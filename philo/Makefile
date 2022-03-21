NAME 		:= philo
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g -pthread

HEADERS		=	.


INCLUDES	=	$(addprefix -I, $(HEADERS))

SRCS = main.c\
		ft_calloc.c\
		init_philosophers.c\
		ft_atoi.c\
		ft_isdigit.c\
		get_time_ms.c\
		delete_philosophers.c\
		manage_mutexes.c\
		simulate_philosophers.c\
		monitor_philosophers.c\
		last_ate_at.c\
		liveness.c\
		simulate_single_philosopher.c\
		print_log.c\
		forks.c\
		fork_interfaces.c\
		get_fork_id.c\
		ft_swap.c\
		sleep_in_ms.c\



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
