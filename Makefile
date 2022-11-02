SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a;


%.o: %.c ft_printf.h
	ccc -c %<

$NAME : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re : fclean all