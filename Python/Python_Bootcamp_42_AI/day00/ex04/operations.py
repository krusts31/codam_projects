import sys

def op(arg1, arg2):
	if (len(sys.argv) != 3):
		raise Exception("InputError: only numbers\n\n")
	if (arg1.isdigit() and arg2.isdigit()):
		arg1 = int(arg1)
		arg2 = int(arg2)
	else:
		raise Exception("InputError: only numbers\n\n")
	print("Sum:		", arg1 + arg2)
	print("Difference:	", arg1 - arg2)
	print("Product:	", arg1 * arg2)
	try:
		print("Quotient:	", arg1 / arg2)
	except Exception as e:
		print ("Quotient:	ERROR (", e, ")")
	try:
		print("Remainder:	", arg1 % arg2)
	except Exception as e:
		print ("Remainder:	ERROR (", e, ")")

try:
	op(sys.argv[1], sys.argv[2])
except IndexError:
	print("Usage: python3 operations.py <number1> <number2> Example:\n\tpython3 operations.py 10 3")
except Exception as e:
	print(e, "Usage: python3 operations.py <number1> <number2> Example:\n\tpython3 operations.py 10 3")

