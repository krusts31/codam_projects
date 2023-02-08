for ((i = 1; i <= 100; i++));
do
	gcc main.c get_next_line.c get_next_line_utils.c -D MALLOC_COUNT=$i -Wall -Werror -Wextra -fsanitize=address -g
	./a.out main.c get_next_line.c get_next_line_utils.c
done
