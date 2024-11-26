v4 = [42,70,39,34,78,44,34,40,73,63,43,64]
code = "~}|{zyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)(" + chr(0x27) + '&%$# !"'
flag=""
for i in v4:
    for j in range(1,len(code)):
        if i == ord(code[j]):
            flag+=chr(j+1)
print (f"{flag}")
