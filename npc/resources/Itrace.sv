module Itrace (
    input wire clk,
    input wire rst,
    input wire valid,
    input wire [31:0] pc,
    input wire [31:0] inst,
    input wire [31:0] dnpc
);
`ifndef SYNTHESIS
    import "DPI-C" function void itrace(input int unsigned pc, input int unsigned inst, input int unsigned dnpc);

    always @(posedge clk) begin
        if(rst) begin
            // do nothing
        end 
        else if(valid) begin
            itrace(pc, inst, dnpc);
        end
    end
`endif
    
endmodule
