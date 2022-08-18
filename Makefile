NAME	= so_long

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra

OFLAGS	= -Wall -Werror -Wextra -L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRCS	= ./src/so_long.c ./src/utils.c ./src/error.c ./src/map.c ./src/window.c

OBJS	= $(SRCS:.c=.o)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./inc

$(NAME):	$(OBJS)
			make -C ./libft
			make -C ./minilibx
			cc $(OFLAGS) $^ $(LIBFT) -o $@

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
