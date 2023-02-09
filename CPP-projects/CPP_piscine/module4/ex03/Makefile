NAME = Magic 
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
COMP = c++

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp 


SRCO = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRCO)
	$(COMP) $(SRCO) $(CFLAGS) -o $(NAME)
%.o: %.cpp
	$(COMP) -c -o $@ $< $(CFLAGS) 
clean:
	rm -rf $(SRCO)
fclean: clean
	rm -rf $(NAME)
re: clean fclean all

run:
	$(MAKE) all
	./$(NAME)
