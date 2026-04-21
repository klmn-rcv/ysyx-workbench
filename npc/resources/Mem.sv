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
    input wire wen,
    input wire [31:0] pc,
    input wire [31:0] raddr,
    input wire [31:0] waddr,
    input wire [31:0] wdata,
    input wire [3:0] wmask,
    output reg inst_resp_valid,
    output reg data_resp_valid,
    output reg [31:0] rinst,
    output reg [31:0] rdata   // 暂时让rdata在当前周期就能返回，不然对于单周期CPU来说太麻烦
);
    import "DPI-C" function int pmem_read(input int unsigned raddr, input byte read_type);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int wdata, input byte unsigned wmask);

    always @(posedge clk) begin
        if(rst) begin
            inst_resp_valid <= 0;
            data_resp_valid <= 0;
            rinst <= 0;
            rdata <= 0;
        end
        else begin
            if(inst_req_valid) begin // 有读指令请求时
                // $write("Mem.sv: inst_req_valid=%b pc=%h\n", inst_req_valid, pc);
                rinst <= pmem_read(pc, MEM_READ_INST); // 读指令时read_type为MEM_READ_INST
            end
            if (data_req_valid) begin // 有读写数据请求时
                // if (wen) begin // 有写请求时
                //     pmem_write(waddr, wdata, wmask);
                // end
                // else begin // 有读请求时
                //     rdata <= pmem_read(raddr, MEM_READ_DATA); // 读数据时read_type为MEM_READ_DATA
                // end
                rdata <= (!wen) ? pmem_read(raddr, MEM_READ_DATA) : 32'b0;
                if (wen) begin
                    pmem_write(waddr, wdata, wmask);
                end
            end
            inst_resp_valid <= inst_req_valid;
            data_resp_valid <= data_req_valid;
        end
    end
endmodule
