CC = cc

NAME = philo

SRCS = argument_handler_util.c argument_handler.c create_philosopher.c \
		death_handler.c death_watcher.c eating_time.c fork_handler.c \
		main.c pick_or_put_fork.c resource_distributor.c routine_func.c \
		sleeping_time.c time_handler.c only_one_philo.c free_all_resource.c \
		destroy_all_mutex.c thinking_time.c
		
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o ${NAME}

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY : bonus
.PHONY : all
.PHONY : clean
.PHONY : fclean
.PHONY : re