NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast

SRCS = ft_sort.c lis.c main.c parser.c push.c \
		rotate.c rrotate.c sort_3.c sort_5.c swap.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

Libft-42/libft.a:
	make bonus -C lib-ft

%.o:%.c push_swap.h Libft-42/libft.h 
	$(CC) $(CFLAGS) -c $<

$(NAME):$(OBJS) Libft-42/libft.a
	$(CC) $(CFLAGS) $(OBJS)  Libft-42/libft.a -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUSOBJS)
	make clean -C Libft-42

fclean: clean 
	rm -f $(NAME)
	make fclean -C Libft-42

re: fclean all 

.PHONY: clean fclean re all