for i in range(16):
    s = "".join(['1' if i & (1 << j) else '0' for j in range(4)])
    s += '1' if i == 15 else '0'
    print(s)

