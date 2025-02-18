from z3 import *

a2,a3,a4 = BitVecs('a2 a3 a4',64)
s = Solver()
s.add(a2 - a3 == 2225223423)
s.add(a3 + a4 == 4201428739)
s.add(a2 - a4 == 1121399208)
if s.check() == sat:
    m = s.model()
    for i in m:
        print("%s = %ld" % (i, m[i].as_long()))
print("a0 = 0xDF48EF7E")
print("a1 = 550153460")
print("a5 = 0x84F30420")