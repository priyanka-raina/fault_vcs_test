import sys
import mantle
from tester import Tester
import magma as m
m.set_mantle_target("coreir")

dut = mantle.DefineCounter(4)
print(dut)
m.compile('build/' + dut.name, dut, output="coreir-verilog")
t = Tester(dut, sys.stdin.readlines())
t.compile_and_run(directory="build", target="verilator", flags=["-Wno-fatal", '--trace'])
