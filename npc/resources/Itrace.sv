module ysyx_26050145_Itrace (
    input wire clk,
    input wire rst,
    input wire valid,
    input wire [31:0] pc,
    input wire [31:0] inst,
    input wire [31:0] dnpc,
    input wire need_skip_ref
);
    import "DPI-C" function void itrace(input int unsigned pc, input int unsigned inst, input int unsigned dnpc, input byte need_skip_ref);

    always @(posedge clk) begin
        if(rst) begin
            // do nothing
        end 
        else if(valid) begin
            itrace(pc, inst, dnpc, {7'd0, need_skip_ref});
        end
    end
    
endmodule
