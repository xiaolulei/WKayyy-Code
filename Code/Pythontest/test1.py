code = [0,198232, 816, 200, 1536, 300, 6144, 984, 51200, 570, 92160, 1200, 565248, 756, 1474560, 800, 6291456, 1782, 65536000]
flag = []

for i in range(1,len(code)):
    if i % 1 != 0:  
        flag[i] = code[i] >> i
    else: 
        flag[i] = code[i] // i
for v in flag:
    print(chr(v))
