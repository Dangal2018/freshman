module dividers(clk_out ,clk_in ,reset);
output clk_out ;
input clk_in ;
input reset ;
reg [1:0] cnt ;
reg clk_out ;
always@(posedge clk_in or posedge reset)
begin
if(reset)
begin
cnt<=0;
clk_out <= 0;
end
else
begin
if(cnt==24999999)
begin
clk_out <=!clk_out;
cnt<=0;
end
else
cnt<=cnt+1;
end
end
endmodule
