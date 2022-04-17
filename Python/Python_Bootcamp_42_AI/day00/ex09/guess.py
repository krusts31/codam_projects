import sys
import random

greeting_message = "This is an interactive guessing game!\
\nYou have to enter a number between 1 and 99 to find out the secret number. Type 'exit' to end the game.\
\nGood luck!"
guess_message = "What's your guess between 1 and 99?"
congoratulations_message = "Congratulations, you've got it!"
Douglas_Admas_qute = "The answer to the ultimate question of life, the universe and everything is 42."
first_atmept = "Congratulations! You got it on your first try!"

print(greeting_message)

random.seed()
answear = random.randrange(1, 99)
guess_count = 1 

while (1):
	print(guess_message)
	user_input = input()
	if 'exit' == user_input.rstrip():
		print("Goodbye")
		break
	if (not(user_input.rstrip().isdigit())):
		print("That's not a number.")
	else:
		user_input = int(user_input)
		if (isinstance(user_input, int)):
			if (user_input > answear):
				print("Too high!")
			if (user_input < answear):
				print("Too low!")
			if (user_input == answear):
				if (user_input == 42):
					print(Douglas_Admas_qute)
				if (guess_count == 1):
					print (first_atmept)
					break
				print(congoratulations_message)
				break
		guess_count = guess_count + 1
