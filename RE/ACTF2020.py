import base64
str1 = 'zMXHz3TIgnxLxJhFAdtZn2fFk3lYCrtPC2l9'
str2 = ''
for s in str1:
    s = ord(s)
    if(s>64 and s<91):
        s += 32
    elif(s>90 and s<123):
        s -= 32
    str2 += chr(s)
base64_table='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
dict={}
for i in range(len(base64_table)):
    dict[base64_table[i]] = base64_table[i]
for i in range(6, 15):
        dict[base64_table[i]] , dict[base64_table[i + 10]] = dict[base64_table[i + 10]] , dict[base64_table[i]]
flag=''
for i in range(len(str2)):
    flag+=dict[str2[i]]
flag=base64.b64decode(flag)
print(flag)