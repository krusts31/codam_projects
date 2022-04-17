import sys

if (len(sys.argv) == 2):
	x = sys.argv[1]
	if not (x.isdigit()):
		print("ERROR")
	else:
		x = int(sys.argv[1])
		if (x == 0):
			print("I`m Zero.")
		elif ((x % 2) == 0):
			print("I`m Even.")
		else:
			print("I`m Odd.")
else:
	print("ERROR")
