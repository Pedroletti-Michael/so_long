SRCS=	src/main.c	src/board_check.c \
		src/get_next_line/get_next_line_utils.c \
		src/get_next_line/get_next_line.c

INCS=	includes/so_long.h	includes/ft_printf
OBJS= ${SRCS:.c=.o}

MAKEMLX=	${MAKE} -C ./mlx

CFLAGS= -Wall -Wextra -Werror
NAME= so_long

all: 		$(NAME)

.c.o:
			@echo Compiling $<
			gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${MAKEMLX}
			${MAKELIBFT}
			gcc ${CFLAGS} -I./ -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) libftprintf.a libft.a -o $(NAME)

bonus:		${NAME}

clean:
			@echo Cleaning out thos old .o
			${MAKEMLX} clean
			${MAKELIBFT} clean
			rm -f $(OBJS)

fclean:		clean
			@echo Cleaning out that old $(NAME)
			${MAKELIBFT} fclean
			${MAKEMLX} clean
			rm -f $(NAME)

re:			fclean $(NAME)

out:
			gcc $(CFLAGS) $(SRCS)

.PHONY:		all bonus clean fclean re
