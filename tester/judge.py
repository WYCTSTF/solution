from colorama import Fore,init
init(autoreset=True)
import os

std = "c++17"
a = ["make","a","force"]
for i in a :  os.system(f"g++ {i}.cpp -o {i} -std={std} -O2")
for i in range(1,10000) : 
	print("Running on " + Fore.BLUE + f"Test {i}" + Fore.RESET + "......", end="")
	os.system(f"./{a[0]} > in")
	os.system(f"./{a[1]} < in > out")
	os.system(f"./{a[2]} < in > ans")
	if(os.system("diff ans out > /dev/null")) :
		print(Fore.RED + "WA")
		break
	else : print(Fore.GREEN + "AC")