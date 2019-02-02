NAME =  libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = 3.Libft/*.c srcs/*.c
OBJS = $(SRCS:.c=.o)

# $(NAME): $(OBJS)

all: # $(NAME)
		# make re -C 3.Libft
		@gcc main_test.c srcs/ft_printf.c 3.Libft/libft.a && ./a.out
		# @ar rc $(NAME) $(OBJS)
		# @ranlib $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C 3.Libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C 3.Libft

re: fclean all
