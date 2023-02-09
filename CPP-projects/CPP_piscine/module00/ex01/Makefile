CPPFLAGS = -Wall -Werror -Wextra
COMPAILER = c++
NAME = phonebook
SRC = info.class.cpp contact.class.cpp main.cpp
all: $(NAME)

$(NAME):
	$(COMPAILER) $(SRC) $(CPPFLAGS) -o $(NAME)

clean:
	/bin/rm -rf $(NAME)

re: clean all
