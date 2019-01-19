NAME =  libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = libft/*.c srcs/*.c
OBJS = $(SRCS:.c=.o)

# $(NAME): $(OBJS)

all: # $(NAME)
		@gcc main_test.c srcs/ft_printf.c 3.Libft/libft.a && ./a.out
		# @ar rc $(NAME) $(OBJS)
		# @ranlib $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all
