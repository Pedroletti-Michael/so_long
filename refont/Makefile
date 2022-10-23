NAME = so_long

CFLAGS = -Wall -Wextra -Werror

MAKELIBFT = ${MAKE} -C ./libft

MAKEPRINTF = ${MAKE} -C ./42-printf

MAKEMLX = ${MAKE} -C ./mlx

SRCS = 	src/so_long.c			\
		src/error_handler.c		\
		src/start.c				\
		src/utils.c				\
		src/move.c				\
		src/check.c				\
		src/hooks.c				\
		src/print_map.c			\
		src/print_map_utils.c	\
		src/init_map.c			\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	@echo Compiling $<
	gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			$(MAKEMLX)
			$(MAKELIBFT)
			$(MAKEPRINTF)
			gcc $(CFLAGS) -I./ -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) libft/libft.a 42-printf/libftprintf.a -o $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKEMLX) clean
	$(MAKELIBFT) clean
	$(MAKEPRINTF) clean

fclean:
	$(MAKEMLX) fclean
	$(MAKELIBFT) fclean
	$(MAKEPRINTF) fclean
	rm -f $(NAME)

re: fclean all

out:
	gcc $(CFLAGS) $(SRCS)

.PHONY: all clean fclean re
