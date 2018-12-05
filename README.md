To run simulation with verilator
```
python counter.py | python tester_counter.py
```

To run simulation with vcs
```
vcs -sverilog -full64 +v2k -timescale=1ns/1ns verilog_tester_counter.v ./build/Counter4_COUT.v
./simv
```
