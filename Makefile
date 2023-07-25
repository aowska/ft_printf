NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -o
SRC = ft_printf.c ft_pointerhex.c ft_hexlower.c ft_itoa.c ft_itoaun.c ft_putchar_fd.c
	
OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
