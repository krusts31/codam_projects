# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrust@student.codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/04 18:08:05 by alkrusts      #+#    #+#                  #
#    Updated: 2022/03/14 20:11:50 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := philo_bonus

PARSER := -lparser
DIRPARSER := -L ./parser
SIMULATION := -lsimulation
DIRSIMULATION := -L ./simulation

ODIR := .obj
dDIR := .debug

SRC := main.c
HEADER := inc

MODULES := $(DIRPARSER) $(PARSER) $(DIRSIMULATION) $(SIMULATION)
MOD_NAME = ./parser/libparser.a
MOD_NAME += ./simulation/libsimulation.a

CC := gcc

FLAGS = -Wall -Wextra -Werror -I $(HEADER)
#to support tail recursoin! :)

C_THREAD := -fsanitize=thread -g
C_MEMORY := -fsanitize=address -g

DEP = par simu

ifdef thread
	FLAGS += $(C_THREAD)
	DEP = parthraed simuthread
endif

ifdef memory
	FLAGS += $(C_MEMORY)
	DEP = parmem simumem
endif

OBJ := $(addprefix $(ODIR)/, $(SRC:.c=.o))

DBG := $(patsubst %,$(dDIR)/%,$(OBJ))

all: creat_dir $(DEP) $(NAME)
	@echo $(DBG)

$(NAME): $(OBJ) $(MOD_NAME)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MODULES)

$(ODIR)/%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C parser clean -f parser.mk
	make -C simulation clean -f simulation.mk
	rm -rf $(ODIR)

fclean: clean
	make -C parser fclean -f parser.mk
	make -C simulation fclean -f simulation.mk
	rm -rf $(NAME)

re: fclean all

memory: fclean
	make memory=1

thread: fclean
	make thread=1

par:
	make -C parser -f parser.mk

simu:
	make -C simulation -f simulation.mk

parmem:
	make memory -C parser -f parser.mk

simumem:
	make memory -C simulation -f simulation.mk

parthraed:
	make thread -C parser -f parser.mk

simuthread:
	make thread -C simulation -f simulation.mk

creat_dir:
	if [ ! -d "$(ODIR)" ]; then	mkdir -p $(ODIR); fi

.PHONY: all bonus clean fclean re run
