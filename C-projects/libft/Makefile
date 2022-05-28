# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                            :+:    :+:            #
#                                                      +:+                     #
#    By: alkrusts <alkrusts@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/20 11:05:23 by alkrusts      #+#    #+#                  #
#    Updated: 2022/05/29 01:12:24 by alkrusts        ########   odam.nl        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC=emcc

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra

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
	ft_cpystr_bonus.c

SRC_OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_lstsize.c ft_lstlast.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

ifdef WITH_BONUS
	OBJ = $(SRC_OBJ) $(BONUS_OBJ)
else
	OBJ = $(SRC_OBJ)
endif

all: $(NAME)
	emcc libft.a -o libft.html -O2 -s WASM=1 -s EXPORTED_FUNCTIONS="['_ft_atoi', '_ft_bzero', '_ft_calloc', '_ft_compare', '_ft_cpystr', '_ft_free_2dim_array', '_ft_intlen', '_ft_isalnum', '_ft_isalpha', '_ft_isascii', '_ft_isdigit', '_ft_isprint', '_ft_itoa', '_ft_longlen', '_ft_lstadd_back', '_ft_lstadd_front', '_ft_lstclear', '_ft_lstdelone', '_ft_lstiter', '_ft_lstlast', '_ft_lstmap', '_ft_lstnew', '_ft_lstsize', '_ft_memccpy', '_ft_memchr', '_ft_memcmp', '_ft_memcpy', '_ft_memmove', '_ft_memrcpy', '_ft_memset', '_ft_putchar', '_ft_putchar_fd', '_ft_putendl_fd', '_ft_putlst', '_ft_putnbr_fd', '_ft_putstr', '_ft_putstr_fd', '_ft_split', '_ft_strchr', '_ft_strdup', '_ft_strjoin', '_ft_strlcat', '_ft_strlcpy', '_ft_strlen', '_ft_strmapi', '_ft_strncmp', '_ft_strnlen', '_ft_strnstr', '_ft_strrchr', '_ft_strtrim', '_ft_substr', '_ft_tolower', '_ft_toupper', '_ft_uitoa']" -s EXPORTED_RUNTIME_METHODS="['cwrap']" -s ALLOW_MEMORY_GROWTH=1 -s ABORTING_MALLOC=0 -I .

$(NAME): $(OBJ)
	emar rcs $@ $^

bonus:
	$(MAKE) WITH_BONUS=1 all

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f $(SRC_OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f  $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
