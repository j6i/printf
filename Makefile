CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft/includes -I includes
LFLAGS = -L libft/ -lft
NAME = printf
SRC = ft_printf.c
OBJ = $(SRC:%.c=%.o)
INCLUDES = printf.h

.PHONY: clean fclean all re norm norme debug

VPATH = src obj libft/includes includes

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) obj/* $(LFLAGS)
	@echo done

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	$(CC) -g $(CFLAGS) -o obj/$@ -c $<

clean:
	@rm -rf obj/
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
