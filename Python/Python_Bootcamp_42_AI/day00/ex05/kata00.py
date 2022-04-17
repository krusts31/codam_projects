from colorama import Fore, Back, Style

t = (123.123213, 222222222222222222222222222222222222, -2)

x = "No numbers given"
try:
	length = len(t)
except TypeError:
	x = "The 1 number is: " + str(t)
	exit(x)
for var in t:
	x = str(length) + " numbers are: " + str(t)
x = x.replace("(", "")
x = x.replace(")", "")
print(Fore.BLUE + "The " + Style.RESET_ALL + x)
