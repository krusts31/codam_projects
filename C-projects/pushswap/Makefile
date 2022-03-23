# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts	   <alkrusts@student.codam.nl >       +#+              #
#                                                    +#+                       #
#    Created: 2021/11/02 10:36:33 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/12/09 13:24:54 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

#COLORS FOR FUN

RED := \033[0;31m
GREEN := \033[0;32m
BLUE := \033[0;34m
LBLUE := \033[1;34m
NC := \033[0m

#used folders

IDIR := inc
UDIR := utils
SDIR := sort
OPDIR := operations
PDIR := parser
PRDIR := print
ODIR := .obj
DDIR := .debug
TDIR := tests

OS = $(shell uname)

#all the files

SRC = main.c \
	$(UDIR)/malloc_wrap.c \
	$(UDIR)/comparison_functions.c \
	$(UDIR)/write_message.c \
	$(UDIR)/print_error_and_exit.c \
	$(UDIR)/ft_stack_func.c \
	$(UDIR)/ft_stack_func_2.c \
	$(UDIR)/ft_stack_func_3.c \
	$(PDIR)/parser_entry_from_main.c \
	$(PDIR)/index_stack.c \
	$(PDIR)/check_functions.c \
	$(SDIR)/sort.c \
	$(SDIR)/radix_sort.c \
	$(SDIR)/sort_size_2_4_5.c \
	$(SDIR)/sort_size_3.c \
	$(OPDIR)/sa_ra_rra_pa_pb.c

OBJ = $(addprefix $(ODIR)/, $(SRC:.c=.o))

LIBFT = libft

LIBS = -L $(LIBFT) -lft

#headers aka dependencys

HEADER := -I $(IDIR) -I $(LIBFT)

DBG := $(patsubst %,$(DDIR)/%,$(OBJ))

#flags
 
C_DEBUG := -fsanitize=address -g -Wall -Werror -Wextra $(HEADER)
C_REGULAR := -Wall -Wextra -Werror $(HEADER)

CC := gcc

ifdef DEBUG
	FLAGS = $(C_DEBUG)
else
	FLAGS = $(C_REGULAR)
endif

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "${GREEN}push_swap ready!${NC}"

$(ODIR)/%.o: %.c
	@mkdir -p $(ODIR)/utils \
		$(ODIR)/parser \
		$(ODIR)/sort \
		$(ODIR)/operations \
		$(ODIR)/print
	@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(LIBFT)/libft.a:
	@echo "${GREEN}Building libft${NC}"
	@make -C $(LIBFT)
	@echo "${GREEN}libft ready!${NC}"
	@echo "${GREEN}Building push_swap${NC}"

clean:
	@echo "${RED}Cleaning build!${NC}"
	@rm -rf $(ODIR)
	@echo "${RED}Cleaning libft!${NC}"
	@make -C $(LIBFT) clean

fclean: clean
	@echo "${RED}Deleting push_swap!${NC}"
	@rm -rf $(NAME)
	@echo "${RED}Deleting libft!${NC}"
	@make -C $(LIBFT) fclean

re: fclean all

run: all
	@./$(NAME)

debug: fclean
	@make DEBUG=1

.PHONY: all bonus clean fclean re run
