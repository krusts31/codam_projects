# get_next_line
Read a line from a file and puts it in to a `char *`

##### To use the get_next_line

```sh
git clone
gcc get_next_line.c get_next_line_utils.c main.c
./a.out file_1
```
##### test.sh automates failing mallocs to see if there are any hidden errors.
```sh
for ((i = 1; i <= 100; i++));
do
	gcc main.c get_next_line.c get_next_line_utils.c -D MALLOC_COUNT=$i -Wall -Werror -Wextra -fsanitize=address -g
	./a.out main.c get_next_line.c get_next_line_utils.c
done
```
##### my jurney:
1. Learned about static varibles in C.
2. Learned about how to stop cheeky SEGFAULTS and memory leaks.
3. Learned about scripting to test programmes.
4. Learned how to handle file descriptors.
5. Learned about marcos in C.
