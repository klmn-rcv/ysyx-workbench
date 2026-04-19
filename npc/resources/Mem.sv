module Mem(
    input wire clk,
    input wire rst,
    input wire inst_req_valid,
    input wire data_req_valid,
    input wire wen,
    input wire [31:0] pc,
    input wire [31:0] raddr,
    input wire [31:0] waddr,
    input wire [31:0] wdata,
    input wire [3:0] wmask,
    output reg [31:0] rinst,
    output reg [31:0] rdata
);
    localparam BASE_ADDR = 32'h8000_0000;
    localparam MEM_DEPTH = 256;

    reg [31:0] imem [0:MEM_DEPTH - 1];
    reg [31:0] dmem [0:MEM_DEPTH - 1];
    integer i;

    wire [31:0] inst_off  = pc - BASE_ADDR;
    wire [31:0] rdata_off = raddr - BASE_ADDR;
    wire [31:0] wdata_off = waddr - BASE_ADDR;
    wire [7:0] inst_idx  = inst_off[9:2];
    wire [7:0] rdata_idx = rdata_off[9:2];
    wire [7:0] wdata_idx = wdata_off[9:2];

    always @(posedge clk) begin
        if(rst) begin
            rinst <= 0;
            for (i = 0; i < MEM_DEPTH; i = i + 1) begin
                imem[i] <= BASE_ADDR + (i << 2);
                dmem[i] <= BASE_ADDR + (i << 2);
            end
        end
        else begin
            if(inst_req_valid) begin
                rinst <= imem[inst_idx];
            end
            if (data_req_valid && wen) begin
                if (wmask[0]) dmem[wdata_idx][ 7: 0] <= wdata[ 7: 0];
                if (wmask[1]) dmem[wdata_idx][15: 8] <= wdata[15: 8];
                if (wmask[2]) dmem[wdata_idx][23:16] <= wdata[23:16];
                if (wmask[3]) dmem[wdata_idx][31:24] <= wdata[31:24];
            end
        end
    end

    always @(*) begin
        if(data_req_valid && !wen) begin
            rdata = dmem[rdata_idx];
        end
        else begin
            rdata = 0;
        end
    end
endmodule
