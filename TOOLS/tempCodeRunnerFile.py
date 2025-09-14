import base64
code = "gJ1BRjQie/FIWhEslq7GxbnL26M4+HXUtcpmVTKaydOP38of5v90ZSwrkYzCAuND"
flag = "GQTZlSqQXZ/ghxxwhju3hbuZ4wufWjujWrhYe7Rce7ju"
coder = str.maketrans(code, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/")
print(flag.translate(coder))
print(base64.b64decode(flag.translate(coder)))