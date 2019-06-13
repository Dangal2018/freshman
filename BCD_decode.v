```verilog
`timescale 1 ns / 1 ps

module bcd7seg ( Y ,A );

input [3:0] A ;
wire [3:0] A ;

output [6:0] Y ;
wire [6:0] Y ;
assign Y =~Y_r;
reg [6:0] Y_r;

    always @(A  )
    begin
        Y_r = 7'b1111111;
        case (A )
                4'b0000: Y_r = 7'b0111111; // 0
                4'b0001: Y_r = 7'b0000110; // 1
                4'b0010: Y_r = 7'b1011011; // 2
                4'b0011: Y_r = 7'b1001111; // 3
                4'b0100: Y_r = 7'b1100110; // 4
                4'b0101: Y_r = 7'b1101101; // 5
                4'b0110: Y_r = 7'b1111101; // 6
                4'b0111: Y_r = 7'b0000111; // 7
                4'b1000: Y_r = 7'b1111111; // 8
                4'b1001: Y_r = 7'b1101111; // 9
                4'b1010: Y_r = 7'b1110111; // A
                4'b1011: Y_r = 7'b1111100; // b
                4'b1100: Y_r = 7'b0111001; // c
                4'b1101: Y_r = 7'b1011110; // d
                4'b1110: Y_r = 7'b1111001; // E
                4'b1111: Y_r = 7'b1110001; // F
                default: Y_r = 7'b0000000;
            endcase
    end
    
endmodule
```
