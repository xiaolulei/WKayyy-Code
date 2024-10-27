s='填写16进制数据'
import binascii
out=open('2.jpg','wb')
out.write(binascii.unhexlify(s))
out.close()
