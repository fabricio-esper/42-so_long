NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra

OFLAGS = -Wall -Werror -Wextra -L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRCS	= ./so_long.c

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			make -C ./libft
			make -C ./minilibx
			cc $(OFLAGS) $^ -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft
			make clean -C ./minilibx

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re