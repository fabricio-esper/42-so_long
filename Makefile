NAME	= so_long.a

CFLAGS	= -Wall -Werror -Wextra

SRCS	= ./srcs/so_long.c

OBJS	= $(SRCS:.c.o)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./include

$(NAME):	$(OBJS)
			make -C ./libft
			cp ./libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re