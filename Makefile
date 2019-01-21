CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft/includes -Iincludes -c
NAME = libftprintf.a
SRC = ft_printf.c
OBJ = ft_printf.o
INCLUDES = printf.h

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -L libft/ -lft $(CLFAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean $(NAME)
