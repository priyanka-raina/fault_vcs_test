module corebit_const #(parameter value=1) (
  output out
);
  assign out = value;

endmodule  // corebit_const

module coreir_add #(parameter width=1) (
  input [width-1:0] in0,
  input [width-1:0] in1,
  output [width-1:0] out
);
  assign out = in0 + in1;

endmodule  // coreir_add

module coreir_reg #(parameter clk_posedge=1, parameter init=1, parameter width=1) (
  input clk,
  input [width-1:0] in,
  output [width-1:0] out
);
  reg [width-1:0] outReg=init;
  wire real_clk;
  assign real_clk = clk_posedge ? clk : ~clk;
  always @(posedge real_clk) begin
    outReg <= in;
  end
  assign out = outReg;

endmodule  // coreir_reg

module coreir_const #(parameter value=1, parameter width=1) (
  output [width-1:0] out
);
  assign out = value;

endmodule  // coreir_const

module Add4_cout (
  output  COUT,
  input [3:0] I0,
  input [3:0] I1,
  output [3:0] O
);


  wire  bit_const_0_None__out;
  corebit_const #(.value(0)) bit_const_0_None(
    .out(bit_const_0_None__out)
  );

  // Instancing generated Module: coreir.add(width:5)
  wire [4:0] inst0__in0;
  wire [4:0] inst0__in1;
  wire [4:0] inst0__out;
  coreir_add #(.width(5)) inst0(
    .in0(inst0__in0),
    .in1(inst0__in1),
    .out(inst0__out)
  );

  assign inst0__in0[4] = bit_const_0_None__out;

  assign inst0__in1[4] = bit_const_0_None__out;

  assign inst0__in0[0] = I0[0];

  assign inst0__in0[1] = I0[1];

  assign inst0__in0[2] = I0[2];

  assign inst0__in0[3] = I0[3];

  assign inst0__in1[0] = I1[0];

  assign inst0__in1[1] = I1[1];

  assign inst0__in1[2] = I1[2];

  assign inst0__in1[3] = I1[3];

  assign O[0] = inst0__out[0];

  assign O[1] = inst0__out[1];

  assign O[2] = inst0__out[2];

  assign O[3] = inst0__out[3];

  assign COUT = inst0__out[4];


endmodule  // Add4_cout

module Counter4_COUT (
  input  CLK,
  output  COUT,
  output [3:0] O
);


  // Instancing generated Module: coreir.const(width:4)
  wire [3:0] const_1_4__out;
  coreir_const #(.value(4'h1),.width(4)) const_1_4(
    .out(const_1_4__out)
  );

  wire  inst0__COUT;
  wire [3:0] inst0__I0;
  wire [3:0] inst0__I1;
  wire [3:0] inst0__O;
  Add4_cout inst0(
    .COUT(inst0__COUT),
    .I0(inst0__I0),
    .I1(inst0__I1),
    .O(inst0__O)
  );

  // Instancing generated Module: coreir.reg(width:4)
  wire  inst1__clk;
  wire [3:0] inst1__in;
  wire [3:0] inst1__out;
  coreir_reg #(.clk_posedge(1),.init(4'h0),.width(4)) inst1(
    .clk(inst1__clk),
    .in(inst1__in),
    .out(inst1__out)
  );

  assign inst0__I1[3:0] = const_1_4__out[3:0];

  assign COUT = inst0__COUT;

  assign inst0__I0[3:0] = inst1__out[3:0];

  assign inst1__in[3:0] = inst0__O[3:0];

  assign inst1__clk = CLK;

  assign O[3:0] = inst1__out[3:0];


endmodule  // Counter4_COUT

