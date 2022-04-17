import math
import data as my_data
import numpy as np
import describe

def filter_by_key(sample, heystack, needle, data):
	sub_set = dict.fromkeys(sample)
	sub_set_cpy = sub_set.copy()
	list_index = 0
	x = 0
	all_keys = []
	for key in sub_set_cpy:
		all_keys.insert(list_index, key)
		sub_set[key] = []
		list_index = list_index + 1
	for key in sample:
		index = 0
		i = 0
		for element in sample[key]:
			if (element == needle and key == heystack):
					for hit in all_keys:
						if (data.count[hit] > index):
							if (sample[hit][index] != ""):
								sub_set[hit].insert(i, sample[hit][index])
					i = i + 1
			index = index + 1
	return sub_set

itter = 100000		# min iter till converg
sample_limit = 100 
alpha = 0.160		# for gradient discent
m = []			# columns in a row

def is_member_of_house(house_name, data):
	binary_class = []
	index = 0
	for name in data:
		if (name == house_name):
			binary_class.insert(index, 1)
		else:
			binary_class.insert(index, 0)
		index = index + 1
	return binary_class
			

def sigmoid(z):
	return 1/(1 + math.exp(-z))
# J = (1/m)*sum((-y.*log(h_x))-((1-y).*log(1-h_x)))
def cost(hypothesis, m, bin_clas_for_house):
	neg_bin_clas_for_house = []
	revers_bin_clas_for_house = []
	mul = []
	mul_2 = []
	sub = []
	sum_x = 0 
	x = math.log(1 - hypothesis)#*log(1-h_x)
	a = math.log(hypothesis)#*log(1-h_x)
	for num in bin_clas_for_house:
		neg_bin_clas_for_house.append(num - 1) #-y
	for num in bin_clas_for_house:
		revers_bin_clas_for_house.append(1 - num) #1 -y
	for num in revers_bin_clas_for_house:
		mul.append(num * x) #(1-y)*log(1-h_x)
	for num in neg_bin_clas_for_house:
		mul_2.append(num * a) #-y *log(h_x)
	for i in range(0, len(mul_2)):
		sub.append(mul_2[i] - mul[i])#-y.*log(h_x))-((1-y).*log(1-h_x))
	for num in sub:
		sum_x = num + sum_x #sum((-y.*log(h_x))-((1-y).*log(1-h_x)))
	error = sum_x / m
	return error
	
#grad = (1/m) * (X'*(h_x-y))
def grad(m, h_x, data, bin_clas_for_house):
	neg_bin_clas_for_house = []
	sub = []
	div = []
#	print(data)
	transpoe_date = list(map(list, zip(data)))
#	print(transpoe_date)
	for num in bin_clas_for_house:
		neg_bin_clas_for_house.append(num - 1)		#-y
	for num in neg_bin_clas_for_house:
		sub.append(h_x - num) 				#h_x - y
	for i in range(0, len(transpoe_date)):
		sub.append(transpoe_date[i] * sub[i])		#(X'*(h_x-y))
	for num in sub:
		div.append(sub / m)
	return div

#def vector(data)
#	for key in data.sorted_dict:
#		if (describe.not_nuermical(key)):
#			data.sorted_dict
#			np.array(data.sorted_dict)

def logistic_regresion(subset, data, house_name):
	bin_clas_for_house = is_member_of_house(house_name, data.data["Hogwarts House"])
	#the_whole_numeric_data_vector = vector(data)
	for key in subset.sorted_dict:
		if (describe.not_nuermical(key)):
			row_in_column = subset.count[key]
			theta = []
			limit = sample_limit
			while (row_in_column > -1):
				theta.insert(row_in_column, 0)
				row_in_column = row_in_column - 1
			total_amount_of_members_in_house = data.sorted_dict[key]
			hypothesis = sigmoid(row_in_column)
			if (hypothesis == 1):
				hypothesis = 0.99
			J = cost(hypothesis, data.count[key], bin_clas_for_house)
			print("this is cost ret: ", J)
		#	grad_ret = grad(data.count[key], hypothesis, data.sorted_dict[key], bin_clas_for_house)
#			print("this is J ", grad_ret)
		
sample = describe.open_file(None)		#converts csv to py dict
data = my_data.data(sample)		#runs anylasis on data

sub = filter_by_key(sample, "Hogwarts House", "Ravenclaw", data)	#Ravenclaw subset
sub_2 = filter_by_key(sample, "Hogwarts House", "Gryffindor", data)	#Gryffindor subset
sub_3 = filter_by_key(sample, "Hogwarts House", "Slytherin", data)	#Slytherin subset
sub_4 = filter_by_key(sample, "Hogwarts House", "Hufflepuff", data)	#Hufflepuff

Rave = my_data.data(sub)	#Ravenclaw describe subset
Gryf = my_data.data(sub_2)	#Gtyfindor describe subset
Slyt = my_data.data(sub_3)	#Slytherin describe subset
Huff = my_data.data(sub_4)	#Hufflepuff describe subset
logistic_regresion(Rave, data, "Ravenclaw")
logistic_regresion(Gryf, data, "Gryffindor")
logistic_regresion(Slyt, data, "Slytherin")
logistic_regresion(Huff, data, "Hufflepuff")
#print(is_member_of_house("Gryffindor", data.data["Hogwarts House"]))
#print(is_member_of_house("Ravenclaw", data.data["Hogwarts House"]))
#print(is_member_of_house("Slytherin", data.data["Hogwarts House"]))
#print(is_member_of_house("Hufflepuff", data.data["Hogwarts House"]))
