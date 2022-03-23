import describe as describe
import data as my_data
import matplotlib.pyplot as plt
import pdb

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

def hist(Rave, Gryf, Slyt, Huff):
	for key in Rave.sorted_dict:
		if (key != 'Hogwarts House' and key != 'First Name' and key != 'Last Name' and key != 'Best Hand' and key != 'Birthday'):
			box_R = int(Rave.count[key] / 2)
			box_G = int(Gryf.count[key] / 2)
			box_S = int(Slyt.count[key] / 2)
			box_H = int(Huff.count[key] / 2)
			name_R = key + " scores for " + "Ravenclaw"
			name_G = key + " scores for " + "Gryffindor"
			name_S = key + " scores for " + "Slytherin"
			name_H = key + " scores for " + "Hufflepuff"
			fig, axs = plt.subplots(2, 2, constrained_layout=True, figsize=(20,7))
			axs[0][0].hist(Rave.data[key], bins = box_R)
			axs[0][1].hist(Gryf.data[key], bins = box_G)
			axs[1][0].hist(Slyt.data[key], bins = box_S)
			axs[1][1].hist(Huff.data[key], bins = box_H)
			axs[0][0].set_title(name_R)
			axs[0][1].set_title(name_G)
			axs[1][0].set_title(name_S)
			axs[1][1].set_title(name_H)
			plt.xlabel('index')
			plt.ylabel('score')
			plt.show()

sample = describe.open_file(None) #converts csv to py dict
data = my_data.data(sample) #runs anylasis on data

sub = filter_by_key(sample, "Hogwarts House", "Ravenclaw", data)	#Ravenclaw subset
sub_2 = filter_by_key(sample, "Hogwarts House", "Gryffindor", data)	#Gryffindor subset
sub_3 = filter_by_key(sample, "Hogwarts House", "Slytherin", data)	#Slytherin subset
sub_4 = filter_by_key(sample, "Hogwarts House", "Hufflepuff", data)	#Hufflepuff

Rave = my_data.data(sub)	#Ravenclaw describe subset
Gryf = my_data.data(sub_2)	#Gtyfindor describe subset
Slyt = my_data.data(sub_3)	#Slytherin describe subset
Huff = my_data.data(sub_4)	#Hufflepuff describe subset

hist(Rave, Gryf, Slyt, Huff)
