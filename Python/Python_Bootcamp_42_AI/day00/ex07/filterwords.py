import sys

error_message = "ERROR"
list_of_words = []
punctuation= '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
clean_string = ""

if (len(sys.argv) == 3 and isinstance(sys.argv[1], str) and sys.argv[2].isdigit()):
	text = str(sys.argv[1])
	for char in text:
		if char not in punctuation:
    			clean_string=clean_string+char
	words = clean_string.split()
	x = 0
	delimiter = int(sys.argv[2])
	for word in words:
		if (len(word) >= delimiter):
			list_of_words.insert(x, word)
			x = x + 1
	if (x >= 1):
		print(list_of_words)
	else:
		print(error_message)
else:
	print(error_message)
