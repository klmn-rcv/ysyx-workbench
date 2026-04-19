typedef enum logic [0:0] {
    JAL  = 1'd0,
    JALR = 1'd1
} inst_type_e;

module Ftrace(
  input wire clk, 
  input wire rst,
  input wire [31:0] pc,
  input wire [31:0] target_pc,
  input wire [4:0] rd,
  input wire [4:0] rs1,
  input wire [31:0] imm,
  input wire is_jal,
  input wire is_jalr
);
  import "DPI-C" function void ftrace(input int unsigned pc, input int unsigned target_pc, input byte unsigned inst_type, input int rd, input int rs1, input int imm);

  always @(posedge clk) begin
    if (rst) begin
      // do nothing
    end
    else begin
      if (is_jal) begin
        ftrace(pc, target_pc, JAL, rd, 0, imm);
      end
      if(is_jalr) begin
        ftrace(pc, target_pc, JALR, rd, rs1, imm);
      end
    end
  end

endmodule
