# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrusts@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/20 11:05:23 by alkrusts      #+#    #+#                  #
#    Updated: 2020/11/14 14:54:04 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = ft_atoi.c ft_isascii.c ft_memmove.c ft_putstr_fd.c \
	ft_strlcpy.c ft_tolower.c ft_bzero.c ft_isdigit.c \
	ft_memrcpy_bonus.c ft_strlen.c ft_toupper.c \
	ft_isprint.c ft_memset.c ft_free_2dim_array_bonus.c ft_strmapi.c \
	ft_compare_bonus.c ft_itoa.c ft_putchar_bonus.c \
	ft_strncmp.c ft_split.c ft_strnlen_bonus.c \
	ft_putchar_fd.c ft_strchr.c ft_strnstr.c \
	ft_memccpy.c ft_putendl_fd.c \
	ft_strrchr.c ft_intlen_bonus.c \
	ft_memchr.c ft_putlst_bonus.c ft_strdup.c \
	ft_isalnum.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c \
	ft_strtrim.c ft_isalpha.c ft_memcpy.c ft_putstr_bonus.c \
	ft_strlcat.c ft_substr.c ft_calloc.c ft_uitoa.c ft_long_len_bonus.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_lstsize.c ft_lstlast.c

OBJ = $(SRC:.c=.o)

ifdef DEBUG
	CFLAGS =-Wall -Werror -Wextra -g -fsanitize=address
else ifdef FAST
	CFLAGS =-Wall -Werror -Wextra -O3
else
	CFLAGS =-Wall -Werror -Wextra
endif


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

fast:
	$(MAKE) FAST=1 all
debug:
	$(MAKE) DEBUG=1 all

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $< 

clean:
	/bin/rm -f $(OBJ) 

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
