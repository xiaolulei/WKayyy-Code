import base64
y1=[0x23,0x61,0x3e,0x69,0x54,0x41,0x18,0x4d,0x6e,0x3b,0x65,0x53,0x30,0x79,0x45,0x5b]
y2=[0x71,0x04,0x61,0x58,0x27,0x1e,0x4b,0x22,0x5e,0x64,0x03,0x26,0x5e,0x17,0x3c,0x7a]
flag=""
for i in range(0,len(y1)):
    flag+=chr(y1[i]^y2[i])
a=[0x3d,0x23,0x40]
for i in range(len(a)):
    flag+=chr(a[i])
a="YTFzMF9wV24="
print(a.encode())
flag+=base64.b64decode(a.encode()).decode()
print(flag)
