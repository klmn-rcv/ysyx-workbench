module LFSR #(
    parameter [7:0] SEED = 8'h1
) (
    input wire clk,
    input wire rst,
    input wire step,
    output reg [7:0] out
);

    always @(posedge clk) begin
        if (rst) begin
            out <= SEED;
        end
        else if (step) begin
            out <= {out[6:0], out[7] ^ out[5] ^ out[4] ^ out[3]};
        end
    end

endmodule
