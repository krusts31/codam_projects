NAME = Bureaucrat 
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
COMP = c++

SRC = main.cpp Bureaucrat.cpp

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
