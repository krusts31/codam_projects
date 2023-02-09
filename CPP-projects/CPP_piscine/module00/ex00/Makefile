CPPFLAGS = -Wall -Werror -Wextra -std=c++98
COMPAILER = c++
NAME = megaphone
SRC = megaphone.cpp

all: $(NAME)

$(NAME):
	$(COMPAILER) $(SRC) $(CPPFLAGS) -o $(NAME)

clean:
	/bin/rm -rf $(NAME)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
