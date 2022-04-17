#TASK	displays the sums of upper characters, lower characters, punctuation characters and spaces in a given text.
import sys

def ft_is_upper(c):
	if c >= 'A' and c <= 'Z':
		return True
	return False

def ft_is_lower(c):
	if c >= 'a' and c <= 'z':
		return True
	return False

def ft_is_punctuation(c):
	if c == '!':
		return True
	elif c == '.':
		return True
	elif c == ',':
		return True
	elif c == ';':
		return True
	elif c == ':':
		return True
	elif c == '-':
		return True
	elif c == '(':
		return True
	elif c == ')':
		return True
	elif c == '[':
		return True
	elif c == ']':
		return True
	elif c == '?':
		return True
	return False

def text_analyzer(src):
	"""This function counts the number of upper characters, lower characters,
	punctuation (?!.,:;-()[])and spaces in a given text."""
	uppercase_letters = 0
	lowercase_letters = 0
	spaces = 0
	punctuation = 0
	chars = 0
	if not src:
		print("What is the text to analyse?")
		src = sys.stdin.read()
	for char in src:
		if ft_is_upper(char):
			uppercase_letters += 1
		if ft_is_lower(char):
			lowercase_letters += 1
		if char == ' ':
			spaces += 1
		if ft_is_punctuation(char):
			punctuation += 1
		chars += 1
	print("the text contains ", chars, "characters")
	print("- ", uppercase_letters, " upper letters")
	print("- ", lowercase_letters, " lower letters")
	print("- ", punctuation, "punctuation marks")
	print("- ", spaces, " spaces")


text_analyzer("Testing! ")
text_analyzer("")
help(text_analyzer)
