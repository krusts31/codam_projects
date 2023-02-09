NAME = STARWARS 
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -g -fsanitize=address
COMP = c++

SRC = main.cpp  Squad.cpp  TacticalMarine.cpp AssaultTerminator.cpp 


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
