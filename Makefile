NAME =  libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_base.c srcs/ft_padding.c srcs/ft_print_char.c srcs/ft_print_strings.c srcs/ft_printf.c srcs/ft_print_float.c srcs/ft_print_integer.c srcs/get_arguments.c srcs/ft_parsers.c srcs/ft_options.c
OBJS = $(SRCS:.c=.o)

# $(NAME): $(OBJS)

all: # $(NAME)
		@make re -C 3.Libft
		# @gcc main_test.c $(SRCS) 3.Libft/libft.a && ./a.out
		@gcc mainprintf.c $(SRCS) 3.Libft/libft.a && ./a.out 
		#@ar rc $(NAME) $(OBJS)
		#@ranlib $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C 3.Libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C 3.Libft

re: fclean all
