CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
COMPAILER = clang++
NAME = replace
SRC = main.cpp
all: $(NAME)

$(NAME):
	$(COMPAILER) $(SRC) $(CPPFLAGS) -o $(NAME)

clean:
	/bin/rm -rf $(NAME)

re: fclean all

