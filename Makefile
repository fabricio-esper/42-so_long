NAME	= so_long

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra

SRCS	= ./src/so_long.c ./src/utils.c ./src/utils2.c ./src/error.c ./src/map.c ./src/window.c

OBJS	= $(SRCS:.c=.o)

UNAME	:= $(shell uname)

ifeq ($(UNAME), Linux)
	OFLAGS	= $(CFLAGS) -L ./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX		= ./mlx_linux
else
	OFLAGS	= $(CFLAGS) -L ./mlx -lmlx -framework OpenGL -framework AppKit
	MLX		= ./mlx
endif

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./inc

$(NAME):	$(OBJS)
			make -C ./libft && make -C $(MLX)
			cc $^ $(OFLAGS) $(LIBFT) -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft && make clean -C $(MLX)

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
