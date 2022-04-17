import sys
import os

file = "dash.wav"
file_2 = "dot.wav"

# Dictionary representing the morse code chart
MORSE_CODE_DICT = { 'A':'.-', 'B':'-...',
	'C':'-.-.', 'D':'-..', 'E':'.',
	'F':'..-.', 'G':'--.', 'H':'....',
	'I':'..', 'J':'.---', 'K':'-.-',
	'L':'.-..', 'M':'--', 'N':'-.',
	'O':'---', 'P':'.--.', 'Q':'--.-',
	'R':'.-.', 'S':'...', 'T':'-',
	'U':'..-', 'V':'...-', 'W':'.--',
	'X':'-..-', 'Y':'-.--', 'Z':'--..',
	'1':'.----', '2':'..---', '3':'...--',
	'4':'....-', '5':'.....', '6':'-....',
	'7':'--...', '8':'---..', '9':'----.',
	'0':'-----', ' ': ' \ '}

def encrypt(message):
	cipher = ''
	for letter in message:
		letter = letter.capitalize()
		if (letter.isalnum() or letter == ' '):
			cipher += MORSE_CODE_DICT[letter] + ' '
		else:
			return ("error")
	return cipher

if (len(sys.argv) >= 2):
	x = 0
	for args in sys.argv:
		if (x == 0):
			x = x + 1
			continue
		else:
			message = encrypt(str(args))
			if (message == 'error'):
				print("ERROR")
				break
			for letter in message:
				if (letter == '.'):
					os.system("afplay -t 0.2 " + file_2)
				if (letter == '-'):
					os.system("afplay -t 0.6 " + file)
			print(message)
			x = x + 1
else:
	print("ERROR")
