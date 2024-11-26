v12='Qsw3sj_lz4_Ujw@l'
flag=''
for i in range(0,16):
    for j in range (32,127):
        sum=j
        if(sum>64 and sum<=90):
            sum=(sum-51)%26+65
        if(sum>96 and sum<=122):
            sum=(sum-79)%26+97
        if(chr(sum)==v12[i]):
            flag+=chr(j)
print(f"{flag}")