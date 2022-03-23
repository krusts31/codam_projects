# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    parser.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrust@student.codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/25 20:34:33 by alkrusts      #+#    #+#                  #
#    Updated: 2022/03/14 19:11:57 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libparser.a
ODIR := .obj
DDIR := .debug

SDIR := src
HEADER := ../inc

CC := gcc

FLAGS = -Wall -Wextra -Werror -I $(HEADER)

C_THREAD := -fsanitize=thread -g
C_MEMORY := -fsanitize=address -g

ifdef THREAD 
	FLAGS += $(C_THREAD)
endif

ifdef MEMORY
	FLAGS += $(C_MEMORY)
endif

DEP += $(NAME)

SRC := is_int.c \
	parser.c \
	lexer.c \
	atoi.c \
	is_spaces.c \
	is_digit.c \
	print_error_exit.c \
	set_programm_args_in_template.c \
	skip_spaces.c

OBJ := $(addprefix $(ODIR)/$(SDIR)/, $(SRC:.c=.o))

DBG := $(patsubst %,$(DDIR)/%,$(OBJ))

CC := gcc

all: creat_dir $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(ODIR)/%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

creat_dir:
	if [ ! -d "$(ODIR)" ];then mkdir -p $(ODIR)/$(SDIR); fi


clean:
	/bin/rm -rf $(ODIR) $(dDIR)

fclean: clean
	/bin/rm -rf $(NAME)

memory: fclean
	make MEMORY=1 -f parser.mk

thread: fclean
	make THREAD=1 -f parser.mk

re: fclean all
