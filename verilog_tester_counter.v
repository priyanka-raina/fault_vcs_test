module verilog_tester ();

  reg CLK;
  wire COUT;
  wire [3:0] O;

  Counter4_COUT dut (
    .CLK(CLK),
    .COUT(COUT),
    .O(O)
  );

  initial begin
    CLK = 1'b0;
    // Arbitrarily taking clock period of 10
    #5 CLK = ~CLK; // 1
    $display("%t O = %h", $time, O);
    $display("%t COUT = %h", $time, COUT);
    assert(O == 4'b0000);
    assert(COUT == 1'b0);

    #5 CLK = ~CLK; // 0
    #5 CLK = ~CLK; // 1
    $display("%t O = %h", $time, O);
    $display("%t COUT = %h", $time, COUT);
    assert(O == 4'b0001);
    assert(COUT == 1'b0);

    #5 CLK = ~CLK; // 0
    #5 CLK = ~CLK; // 1
    $display("%t O = %h", $time, O);
    $display("%t COUT = %h", $time, COUT);
    assert(O == 4'b0010);
    assert(COUT == 1'b0);

    #5 CLK = ~CLK; // 0
    #5 CLK = ~CLK; // 1
    $display("%t O = %h", $time, O);
    $display("%t COUT = %h", $time, COUT);
    assert(O == 4'b0011);
    assert(COUT == 1'b0);

    #5 CLK = ~CLK; // 0
    #5 CLK = ~CLK; // 1
    $display("%t O = %h", $time, O);
    $display("%t COUT = %h", $time, COUT);
    assert(O == 4'b0100);
    assert(COUT == 1'b0);

    #5 CLK = ~CLK; // 0
    #5 CLK = ~CLK; // 1
    $display("%t O = %h", $time, O);
    $display("%t COUT = %h", $time, COUT);
    assert(O == 4'b0101);
    assert(COUT == 1'b0);

    #5 CLK = ~CLK; // 0
    #5 CLK = ~CLK; // 1
    $display("%t O = %h", $time, O);
    $display("%t COUT = %h", $time, COUT);
    assert(O == 4'b0110);
    assert(COUT == 1'b0);
  end
endmodule
