SRCS	=	color.c fdf.c image.c utils.c\
			coordinates.c hook.c iso.c parser.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

B_SRCS	=	color.c fdf_bonus.c image.c key_hook_bonus.c utils.c\
			coordinates.c view_bonus.c parser.c\
			rotate_bonus.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

NAME	=	fdf

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		make_libft $(NAME)

$(NAME):	$(OBJS) libft/libft.a fdf.h get_next_line/get_next_line.h
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit libft/libft.a  -o $@ $(OBJS)

bonus:		$(B_OBJS) libft/libft.a fdf_bonus.h get_next_line/get_next_line.h
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit libft/libft.a  -o fdf_bonus $(B_OBJS)

make_libft:
			@$(MAKE) -C libft/

clean:
			$(RM) $(OBJS) $(B_OBJS)
			@$(MAKE) -C libft/ clean

fclean:		clean
			$(RM) $(NAME) fdf_bonus
			@$(MAKE) -C libft/ fclean

re:			fclean all

.PHONY:		all make_libft clean fclean re bonus
