import sys

input_prompt_message = "Please select an option by typing the corresponding number:\n1: Add a recipe\n2: Delete a recipe\n3: Print a recipe\n4: Print the cookbook\n5: Quit"
input_not_from_list_of_options = "his option does not exist, please type the corresponding number.\nTo exit, enter 5."
close_message = "\nCookbook closed."
qestion_one = "Whats the name of the recipe?\n"
qestion_tow = "What time do you like to eat it?\n"
qestion_tree = "How long do you cook it (value will be appened with min)?\n"
qestion_fore = "Whats are the ingredients?\nKeep adding when done type: \"END\"(with capital letters)"

print(input_prompt_message)

#stdin is used for all interactive input (including calls to input());

cookbook = {	1: {'name': 'sandwich', 'ingredients': ['bread', 'butter', 'sausage', 'tomato', 'salt'], 'meal': 'eat when hungry :D', 'prep_time': '5'},
		2: {'name': 'cake', 'ingredients': ['eggs', 'sugar', 'cookies', 'cocopoweder', 'butter'], 'meal': 'weekedns or partys', 'prep_time': '60'},
		3: {'name': 'salad', 'ingredients': ['carotrs', 'cream', 'garlic', 'chees'], 'meal': 'dinner', 'prep_time': '10'},
}

def print_recipe(recipe):
	print("Recipe for: " + str(recipe['name']))
	print("Ingredients list: " + str(recipe['ingredients']))
	print("To be eaten for " + str(recipe['meal']) + ".")
	print("Takes " + str(recipe['prep_time']) + " minutes of cooking.")

def print_cookbook(cookbook):
	print("\n")
	for recipe_id, recipe_info in cookbook.items():
		print_recipe(recipe_info)
		print("\n")

def add_recipe(cookbook):
	ingredients = []
	size = len(cookbook) + 1
	new_recipe = {'name': input(qestion_one),\
	'meal': input(qestion_tow),\
	'ingredients': [""],\
	'prep_time': input(qestion_tree)}
	print(qestion_fore)
	for line_2 in sys.stdin:
		x = 0
		if (line_2.rstrip() == "END"):
			break
		else:
			ingredients.insert(x, line_2.rstrip())
			x = x + 1
	new_recipe.update({"ingredients": ingredients})
	cookbook[size] = new_recipe

def delete_recipe(cookbook):
	print_cookbook(cookbook)
	recipe_name = input("Please enter the recipe's name to delete it\n")
	#creating a copy for the cook book because you can not iterate over the same dictonary and delte elements from it
	for recipe_id, recipe_info in cookbook.copy().items():
		for key in recipe_info:
			if (key == 'name'):
				if (recipe_info[key] == recipe_name):
					del cookbook[recipe_id]
	
def search_for_recipe(cookbook):
	recipe_name = input("Please enter the recipe's name to get its details:\n")
	for recipe_id, recipe_info in cookbook.items():
		for key in recipe_info:
			if (recipe_info[key] == recipe_name):
				print_recipe(recipe_info)

for line in sys.stdin:
	if '5' == line.rstrip():
		break
	elif '4' == line.rstrip():
		print_cookbook(cookbook)
	elif '3' == line.rstrip():
		search_for_recipe(cookbook)
	elif '2' == line.rstrip():
		delete_recipe(cookbook)
	elif '1' == line.rstrip():
		add_recipe(cookbook)
	else:
		print(input_not_from_list_of_options)
print(close_message)
