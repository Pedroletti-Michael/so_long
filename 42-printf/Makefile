SRCS= ft_printf.c		print_hex.c		print_pointer.c		print_uint.c

INCS= ft_printf.h
OBJS= ${SRCS:.c=.o}

CFLAGS= -Wall -Wextra -Werror
NAME= libftprintf.a

all: $(NAME)

.c.o:
	@echo Compiling $<
	gcc -c $(CFLAGS) $< -o ${<:.c=.o}
	cd libft && make

$(NAME): $(OBJS)
	cp libft/libft.a ${NAME}
	ar -rcs $(NAME) $(OBJS)

re: fclean $(NAME)

clean:
	@echo Cleaning out thos old .o
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	@echo Cleaning out that old $(NAME)
	rm -f $(NAME)
	cd libft && make fclean

out:
	gcc $(CFLAGS) $(SRCS)
