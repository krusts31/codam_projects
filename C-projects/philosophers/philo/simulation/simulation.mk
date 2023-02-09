# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    simulation.mk                                      :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrust@student.codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/01 11:37:39 by alkrusts      #+#    #+#                  #
#    Updated: 2022/03/14 19:34:26 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libsimulation.a
ODIR := .obj
dDIR := .debug
SDIR := src

SDIR := src
HEADER := ../inc

CC := gcc

FLAGS = -fsplit-stack -Wall -Wextra -Werror -I $(HEADER)
#FLAGS += -D PTHREAD_CREATE_COUNT=22

C_THREAD := -fsanitize=thread -g
C_MEMORY := -fsanitize=address -g

ifdef thread
	FLAGS += $(C_THREAD)
endif

ifdef memory
	FLAGS += $(C_MEMORY)
endif


SRC := subset_functions.c \
	set_philosophers.c \
	alloc_and_init_muteces.c \
	set_philosopher_time_of_death.c \
	eating.c \
	set_forks.c \
	set_locks.c \
	set_time_between_meals.c \
	set_time.c \
	set_index.c \
	set_utils.c \
	set_programm_args.c \
	set_all_to_dead.c \
	set_programm_args_in_template.c \
	monitoring_thread.c \
	reset_time_between_meals.c \
	is_starved.c \
	make_threads.c \
	join_exited_threads.c \
	handel_forks.c \
	thinking.c \
	sleeping.c \
	eating_sleeping_thinking.c \
	is_template_valid.c \
	init.c \
	allocate.c \
	ft_sleep_utils.c \
	done_recursin_functions.c \
	destroy_muteces.c \
	unlock_all_muteces.c \
	free_template.c \
	debug_mutex_lock.c \
	print_stuff.c \
	set_thread_to_exited.c \
	is_philosopher_dead.c \
	are_all_done.c \
	subtract_time.c

OBJ += $(addprefix $(ODIR)/$(SDIR)/, $(SRC:.c=.o))

DBG := $(patsubst %,$(dDIR)/%,$(OBJ))

CC := gcc

all: creat_dir $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(ODIR)/%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

creat_dir:
	if [ ! -d "$(ODIR)" ]; \
	then \
	mkdir -p $(ODIR)/$(SDIR); \
	fi

clean:
	/bin/rm -rf $(ODIR) $(dDIR)

fclean: clean
	/bin/rm -rf $(NAME)

memory: fclean
	make memory=1 -f simulation.mk

thread: fclean
	make thread=1 -f simulation.mk

re: fclean all
