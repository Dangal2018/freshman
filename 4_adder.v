```verilog
module _4bAdder (A,B,C3,S,C_1);
  input [3:0] A,B;
  input C_1;
  output [3:0] S;
  output C3;
  wire C0,C1,C2; //模块内部连线声明
//实例引用子模块Adder1b 
  Adder1b  U0(A[0],B[0],C[0],S[0],C_1);
  Adder1b  U1(A[1],B[1],C[1],S[1],C0);
  Adder1b  U2(A[2],B[2],C[2],S[2],C1);
  Adder1b  U3(A[3],B[3],C[3],S[3],C2);
endmodule 
--------------------------------------------------
module Adder1b(A,B,Co,S,Ci);
  input A,B,Ci;
  output S,Co;
  assign {Co,S}=A+B+Ci;
endmodule 
--------------------------------------------------
module _4bAdder (A,B,C3,S,C_1);//父模块
module Adder (A,B,Ci,S,Co);//子模块
Adder1b  U0 (
                         .A(A[0]),
                         .B(B[0]),
                         .Co(C[0]) ,
                         .S(S[0]),
                         .Ci(C_1)
                       );
--------------------------------------------------
```
