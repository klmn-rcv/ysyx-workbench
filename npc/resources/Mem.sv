typedef enum logic [1:0] {
    MEM_READ_INST  = 2'd0,
    MEM_READ_DATA  = 2'd1,
    MEM_READ_DEBUG = 2'd2
} mem_read_e;

module Mem(
    input wire clk,
    input wire rst,
    input wire inst_req_valid,
    input wire data_req_valid,
    input wire inst_resp_ready,
    input wire data_resp_ready,
    input wire wen,
    input wire [31:0] pc,
    input wire [31:0] raddr,
    input wire [31:0] waddr,
    input wire [31:0] wdata,
    input wire [3:0] wmask,
    output inst_req_ready,
    output data_req_ready,
    output reg inst_resp_valid,
    output reg data_resp_valid,
    output reg [31:0] rinst,
    output reg [31:0] rdata   // 暂时让rdata在当前周期就能返回，不然对于单周期CPU来说太麻烦
);
    import "DPI-C" function int pmem_read(input int unsigned raddr, input byte read_type);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int wdata, input byte unsigned wmask);



    localparam IDLE = 2'd0, WAIT = 2'd1, RESP = 2'd2;

    reg [1:0] inst_current_state, inst_next_state;
    reg [1:0] data_current_state, data_next_state;

    wire [7:0] inst_rand;
    wire [7:0] data_rand;
    wire [3:0] inst_latency = {1'b0, inst_rand[2:0]} + 4'd1;
    wire [3:0] data_latency = {1'b0, data_rand[2:0]} + 4'd1;
    reg [3:0] inst_latency_cnt;
    reg [3:0] data_latency_cnt;

    reg [31:0] pc_latched;
    reg        wen_latched;
    reg [31:0] raddr_latched;
    reg [31:0] waddr_latched;
    reg [31:0] wdata_latched;
    reg [3:0]  wmask_latched;


    wire inst_req_fire  = inst_req_valid  && inst_req_ready;
    wire data_req_fire  = data_req_valid  && data_req_ready;
    wire inst_resp_fire = inst_resp_valid && inst_resp_ready;
    wire data_resp_fire = data_resp_valid && data_resp_ready;

    assign inst_req_ready = (inst_current_state == IDLE);
    assign data_req_ready = (data_current_state == IDLE);

    LFSR #(.SEED(8'h1)) inst_lfsr_u (
        .clk(clk),
        .rst(rst),
        .step(inst_req_fire),
        .out(inst_rand)
    );

    LFSR #(.SEED(8'h2)) data_lfsr_u (
        .clk(clk),
        .rst(rst),
        .step(data_req_fire),
        .out(data_rand)
    );

    always @(*) begin
        case(inst_current_state)
            IDLE: begin
                if(inst_req_fire) begin
                    if(inst_latency == 4'd1) inst_next_state = RESP;
                    else inst_next_state = WAIT;
                end
                else inst_next_state = IDLE;
            end
            WAIT: begin
                if(inst_latency_cnt == 4'd1) inst_next_state = RESP;
                else inst_next_state = WAIT;
            end
            RESP: begin
                if(inst_resp_fire) inst_next_state = IDLE;
                else inst_next_state = RESP;
            end
            default: inst_next_state = IDLE;
        endcase
    end

    always @(*) begin
        case(data_current_state)
            IDLE: begin
                if(data_req_fire) begin
                    if(data_latency == 4'd1) data_next_state = RESP;
                    else data_next_state = WAIT;
                end
                else data_next_state = IDLE;
            end
            WAIT: begin
                if(data_latency_cnt == 4'd1) data_next_state = RESP;
                else data_next_state = WAIT;
            end
            RESP: begin
                if(data_resp_fire) data_next_state = IDLE;
                else data_next_state = RESP;
            end
            default: data_next_state = IDLE;
        endcase
    end

    always @(posedge clk) begin
        if(rst) inst_current_state <= 2'd0;
        else inst_current_state <= inst_next_state;
    end

    always @(posedge clk) begin
        if(rst) data_current_state <= 2'd0;
        else data_current_state <= data_next_state;
    end


    always @(posedge clk) begin
        if(rst) begin
            pc_latched <= 32'd0;
            rinst <= 32'd0;
            inst_latency_cnt <= 4'd0;
            inst_resp_valid <= 1'b0;
        end
        else begin
            case(inst_current_state)
                IDLE: begin
                    if(inst_req_fire) begin
                        pc_latched <= pc;
                        if(inst_latency == 4'd1) begin
                            inst_latency_cnt <= 4'd0;
                            inst_resp_valid <= 1'b1;
                            rinst <= pmem_read(pc, MEM_READ_INST);
                        end
                        else begin
                            inst_latency_cnt <= inst_latency - 4'd1;
                        end
                    end
                end
                WAIT: begin
                    if (inst_latency_cnt == 4'd1) begin
                        inst_resp_valid <= 1'b1;
                        rinst <= pmem_read(pc_latched, MEM_READ_INST);
                    end
                    else begin
                        inst_latency_cnt <= inst_latency_cnt - 4'd1;
                    end
                end
                RESP: begin
                    if (inst_resp_fire) begin
                        inst_resp_valid <= 1'b0;
                    end
                end
            endcase        
        end
    end

    always @(posedge clk) begin
        if(rst) begin
            wen_latched <= 1'd0;
            raddr_latched <= 32'd0;
            waddr_latched <= 32'd0;
            wdata_latched <= 32'd0;
            wmask_latched <= 4'd0;
            rdata <= 32'd0;
            data_latency_cnt <= 4'd0;
            data_resp_valid <= 1'b0;
        end
        else begin
            case(data_current_state)
                IDLE: begin
                    if(data_req_fire) begin
                        wen_latched <= wen;
                        raddr_latched <= raddr;
                        waddr_latched <= waddr;
                        wdata_latched <= wdata;
                        wmask_latched <= wmask;
                        if(data_latency == 4'd1) begin
                            data_latency_cnt <= 4'd0;
                            data_resp_valid <= 1'b1;
                            if(wen) begin
                                pmem_write(waddr, wdata, wmask);
                            end
                            else begin
                                rdata <= pmem_read(raddr, MEM_READ_DATA);
                            end
                        end
                        else begin
                            data_latency_cnt <= data_latency - 4'd1;
                        end
                    end
                end
                WAIT: begin
                    if (data_latency_cnt == 4'd1) begin
                        data_resp_valid <= 1'b1;
                        if(wen_latched) begin
                            pmem_write(waddr_latched, wdata_latched, wmask_latched);
                        end
                        else begin
                            rdata <= pmem_read(raddr_latched, MEM_READ_DATA);
                        end
                    end
                    else begin
                        data_latency_cnt <= data_latency_cnt - 4'd1;
                    end
                end
                RESP: begin
                    if (data_resp_fire) begin
                        data_resp_valid <= 1'b0;
                    end
                end
            endcase        
        end
    end
endmodule
