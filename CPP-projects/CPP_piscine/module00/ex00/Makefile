CPPFLAGS = -Wall -Werror -Wextra
COMPAILER = clang++
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
