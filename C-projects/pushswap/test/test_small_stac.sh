#!/bin/bash

# Test script for minishell echo builtin

# Colors
GREEN="\033[0;32m"
WHITE="\e[1;37m"
RED="\033[0;31m"
RESET="\033[0m"


# Path to root directory of minishell
PUSH_SWAP_DIR="../"

# Test input/output files
INPUT="stack_3.in"
INPUT_1="stack_4.in"
INPUT_2="stack_5.in"

KO=0
OK=0
COUNT=0
SEGFAULT=0

# Read input file and pass each LINE as an argument to bash and minishell
echo "3 dig"
while read -r LINE
do
	./push_swap $LINE | wc -l
done < $INPUT
echo "4 dig"
while read -r LINE
do
	echo $LINE
	./push_swap $LINE | wc -l
done < $INPUT_1

echo "5 dig"
while read -r LINE
do
	echo $LINE
	./push_swap $LINE | wc -l
done < $INPUT_2
