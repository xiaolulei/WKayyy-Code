import gmpy2
import rsa
e=65537 #公钥指数
n=86934482296048119190666062003494800588905656017203025617216654058378322103517 #模数
p=285960468890451637935629440372639283459 #两个大素数
q=304008741604601924494328155975272418463
phin=(p-1)*(q-1) #欧拉系数
d=gmpy2.invert(e,phin) #ed≡1(mod φ(n))    利用invert函数求逆元 
key=rsa.PrivateKey(n, e, int(d), p, q) #用RSA库来创建一个私钥
with open("D:\\flag.txt", "rb+") as f:
    f = f.read()
    print(rsa.decrypt(f, key)) 