NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -o
SRC = ft_printf.c 
SRC_BONUS = 
	
OBJS = $(SRC:.c=.o) 
OBJS_BONUS =  $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
bonus: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
