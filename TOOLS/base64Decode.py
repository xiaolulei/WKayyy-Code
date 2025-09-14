import base64
Destination="GQTZlSqQXZ/ghxxwhju3hbuZ4wufWjujWrhYe7Rce7ju"
flag=""
for i in range(len(Destination)):
    flag+=chr(ord(Destination[i])-i)
print(base64.b64decode(flag))
