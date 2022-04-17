import describe as describe
import data as my_data
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import matplotlib.colors as colors

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

#there are 14 numerical keys
def scat(Rave, Gryf, Slyt, Huff, New):
	sub_default = filter_by_key(sample, "Hogwarts House", "Ravenclaw", data)	#Ravenclaw subset
	default = my_data.data(sub_default)						#Ravenclaw describe subset
	for key in default.sorted_dict:
		if (describe.not_nuermical(key)):
			index_y = 0 
			index_x = 0
			index = 0
			name_r = ""
			name_g = ""
			name_s = ""
			name_h = ""
			name_n = ""
			if (Rave is not None):
				rave_cpy = {} 
				rave_cpy = dict.fromkeys(Rave.data)
				rave_cpy_count = {} 
				rave_cpy_count = dict.fromkeys(Rave.count)
				colors=["green"]
				name_r = "Ravenclaw"
			if (New is not None):
				new_cpy = {} 
				new_cpy = dict.fromkeys(New.data)
				new_cpy_count = {} 
				new_cpy_count = dict.fromkeys(New.count)
				colors_n=["black"]
				name_n = "Potential students"
			if (Gryf is not None):
				gryf_cpy = {} 
				gryf_cpy = dict.fromkeys(Gryf.data)
				gryf_cpy_count = {} 
				gryf_cpy_count = dict.fromkeys(Gryf.count)
				colors_g=["red"]
				name_g = "Gryffindor"
			if (Slyt is not None):
				slyt_cpy = {} 
				slyt_cpy = dict.fromkeys(Slyt.data)
				slyt_cpy_count = {} 
				slyt_cpy_count = dict.fromkeys(Slyt.count)
				colors_s=["yellow"]
				name_s = "Slytherin"
			if (Huff is not None):
				huff_cpy = {} 
				huff_cpy = dict.fromkeys(Huff.data)
				huff_cpy_count = {} 
				huff_cpy_count = dict.fromkeys(Huff.count)
				colors_h=["blue"]
				name_h = "Hufflepuff"
			fig, axs = plt.subplots(2, 7, constrained_layout=True, figsize=(20,7))
			lines = []
			labels = []
			for plot in default.data:
				if (describe.not_nuermical(plot)):
					name = key + "/" + plot
					if (index_y == 7):
						index_y = 0
						index_x = 1
					if (Rave is not None):
						rave_cpy[plot] = list(Rave.data[plot]).copy()
						rave_cpy_count[plot] = Rave.count[plot]
						slice_x = Rave.count[key]
						slice_y = rave_cpy_count[plot]
						if (slice_x > slice_y):
							fin_slice = slice_y
						else:
							fin_slice = slice_x
						x_list = Rave.data[key][0:fin_slice]
						y_list = rave_cpy[plot][0:fin_slice]
						axs[index_x][index_y].scatter(x_list, y_list, c = colors, alpha = 0.2, label = name_r)
					if (New is not None):
						new_cpy[plot] = list(New.data[plot]).copy()
						new_cpy_count[plot] = New.count[plot]
						slice_x_n = New.count[key]
						slice_y_n = new_cpy_count[plot]
						if (slice_x_n > slice_y_n):
							fin_slice_n = slice_y_n
						else:
							fin_slice_n = slice_x_n
						x_list_n = New.data[key][0:fin_slice_n]
						y_list_n = new_cpy[plot][0:fin_slice_n]
						axs[index_x][index_y].scatter(x_list_n, y_list_n, c = colors_n, alpha = 1, label = name_n)
					if (Gryf is not None):
						gryf_cpy[plot] = list(Gryf.data[plot]).copy()
						gryf_cpy_count[plot] = Gryf.count[plot]
						slice_x_g = Gryf.count[key]
						slice_y_g = gryf_cpy_count[plot]
						if (slice_x_g > slice_y_g):
							fin_slice_g = slice_y_g
						else:
							fin_slice_g = slice_x_g
						x_list_g = Gryf.data[key][0:fin_slice_g]
						y_list_g = gryf_cpy[plot][0:fin_slice_g]
						axs[index_x][index_y].scatter(x_list_g, y_list_g, c = colors_g, alpha = 0.2, label = name_g)
					if (Slyt is not None):
						slyt_cpy[plot] = list(Slyt.data[plot]).copy()
						slyt_cpy_count[plot] = Slyt.count[plot]
						slice_x_s = Slyt.count[key]
						slice_y_s = slyt_cpy_count[plot]
						if (slice_x_s > slice_y_s):
							fin_slice_s = slice_y_s
						else:
							fin_slice_s = slice_x_s
						x_list_s = Slyt.data[key][0:fin_slice_s]
						y_list_s = slyt_cpy[plot][0:fin_slice_s]
						axs[index_x][index_y].scatter(x_list_s, y_list_s, c = colors_s, alpha = 0.2, label = name_s)
					if (Huff is not None):
						huff_cpy[plot] = list(Huff.data[plot]).copy()
						huff_cpy_count[plot] = Huff.count[plot]
						slice_x_h = Huff.count[key]
						slice_y_h = huff_cpy_count[plot]
						if (slice_x_h > slice_y_h):
							fin_slice_h = slice_y_h
						else:
							fin_slice_h = slice_x_h
						x_list_h = Huff.data[key][0:fin_slice_h]
						y_list_h = huff_cpy[plot][0:fin_slice_h]
						axs[index_x][index_y].scatter(x_list_h, y_list_h, c = colors_h, alpha = 0.2, label = name_h)
					axs[index_x][index_y].set_title(name, fontsize=7)
					index_y = index_y + 1
					index = index + 1
			name = name_r + " " + name_g + " " + name_s + " " + name_h + " " + name_n 
			axLine, axLabel = axs[0][0].get_legend_handles_labels()
			lines.extend(axLine)
			labels.extend(axLabel)
			fig.legend(lines, labels , loc='upper right')
			fig.suptitle(name, fontsize=30)
			plt.show()

sample = describe.open_file(None) #converts csv to py dict
sample_new = describe.open_file("/datasets/dataset_test.csv") #converts csv to py dict
data = my_data.data(sample) #runs anylasis on traindata
data_new = my_data.data(sample_new) #runs anylasis on test data 
print(data.count["Index"])

sub = filter_by_key(sample, "Hogwarts House", "Ravenclaw", data)	#Ravenclaw subset
sub_2 = filter_by_key(sample, "Hogwarts House", "Gryffindor", data)	#Gryffindor subset
sub_3 = filter_by_key(sample, "Hogwarts House", "Slytherin", data)	#Slytherin subset
sub_4 = filter_by_key(sample, "Hogwarts House", "Hufflepuff", data)	#Hufflepuff
sub_5 = filter_by_key(sample, "Hogwarts House", "", data)	#Hufflepuff

Rave = my_data.data(sub)	#Ravenclaw describe subset
Gryf = my_data.data(sub_2)	#Gtyfindor describe subset
Slyt = my_data.data(sub_3)	#Slytherin describe subset
Huff = my_data.data(sub_4)	#Hufflepuff describe subset
scat(None, None, None, None, data_new)
