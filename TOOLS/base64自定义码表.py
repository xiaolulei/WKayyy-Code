import base64
new = "gJ1BRjQie/FIWhEslq7GxbnL26M4+HXUtcpmVTKaydOP38of5v90ZSwrkYzCAuND"
old = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
encoded = "GQTZlSqQXZ/ghxxwhju3hbuZ4wufWjujWrhYe7Rce7ju"
mapper = str.maketrans(new,old)
tmp = encoded.translate(mapper)
flag = base64.b64decode(tmp)

print(flag)