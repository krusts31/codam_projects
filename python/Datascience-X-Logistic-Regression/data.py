import math

class data():
	"""contains the describe fileds similar to pandas df"""
	def __init__(self, sample):
		self.count = self.calc_count(sample)
		self.mean = self.calc_mean(sample)
		self.max = self.calc_max(sample)
		self.min = self.calc_min(sample)
		self.dict_25 = self.calc_25(sample)
		self.dict_50 = self.calc_50(sample)
		self.dict_75 = self.calc_75(sample)
		self.std = self.std_calc(sample)
		self.data = sample
		self.sorted_dict = self.sort_sample(sample)

	def sort_sample(self, sample):
		sorted_dict = dict.fromkeys(sample)
		copy_dict = sample.copy()
		for key in copy_dict:
			test = 0
			for elem in sample[key]:
				if (isinstance(elem, str)):
					test = 1
			if (test == 0):
				index = 0
				list_sorted = [x for x in copy_dict[key] if x]#removes all the None, 0, "" values
				list_sorted.sort()
				sorted_dict[key] = list(list_sorted)
		return sorted_dict

	def calc_count(self, sample):
		"""calculates the count of key for key in dict"""
		count_dict = dict.fromkeys(sample)
		for key in sample:
			cnt = 0
			for element in sample[key]:
				if (element is not ""):
					cnt = cnt + 1
			count_dict[key] = cnt
		return count_dict

	def calc_mean(self, sample):
		"""calculates the mean for key in dict"""
		mean_dict = dict.fromkeys(sample)
		sum_of_elements = 0
		for key in sample:
			sum_of_elements = 0 
			for element in sample[key]:
				if (element is not "" and isinstance(element, float)):
					sum_of_elements = element + sum_of_elements
			if (self.count[key] > 0):
				mean_dict[key] = sum_of_elements / self.count[key]
		return mean_dict

	def calc_max(self, sample):
		"""calculates the max for key in dict"""
		max_dict = dict.fromkeys(sample)
		max_value = float('-inf') 
		for key in sample:
			for num in sample[key]:
				if (num is not "" and isinstance(num, float)):
					if (num > max_value):
						max_value = num
			max_dict[key] = max_value
			max_value = float('-inf')
		return max_dict

	def calc_min(self, sample):
		"""calculates min for key in dict"""
		max_dict = dict.fromkeys(sample)
		max_value = float('inf') 
		for key in sample:
			for num in sample[key]:
				if (num is not "" and isinstance(num, float)):
					if (num < max_value):
						max_value = num
			max_dict[key] = max_value
			max_value = float('inf')
		return max_dict

	def calc_25(self, sample):
		"""calculates precentile 25% for key in dict"""
		dict_25 = dict.fromkeys(sample)
		copy_sample = sample.copy()
		for key in copy_sample:
			test = 0
			for elem in sample[key]:
				if (isinstance(elem, str)):
					test = 1
			if (test == 0):
				index = 0
				list_sorted = [x for x in copy_sample[key] if x]#removes all the None, 0, "" values
				list_sorted.sort()
				limit = int(self.count[key] * 0.25)
				for num in list_sorted:
					if (index == limit):
						dict_25[key] = num
					index = index + 1
		return dict_25

	def calc_50(self, sample):
		"""calculates precentile 50% for key in dict"""
		dict_50 = dict.fromkeys(sample)
		copy_sample = sample.copy()
		for key in copy_sample:
			test = 0
			for elem in sample[key]:
				if (isinstance(elem, str)):
					test = 1
			if (test == 0):
				index = 0
				list_sorted = [x for x in copy_sample[key] if x]#removes all the None, 0, "" values
				list_sorted.sort()
				limit = int(self.count[key] * 0.50)
				for num in list_sorted:
					if (index == limit):
						dict_50[key] = num
					index = index + 1
		return dict_50

	def calc_75(self, sample):
		"""calculates precentile 75% for key in dict"""
		dict_75 = dict.fromkeys(sample)
		copy_sample = sample.copy()
		test = 0
		for key in copy_sample:
			test = 0
			for elem in sample[key]:
				if (isinstance(elem, str)):
					test = 1
			if (test == 0):
				index = 0
				list_sorted = [x for x in copy_sample[key] if x] #removes all the None, 0, "" values
				list_sorted.sort()
				limit = int(self.count[key] * 0.75)
				for num in list_sorted:
					if (index == limit):
						dict_75[key] = num
					index = index + 1
		return dict_75

	def std_calc(self, sample):
		"""calculates std for key in dict"""
		std_dict = dict.fromkeys(sample)
		variance = dict.fromkeys(sample)
		for key in sample:
			variance[key] = 0
			for element in sample[key]:
				if (element is not "" and isinstance(element, float)):
					variance[key] = pow(element - self.mean[key], 2) + variance[key]
			if (self.count[key] > 1):
				std_dict[key] = math.sqrt(variance[key] / (self.count[key] - 1))
		return std_dict
