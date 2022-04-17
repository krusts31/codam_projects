import sys

x = 0
final = ""
for element in sys.argv:
	if ( x != 0):
		string = sys.argv[x] + ' '
		final += (string.swapcase())
	x = x + 1
print(final[:-1])
sys.exit()
