NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  parsing.c \
		  push_swap_utils.c \
		  check_number.c \
		  duplicate.c \
		  ft_atol.c \
		  error.c \
		  disorder.c \
		  operation_swap.c \
		  operation_push.c \
		  operation_rotate.c \
		  print_bench.c \
		  stubs.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
