# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    simulation.mk                                      :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrust@student.codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/01 11:37:39 by alkrusts      #+#    #+#                  #
#    Updated: 2022/03/14 20:14:40 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libsimulation.a
ODIR := .obj
dDIR := .debug
SDIR := src

HEADER := ../inc

CC := gcc

FLAGS = -Wall -Wextra -Werror -I $(HEADER)
#for failing
#FLAGS += -D PTHREAD_CREATE_COUNT=0

C_THREAD := -fsanitize=thread -g
C_MEMORY := -fsanitize=address -g

ifdef thread
	FLAGS += $(C_THREAD)
endif

ifdef memory
	FLAGS += $(C_MEMORY)
endif


RUN_TIME := eating.c \
	ft_sleep_utils.c \
	handel_forks.c \
	is_starved.c \
	print_stuff.c \
	sleeping.c \
	subset_functions.c \
	subset_functions.c \
	done_recursin_functions.c \
	subtract_time.c \
	reset_time_between_meals.c \
	new_semaphore.c \
	malloc_wrapper.c \
	kill_all_philosophers.c \
	set_id.c \
	set_pid.c \
	set_printing_semaphore.c \
	set_processes.c \
	set_program_args.c \
	set_forks.c \
	allocate_philosophers.c \
	set_kill_all.c \
	set_time_since_simulatoin_start.c \
	set_time.c \
	wait_for_processes.c \
	monitoring_thread.c \
	make_processes.c \
	thinking.c

OBJ += $(addprefix $(ODIR)/$(SDIR)/, $(RUN_TIME:.c=.o))

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
	mkdir -p $(ODIR)/$(SDIR)/; \
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
