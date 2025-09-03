flag=''
str = "ylqq]aycqyp{"
for i in range(len(str)):
    a=ord(str[i])
    if (a<94 or a>96) and (a<62 or a>64):
        a+=2
        flag+=chr(a)
    else:
        a-=24
        flag+=chr(a)
print('NSSCTF'+flag)