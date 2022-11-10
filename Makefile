SRCS = ft_printf.c ft_char_str_num.c ft_hexa_char_num.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
C_FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

%.o: %.c ft_printf.h
	cc $(C_FLAGS) -c $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
