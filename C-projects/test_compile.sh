#testing if everting complies
gcc get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/main.c -I get_next_line -o get_next_line/gnl
make -C libft
make -C libft bonus
make -C minishell
make -C philosophers/philo
make -C philosophers/philo_bonus
make -C pushswap
make -C ft_printf

ls ft_printf/libftprintf.a libft/libft.a philosophers/philo/philo philosophers/philo_bonus/philo_bonus pushswap/push_swap get_next_line/gnl minishell/minishell

if [ $? -eq 0 ]; then
	echo -e "\033[0;32msuccess compliling\033[0m"
	return 1
else
	echo -e "\033[0;31mfailed compiling\033[0m"
	return 1
fi


#testing if everting cleans it self up
make -C libft fclean
make -C ft_printf fclean
make -C minishell fclean
make -C philosophers/philo fclean
make -C philosophers/philo_bonus fclean
make -C pushswap fclean
rm -rf ./get_next_line/gnl

lines=$(find ./ -name "*.o" | wc -l)
if [ $lines -eq 0 ]; then
	echo -e "\033[0;32msuccess cleaning up\033[0m"
else
	echo -e "\033[0;31mfailed cleaning up\033[0m"
	return 1
fi
