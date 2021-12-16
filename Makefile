SRCS=	main.c	board_check.c

INCS=	so_long.h
OBJS= ${SRCS:.c=.o}

MAKELIBFT=	${MAKE} -C ./libft

MAKEMLX=	${MAKE} -C ./mlx

MAKEPRINTF= ${MAKE} -C ./ft_printf

CFLAGS= -Wall -Wextra -Werror
NAME= so_long

all: 		$(NAME)

.c.o:
			@echo Compiling $<
			gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${MAKEMLX}
			${MAKELIBFT}
			gcc ${CFLAGS} -I./ -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) libftprintf.a -o $(NAME)

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
