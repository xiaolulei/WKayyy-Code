flag="{hacking_for_fun}"
for i in range(len(flag)):
	if((ord(flag[i])==105) or (ord(flag[i])==114)):
		flag=flag.replace(flag[i],chr(49))
print(flag)