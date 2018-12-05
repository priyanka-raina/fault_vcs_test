#include "VCounter4_COUT.h"
#include "verilated.h"
#include <iostream>
#include <verilated_vcd_c.h>
#include <sys/types.h>
#include <sys/stat.h>

// Based on https://www.veripool.org/projects/verilator/wiki/Manual-verilator#CONNECTING-TO-C
vluint64_t main_time = 0;       // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  You can also use a double, if you wish.

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

#if VM_TRACE
VerilatedVcdC* tracer;
#endif

void my_assert(
    unsigned int got,
    unsigned int expected,
    int i,
    const char* port) {
  if (got != expected) {
    std::cerr << std::endl;  // end the current line
    std::cerr << "Got      : 0x" << std::hex << got << std::endl;
    std::cerr << "Expected : 0x" << std::hex << expected << std::endl;
    std::cerr << "i        : " << std::dec << i << std::endl;
    std::cerr << "Port     : " << port << std::endl;
#if VM_TRACE
    tracer->close();
#endif
    exit(1);
  }
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  VCounter4_COUT* top = new VCounter4_COUT;

#if VM_TRACE
  Verilated::traceEverOn(true);
  tracer = new VerilatedVcdC;
  top->trace(tracer, 99);
  mkdir("logs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  tracer->open("logs/Counter4_COUT.vcd");
#endif

  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 0, 2, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 4, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 1, 11, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 13, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 2, 20, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 22, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 3, 29, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 31, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 4, 38, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 40, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 5, 47, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 49, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 6, 56, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 58, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 7, 65, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 67, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 8, 74, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 76, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 9, 83, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 85, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 10, 92, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 94, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 11, 101, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 103, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 12, 110, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 112, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 13, 119, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 121, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 14, 128, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 0, 130, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  printf("Counter4_COUT.O = %x\n", top->O);
  my_assert(top->O, 15, 137, "O");
  printf("Counter4_COUT.COUT = %x\n", top->COUT);
  my_assert(top->COUT, 1, 139, "COUT");
  printf("Counter4_COUT.CLK = %x\n", top->CLK);
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;


#if VM_TRACE
  tracer->close();
#endif
}
