import sys
import os
import csv
import data as my_data

def not_nuermical(key):
	if (key != 'Hogwarts House' and key != 'First Name' and key != 'Last Name' and key != 'Best Hand' and key != 'Birthday'):
		return 1
	else:
		return 0

def is_2_args():
	if (2 != len(sys.argv)):
		print("Error\nPass only a 1 .csv file as argument")
		print("Example: python3 descrive.py example.csv")
		quit()

def is_csv(test_input):
	if (test_input[-1] != 'v' or test_input[-2] != 's' or test_input[-3] != 'c' and test_input[-4] != '.'):
		print("Error\nFile extension must be .csv")
		quit()

def make_float(num):
	num = num.replace(' ','').replace(',','.').replace("−", "-")
	return float(num)

def chech_str_to_float(string):
	str_len = 0
	for char in string:
		if (char == '-' and str_len == 0):
			pass
		if (not char.isdigit()):
			return 0
		if (str_len > 0):
			if (char == '-'):
				return 0
		str_len = str_len + 1
	return 1

def Check_input(name):
	if (name is not None):
		is_2_args()
		test_input = str(name)
		is_csv(test_input)
		print("Accepted file name: " + test_input)
		cwd = os.getcwd() #get workig dir 
		file_to_read = cwd + "/" + test_input
		print("Accepted file path: " + file_to_read)
	else:
		is_2_args()
		test_input = str(sys.argv[1])
		is_csv(test_input)
		print("Accepted file name: " + test_input)
		cwd = os.getcwd() #get workig dir 
		file_to_read = cwd + "/" + test_input
		print("Accepted file path: " + file_to_read)
	return file_to_read

def open_file(name):
	with open(Check_input(name)) as csvDataFile:
		first_row = 0
		key_cnt = 0
		index = 0
		i = 0
		csvReader = csv.reader(csvDataFile)
		sample = {} #empty dataset
		for row in csvReader: #for every row in .csv
			if (first_row == 0): #init the first row of values
				for word in row:
					sample[word] = []
					key_cnt = key_cnt + 1
				first_row = 1
			else: #init test rest of the values
				some_list = list(sample)
				for column in row:
					key = some_list[i]
					try:
						if (column == ""):
							pass
						else:
							sample[key].insert(index, float(make_float(column)))
					except:
						sample[key].insert(index, str(column))
						pass
					i = i + 1
					if (i == key_cnt):
						i = 0
				index = index + 1
		return sample

def print_dict(test, name):
	column = ""
	count = ""
	mean = ""
	std = ""
	dict_min = ""
	dict_25 = ""
	dict_50 = ""
	dict_75 = ""
	dict_max = ""
	for key in test.count:
		if (not_nuermical(key)):
			pading = len(str(key)) + 5 #padding size of key + 5
			column = column + "{:>{pading}}".format(str(key), pading=pading)
			if (test.count[key] is not None):
				count = count + "{:>{pading}.2f}".format(float(test.count[key]), pading=pading)
			if (test.mean[key] is not None):
				mean = mean + "{:>{pading}.2f}".format(float(test.mean[key]), pading=pading)
			if (test.std[key] is not None):
				std = std + "{:>{pading}.2f}".format(float(test.std[key]), pading=pading)
			if (test.min[key] is not None):
				dict_min = dict_min + "{:>{pading}.2f}".format(float(test.min[key]), pading=pading)
			if (test.dict_25[key] is not None):
				dict_25 = dict_25 + "{:>{pading}.2f}".format(float(test.dict_25[key]), pading=pading)
			if (test.dict_50[key] is not None):
				dict_50 = dict_50 + "{:>{pading}.2f}".format(float(test.dict_50[key]), pading=pading)
			if (test.dict_75[key] is not None):
				dict_75 = dict_75 + "{:>{pading}.2f}".format(float(test.dict_75[key]), pading=pading)
			if (test.max[key] is not None):
				dict_max = dict_max + "{:>{pading}.2f}".format(float(test.max[key]), pading=pading)
		string = "column	" + column + "\n" + "count	" + count + "\n" + "mean	" + mean + "\n" + "std	" + std + "\n" + "min	" + dict_min + "\n" + "25%	" +  dict_25 + "\n" + "50%	" + dict_50 + "\n" + "75%	" + dict_75 + "\n" + "max	"  + dict_max
	if (name == "stdout"):
		print(string)	
	else:
		f = open(name, "w")
		f.write(string)


sample = open_file(None) #converts csv to py dict
data = my_data.data(sample) #runs anylasis on data
if (sys.argv[0] == "describe.py"):
	print_dict(data, "stdout")
