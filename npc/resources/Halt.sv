module Halt(
    input wire [31:0] exit_code,
    input wire [31:0] exit_pc,
    input wire halt_valid
);
    import "DPI-C" function void sim_halt(input int exit_code, input int unsigned exit_pc);
    
    always @(halt_valid) begin
        if(halt_valid) begin
            sim_halt(exit_code, exit_pc);
        end
    end
endmodule
