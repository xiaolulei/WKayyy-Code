import base64
encodedflag = "x2dtJEOmyjacxDemx2eczT5cVS9fVUGvWTuZWjuexjRqy24rV29q"
_list = list("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/")
flag = ""
for i in encodedflag:
    if (ord(i) <= ord('W') and ord(i) >= ord('A')) or (ord(i) <= ord('w') and ord(i) >= ord('a')):
        flag += chr(ord(i) + 3)
    elif i == 'X':
        flag += 'C'
    elif i == 'Y':
        flag += 'B'
    elif i == 'Z':
        flag += 'A'
    elif i == 'x':
        flag += 'c'
    elif i == 'y':
        flag += 'b'
    elif i == 'z':
        flag += 'a'
    else:
        flag += i


print(base64.b64decode(flag).decode())
