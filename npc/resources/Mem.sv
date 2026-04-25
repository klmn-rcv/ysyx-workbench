typedef enum logic [1:0] {
    MEM_READ_INST  = 2'd0,
    MEM_READ_DATA  = 2'd1,
    MEM_READ_DEBUG = 2'd2
} mem_read_e;

module Mem(
    input wire clk,
    input wire rst,
    input wire is_inst,  // 只用于DPI-C函数，用于mtrace，不用于控制逻辑

    // AR
    input wire [31:0] axi_ar_araddr,
    input wire axi_ar_arvalid,
    output wire axi_ar_arready,

    // R
    output reg [31:0] axi_r_rdata,
    output reg [1:0] axi_r_rresp,
    output reg axi_r_rvalid,
    input wire axi_r_rready,

    // AW
    input wire [31:0] axi_aw_awaddr,
    input wire axi_aw_awvalid,
    output wire axi_aw_awready,

    // W
    input wire [31:0] axi_w_wdata,
    input wire [3:0] axi_w_wstrb,
    input wire axi_w_wvalid,
    output wire axi_w_wready,

    // B
    output reg [1:0] axi_b_bresp,
    output reg axi_b_bvalid,
    input wire axi_b_bready
);
    import "DPI-C" function int pmem_read(input int unsigned raddr, input byte read_type);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int wdata, input byte unsigned wmask);

    wire [7:0] read_type = is_inst ? {6'd0, MEM_READ_INST} : {6'd0, MEM_READ_DATA}; // 只用于传给DPI-C函数，用于mtrace

    localparam R_IDLE = 2'd0, R_WAIT = 2'd1, R_RESP = 2'd2;
    localparam W_IDLE = 2'd0, W_WAIT = 2'd1, W_RESP = 2'd2;

    reg [1:0] r_current_state, r_next_state;
    reg [1:0] w_current_state, w_next_state;

    wire [7:0] r_lfsr_rand;
    wire [7:0] w_lfsr_rand;
    wire [3:0] r_latency = {1'b0, r_lfsr_rand[2:0]} + 4'd1;
    wire [3:0] w_latency = {1'b0, w_lfsr_rand[2:0]} + 4'd1;
    reg [3:0] r_latency_cnt;
    reg [3:0] w_latency_cnt;

    reg [31:0] raddr_latched;
    reg [31:0] awaddr_latched;
    reg [31:0] wdata_latched;
    reg [3:0]  wstrb_latched;

    reg aw_fire_after;
    reg w_fire_after;
    wire ar_fire = axi_ar_arvalid && axi_ar_arready;
    wire r_fire  = axi_r_rvalid   && axi_r_rready;
    wire aw_fire = axi_aw_awvalid && axi_aw_awready;
    wire w_fire  = axi_w_wvalid   && axi_w_wready;
    wire b_fire  = axi_b_bvalid   && axi_b_bready;

    wire aw_fire_preserved = aw_fire || aw_fire_after;
    wire w_fire_preserved  = w_fire || w_fire_after;
    wire w_req_complete = aw_fire_preserved && w_fire_preserved;
    wire write_req_complete_pulse = (w_current_state == W_IDLE) && w_req_complete;

    reg writing;
    wire write_begin = (w_current_state == W_IDLE) && (aw_fire || w_fire);
    wire write_finish = ((w_current_state == W_IDLE) && w_req_complete && (w_latency == 4'd1)) ||
                        ((w_current_state == W_WAIT) && (w_latency_cnt == 4'd1));

    always @(posedge clk) begin
        if(rst) begin
            writing <= 1'b0;
        end
        else begin
            if(write_finish) writing <= 1'b0;
            else if(write_begin) writing <= 1'b1;
        end
    end

    // RAW阻塞：当内存有未完成的写操作时，禁止内存接收读请求
    assign axi_ar_arready = (r_current_state == R_IDLE) && !writing && !write_begin;
    assign axi_aw_awready = (w_current_state == W_IDLE) && !aw_fire_after;
    assign axi_w_wready   = (w_current_state == W_IDLE) && !w_fire_after;

    LFSR #(.SEED(8'h1)) r_lfsr_u (
        .clk(clk),
        .rst(rst),
        .step(ar_fire),
        .out(r_lfsr_rand)
    );

    LFSR #(.SEED(8'h2)) w_lfsr_u (
        .clk(clk),
        .rst(rst),
        .step(write_req_complete_pulse),
        .out(w_lfsr_rand)
    );

    always @(*) begin
        case(r_current_state)
            R_IDLE: begin
                if(ar_fire) begin
                    if(r_latency == 4'd1) r_next_state = R_RESP;
                    else r_next_state = R_WAIT;
                end
                else r_next_state = R_IDLE;
            end
            R_WAIT: begin
                if(r_latency_cnt == 4'd1) r_next_state = R_RESP;
                else r_next_state = R_WAIT;
            end
            R_RESP: begin
                if(r_fire) r_next_state = R_IDLE;
                else r_next_state = R_RESP;
            end
            default: r_next_state = R_IDLE;
        endcase
    end

    always @(*) begin
        case(w_current_state)
            W_IDLE: begin
                if(w_req_complete) begin
                    if(w_latency == 4'd1) w_next_state = W_RESP;
                    else w_next_state = W_WAIT;
                end
                else w_next_state = W_IDLE;
            end
            W_WAIT: begin
                if(w_latency_cnt == 4'd1) w_next_state = W_RESP;
                else w_next_state = W_WAIT;
            end
            W_RESP: begin
                if(b_fire) w_next_state = W_IDLE;
                else w_next_state = W_RESP;
            end
            default: w_next_state = W_IDLE;
        endcase
    end

    always @(posedge clk) begin
        if(rst) r_current_state <= R_IDLE;
        else r_current_state <= r_next_state;
    end

    always @(posedge clk) begin
        if(rst) w_current_state <= W_IDLE;
        else w_current_state <= w_next_state;
    end

    always @(posedge clk) begin
        if(rst) begin
            raddr_latched <= 32'd0;
            axi_r_rdata <= 32'd0;
            axi_r_rresp <= 2'd0;
            axi_r_rvalid <= 1'b0;
            r_latency_cnt <= 4'd0;
        end
        else begin
            case(r_current_state)
                R_IDLE: begin
                    if(ar_fire) begin
                        raddr_latched <= axi_ar_araddr;
                        if(r_latency == 4'd1) begin
                            r_latency_cnt <= 4'd0;
                            axi_r_rdata <= pmem_read(axi_ar_araddr, read_type);
                            axi_r_rresp <= 2'd0;
                            axi_r_rvalid <= 1'b1;
                        end
                        else begin
                            r_latency_cnt <= r_latency - 4'd1;
                        end
                    end
                end
                R_WAIT: begin
                    if(r_latency_cnt == 4'd1) begin
                        r_latency_cnt <= 4'd0;
                        axi_r_rdata <= pmem_read(raddr_latched, read_type);
                        axi_r_rresp <= 2'd0;
                        axi_r_rvalid <= 1'b1;
                    end
                    else begin
                        r_latency_cnt <= r_latency_cnt - 4'd1;
                    end
                end
                R_RESP: begin
                    if(r_fire) begin
                        axi_r_rvalid <= 1'b0;
                    end
                end
                default: begin
                end
            endcase
        end
    end

    always @(posedge clk) begin
        if(rst) begin
            aw_fire_after <= 1'b0;
            w_fire_after <= 1'b0;
            awaddr_latched <= 32'd0;
            wdata_latched <= 32'd0;
            wstrb_latched <= 4'd0;
            w_latency_cnt <= 4'd0;
            axi_b_bresp <= 2'd0;
            axi_b_bvalid <= 1'b0;
        end
        else begin
            case(w_current_state)
                W_IDLE: begin
                    if(aw_fire) begin
                        awaddr_latched <= axi_aw_awaddr;
                        aw_fire_after <= 1'b1;
                    end
                    if(w_fire) begin
                        wdata_latched <= axi_w_wdata;
                        wstrb_latched <= axi_w_wstrb;
                        w_fire_after <= 1'b1;
                    end

                    if(w_req_complete) begin
                        if(w_latency == 4'd1) begin
                            w_latency_cnt <= 4'd0;
                            pmem_write(
                                aw_fire ? axi_aw_awaddr : awaddr_latched,
                                w_fire  ? axi_w_wdata  : wdata_latched,
                                w_fire  ? {4'd0, axi_w_wstrb} : {4'd0, wstrb_latched}
                            );
                            axi_b_bresp <= 2'd0;
                            axi_b_bvalid <= 1'b1;
                        end
                        else begin
                            w_latency_cnt <= w_latency - 4'd1;
                        end
                    end
                end
                W_WAIT: begin
                    if(w_latency_cnt == 4'd1) begin
                        w_latency_cnt <= 4'd0;
                        pmem_write(awaddr_latched, wdata_latched, {4'd0, wstrb_latched});
                        axi_b_bresp <= 2'd0;
                        axi_b_bvalid <= 1'b1;
                    end
                    else begin
                        w_latency_cnt <= w_latency_cnt - 4'd1;
                    end
                end
                W_RESP: begin
                    if(b_fire) begin
                        axi_b_bvalid <= 1'b0;
                        aw_fire_after <= 1'b0;
                        w_fire_after <= 1'b0;
                    end
                end
                default: begin
                end
            endcase
        end
    end
endmodule
