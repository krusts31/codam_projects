NAME = ZombieH 
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
COMP = clang++

SRC = main.cpp Zombie.cpp ZombieHorde.cpp

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
