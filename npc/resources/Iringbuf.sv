module Iringbuf (
  input wire clk, 
  input wire rst,
  input wire [31:0] pc,
  input wire [31:0] inst,
  input wire before_ifetch,
  input wire after_ifetch,
  input wire flush_after_ifetch
);
  import "DPI-C" function void iringbuf_before_ifetch(input int unsigned pc);
  import "DPI-C" function void iringbuf_after_ifetch(input int unsigned pc, input int unsigned inst);
  import "DPI-C" function void iringbuf_flush_after_ifetch(input int unsigned pc);

  always @(posedge clk) begin
    if (rst) begin
      // do nothing
    end
    else begin
      if (before_ifetch) begin
        iringbuf_before_ifetch(pc);
      end
      if(after_ifetch) begin
        iringbuf_after_ifetch(pc, inst);
      end
      if(flush_after_ifetch) begin
        iringbuf_flush_after_ifetch(pc);  // 传入pc只是为了assert检查
      end
    end
  end
endmodule
