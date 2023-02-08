# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrusts@student.codam.nl>          +#+                     #
#                                                    +#+                       #
#    Created: 2020/11/14 16:50:00 by alkrusts      #+#    #+#                  #
#    Updated: 2020/12/07 18:13:01 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h
LIB = -L libft/ -lft

SRC = ft_printf.c ft_do_char.c ft_do_helx.c ft_do_hex.c ft_do_ptr.c \
		ft_do_str.c ft_do_uni.c ft_do_prec.c ft_utils.c ft_do_int.c \
		ft_hex_utils.c ft_hex_utils_1.c ft_str_utils.c \
		ft_str_utils_1.c ft_int_utils.c ft_int_utils_1.c \
		ft_utils_1.c

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C libft
	cp libft/libft.a ./libftprintf.a
	ar rcs $@ $^

%.o: %.c $(HEADER) 
	$(CC) -c $(CFLAGS) $< -o $@

do:
	gcc -o a.out $(CFLAGS) main.c -L . -lftprintf

clean:
	make clean -C libft 
	@/bin/rm -f $(SRC_OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
