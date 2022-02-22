NAME 		:= philo
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g -pthread -fsanitize=thread

HEADERS		=	.


INCLUDES	=	$(addprefix -I, $(HEADERS))

SRCS = main.c\
		init_args.c\
		delete_args.c\
		ft_calloc.c\
		init_philosopher.c\
		get_time_ms.c\
		init_vars.c\
		delete_vars.c\
		delete_philosophers.c\
		delete_forks.c\
		start_philosophers.c\
		eat.c\
		print_log.c\
		get_fork_id.c\
		ft_swap.c\
		sleep_in_ms.c\
		go_to_sleep.c\
		think.c\
		monitor_starving.c\


OBJS = ${SRCS:.c=.o}

DEPS = $(OBJS:.o=.d)

RED			=	'\033[31m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[33m'
RESET		=	'\033[0m'

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES)  -o $(NAME) $(OBJS)
	@echo $(YELLOW)"@@@@@ $(NAME) compiling done @@@@@"$(RESET)

%.o: %.c
	@echo $(GREEN)"Creating: $@"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: clean
clean:
	@rm -f $(OBJS)
	@echo $(RED)"REMOVE OBJECT FILES $(OBJS)"$(RESET)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"REMOVE $(NAME)"$(RESET)

re: fclean all
