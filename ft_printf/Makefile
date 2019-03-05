NAME =  libftprintf.a
CC = gcc
CFLAGS = # -Wall -Wextra -Werror
SRCS = 3.Libft/*.c srcs/ft_base.c srcs/ft_padding_nb.c srcs/ft_padding_str.c srcs/ft_print_char.c srcs/ft_print_strings.c srcs/ft_printf.c srcs/ft_print_float.c srcs/ft_print_integer.c srcs/get_arguments.c srcs/ft_parsers.c srcs/ft_options.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) includes/

$(NAME): $(OBJS)
	  @make re -C 3.Libft
		@gcc -c $(SRCS)
		@ar rcs $(NAME) $(OBJS)
		@ranlib $(NAME)
		rm -rf *.o

kalash: # $(NAME)
		# @make re -C 3.Libft
		@gcc -g mainprintf.c $(SRCS) 3.Libft/libft.a && ./a.out
		rm -rf $(OBJS)
		#@ar rc $(NAME) $(OBJS)
		#@ranlib $(NAME)

test_unit: # $(NAME)
		@gcc -g main_test.c $(SRCS) 3.Libft/libft.a && ./a.out
		rm -rf $(OBJS)
		rm -rf *.o

lib: # $(NAME)
		@make re -C 3.Libft
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@gcc -g main_test.c $(SRCS) 3.Libft/libft.a && ./a.out

araout: # $(NAME)
		@make re -C 3.Libft
		@gcc -g main_araouteub.c $(SRCS) 3.Libft/libft.a && ./a.out

clean:
		rm -rf $(OBJS)
		make clean -C 3.Libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C 3.Libft

re: fclean all
