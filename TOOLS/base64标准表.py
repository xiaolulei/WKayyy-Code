import base64
Destination="e3nifIH9b_C@n@dH"
flag=""
for i in range(len(Destination)):
    flag+=chr(ord(Destination[i])-i)
print(base64.b64decode(flag))
