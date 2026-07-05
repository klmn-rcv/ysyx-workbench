typedef enum logic [1:0] {
    MEM_READ_INST  = 2'd0,
    MEM_READ_DATA  = 2'd1,
    MEM_READ_DEBUG = 2'd2
} mem_read_e;

module Mem(
    input wire clk,
    input wire rst,

    output wire axi_awready,
    input wire axi_awvalid,
    input wire [31:0] axi_awaddr,
    input wire [3:0] axi_awid,
    input wire [7:0] axi_awlen,
    input wire [2:0] axi_awsize,
    input wire [1:0] axi_awburst,

    output wire axi_wready,
    input wire axi_wvalid,
    input wire [31:0] axi_wdata,
    input wire [3:0] axi_wstrb,
    input wire axi_wlast,

    input wire axi_bready,
    output reg axi_bvalid,
    output reg [1:0] axi_bresp,
    output reg [3:0] axi_bid,

    output wire axi_arready,
    input wire axi_arvalid,
    input wire [31:0] axi_araddr,
    input wire [3:0] axi_arid,
    input wire [7:0] axi_arlen,
    input wire [2:0] axi_arsize,
    input wire [1:0] axi_arburst,

    input wire axi_rready,
    output reg axi_rvalid,
    output reg [31:0] axi_rdata,
    output reg [1:0] axi_rresp,
    output reg [3:0] axi_rid,
    output reg axi_rlast
);
    import "DPI-C" function int pmem_read(input int unsigned raddr, input byte unsigned read_type);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int wdata, input byte unsigned wmask);

    localparam [1:0] AXI_RESP_OKAY = 2'd0;

    reg aw_seen;
    reg w_seen;
    reg [31:0] awaddr_latched;
    reg [3:0] awid_latched;
    reg [31:0] wdata_latched;
    reg [3:0] wstrb_latched;

    wire ar_fire = axi_arvalid && axi_arready;
    wire r_fire = axi_rvalid && axi_rready;
    wire aw_fire = axi_awvalid && axi_awready;
    wire w_fire = axi_wvalid && axi_wready;
    wire b_fire = axi_bvalid && axi_bready;

    wire write_active = aw_seen || w_seen || axi_awvalid || axi_wvalid || axi_bvalid;
    assign axi_arready = !rst && !axi_rvalid && !write_active;
    assign axi_awready = !rst && !axi_bvalid && !aw_seen;
    assign axi_wready = !rst && !axi_bvalid && !w_seen;

    wire aw_seen_next = aw_seen || aw_fire;
    wire w_seen_next = w_seen || w_fire;
    wire write_req_complete = aw_seen_next && w_seen_next && !axi_bvalid;
    wire [31:0] write_addr = aw_fire ? axi_awaddr : awaddr_latched;
    wire [3:0] write_id = aw_fire ? axi_awid : awid_latched;
    wire [31:0] write_data = w_fire ? axi_wdata : wdata_latched;
    wire [3:0] write_strb = w_fire ? axi_wstrb : wstrb_latched;
    wire [7:0] read_type = (axi_arid == 4'd0) ? {6'd0, MEM_READ_INST} : {6'd0, MEM_READ_DATA};

    always @(posedge clk) begin
        if (rst) begin
            axi_rvalid <= 1'b0;
            axi_rdata <= 32'd0;
            axi_rresp <= AXI_RESP_OKAY;
            axi_rid <= 4'd0;
            axi_rlast <= 1'b0;
        end
        else begin
            if (ar_fire) begin
                assert(axi_arlen == 8'd0);
                axi_rdata <= pmem_read(axi_araddr, read_type);
                axi_rresp <= AXI_RESP_OKAY;
                axi_rid <= axi_arid;
                axi_rlast <= 1'b1;
                axi_rvalid <= 1'b1;
            end
            else if (r_fire) begin
                axi_rvalid <= 1'b0;
                axi_rlast <= 1'b0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            aw_seen <= 1'b0;
            w_seen <= 1'b0;
            awaddr_latched <= 32'd0;
            awid_latched <= 4'd0;
            wdata_latched <= 32'd0;
            wstrb_latched <= 4'd0;
            axi_bvalid <= 1'b0;
            axi_bresp <= AXI_RESP_OKAY;
            axi_bid <= 4'd0;
        end
        else begin
            if (b_fire) begin
                axi_bvalid <= 1'b0;
            end

            if (aw_fire) begin
                assert(axi_awlen == 8'd0);
                awaddr_latched <= axi_awaddr;
                awid_latched <= axi_awid;
                aw_seen <= 1'b1;
            end

            if (w_fire) begin
                assert(axi_wlast);
                wdata_latched <= axi_wdata;
                wstrb_latched <= axi_wstrb;
                w_seen <= 1'b1;
            end

            if (write_req_complete) begin
                pmem_write(write_addr, write_data, write_strb);
                axi_bresp <= AXI_RESP_OKAY;
                axi_bid <= write_id;
                axi_bvalid <= 1'b1;
                aw_seen <= 1'b0;
                w_seen <= 1'b0;
            end
        end
    end
endmodule
