CPPFLAGS = -Wall -Werror -Wextra
COMPAILER = clang++
NAME = a.out
SRC = main.cpp Fixed.class.cpp
all: $(NAME)

$(NAME):
	$(COMPAILER) $(SRC) $(CPPFLAGS) -o $(NAME)

clean:
	/bin/rm -rf $(NAME)

re: clean all


