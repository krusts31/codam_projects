# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts/dkrecisz <marvin@codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/02 10:36:33 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/11/06 12:09:22 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := minishell 

#COLORS FOR FUN

RED := \033[0;31m
GREEN := \033[0;32m
BLUE := \033[0;34m
LBLUE := \033[1;34m
NC := \033[0m

#used folders

SDIR := src
IDIR := inc
ODIR := obj
DDIR := .debug
TDIR := tests

OS = $(shell uname)

#all the files

SRC = main.c \
	minishell.c \
	exit_shell.c \
	init_data.c \
	minishell_calloc.c \
	minishell_write.c \
	minishell_putchar_fd.c \
	minishell_putstr_fd.c \
	minishell_strdup.c \
	minishell_putendl_fd.c \
	minishell_lstnew.c \
	increment_shlvl.c \
	built_in_functions/builtin_echo.c \
	built_in_functions/builtin_cd.c \
	built_in_functions/builtin_pwd.c \
	built_in_functions/builtin_export.c \
	built_in_functions/builtin_unset.c \
	built_in_functions/builtin_env.c \
	built_in_functions/builtin_exit.c \
	lexer/lexer.c \
	lexer/lexer_utils_1.c \
	lexer/lexer_utils_2.c \
	lexer/lexer_count_tokens.c \
	lexer/make_token_meta.c \
	lexer/make_token_quote.c \
	lexer/expand_variables.c \
	lexer/expand_utils_1.c \
	lexer/expand_utils_2.c \
	lexer/split_words.c \
	lexer/word_splitter.c \
	lexer/quote_removal.c \
	parser/parser.c \
	parser/parser_utils.c \
	parser/parse_pipeline.c \
	parser/parse_word_list.c \
	parser/parse_command.c \
	parser/parse_redirection.c \
	executor/execute_here_utils.c \
	executor/execute.c \
	executor/execute_child_utils.c \
	executor/execute_pipeline.c \
	executor/execute_command.c \
	executor/execute_word_list.c \
	executor/execute_builtin.c \
	executor/execute_here_doc.c \
	executor/execute_redirection.c \
	executor/execute_redirection_utils.c \
	executor/execute_utils.c \
	executor/search_command.c \
	executor/execute_free_child.c \
	executor/make_comand.c \
	environ/environ.c \
	environ/environ_utils.c \
	environ/environ_get_keyvalue.c \
	environ/environ_utils_2.c \
	signals/signals.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJ = $(addprefix $(ODIR)/$(SDIR)/, $(SRC:.c=.o))

LIBFT = libft
READLINE =	-lreadline \
			-L/usr/local/opt/readline/lib \
			-L$(HOME)/.brew/Cellar/readline/8.1.1/lib
LIBS = -L $(LIBFT) -lft $(READLINE)

#headers aka dependencys

HEADER :=	-I $(IDIR) -I $(LIBFT) \
			-I/usr/local/opt/readline/include \
			-I/Users/alkrusts/.brew/opt/readline/include \
			-I$(HOME)/.brew/Cellar/readline/8.1.1/include

DBG := $(patsubst %,$(DDIR)/%,$(OBJ))

#flags
 
C_DEBUG := -fsanitize=address -g -Wall -Werror -Wextra  $(HEADER)
C_REGULAR := -Wall -Wextra -Werror -g $(HEADER)

CC := gcc

ifdef DEBUG
	FLAGS = $(C_DEBUG)
else
	FLAGS = $(C_REGULAR)
endif

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "${GREEN}minishell ready!${NC}"

$(ODIR)/%.o: %.c
	@mkdir -p $(ODIR)/$(SDIR)/built_in_functions \
		$(ODIR)/$(SDIR)/lexer \
		$(ODIR)/$(SDIR)/parser \
		$(ODIR)/$(SDIR)/executor \
		$(ODIR)/$(SDIR)/environ \
		$(ODIR)/$(SDIR)/get_next_line \
		$(ODIR)/$(SDIR)/signals
	@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(LIBFT)/libft.a:
	@echo "${GREEN}Building libft${NC}"
	@make -C $(LIBFT)
	@echo "${GREEN}libft ready!${NC}"
	@echo "${GREEN}Building minishell${NC}"

clean:
	@echo "${RED}Cleaning build!${NC}"
	@rm -rf $(ODIR)
	@echo "${RED}Cleaning libft!${NC}"
	@make -C $(LIBFT) clean

fclean: clean
	@echo "${RED}Deleting minishell!${NC}"
	@rm -rf $(NAME)
	@echo "${RED}Deleting libft!${NC}"
	@make -C $(LIBFT) fclean

re: fclean all

run: all
	@./$(NAME)

debug: fclean
	@make DEBUG=1

.PHONY: all bonus clean fclean re run
