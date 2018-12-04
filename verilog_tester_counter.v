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
  end

  task runtest;
    begin
      // Arbitrarily taking clock period of 10
      #5 CLK = ~CLK; // 1
      assert(O == 4'b0000);
      assert(COUT == 1'b0);
      #5 CLK = ~CLK; // 0
      #5 CLK = ~CLK; // 1
      assert(O == 4'b0001);
      assert(COUT == 1'b0);
      #5 CLK = ~CLK; // 0
      #5 CLK = ~CLK; // 1
      assert(O == 4'b0001);
      assert(COUT == 1'b0);
    end
  endtask
endmodule
