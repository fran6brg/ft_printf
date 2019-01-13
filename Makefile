NAME =  libftprintf.a
CC = gcc
CFLAGS = Wall -Wextra -Werror
SRCS = *.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)

all: $(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all
