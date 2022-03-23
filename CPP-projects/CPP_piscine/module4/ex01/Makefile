NAME = DOOM 
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic 
COMP = clang++

SRC = AWeapon.cpp  Character.cpp  Enemy.cpp  main.cpp  PlasmaRifle.cpp  PowerFist.cpp  RadScorpion.cpp  SuperMutant.cpp Meseeks.cpp Railgun.cpp


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

run: re
	./$(NAME)
