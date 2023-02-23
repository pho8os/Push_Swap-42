# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absaid <absaid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:58:04 by absaid            #+#    #+#              #
#    Updated: 2023/02/16 01:04:19 by absaid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address 

SRCS = ft_sort.c lis.c main.c parser.c push.c \
		rotate.c rrotate.c sort_3.c sort_5.c swap.c sorting_lis.c \
		push_b_utils.c

BSRCS = main_bonus.c parser.c push.c swap.c rotate.c rrotate.c ft_sort.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)


all: $(NAME)

bonus : $(NAME_B)

Libft-42/libft.a:
	make bonus -C Libft-42

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $<



$(NAME):$(OBJS) Libft-42/libft.a push_swap.h Libft-42/libft.h $(BON)
	$(CC) $(CFLAGS) $(OBJS) Libft-42/libft.a -o $(NAME)

$(NAME_B): $(BOBJS) Libft-42/libft.a push_swap.h
	$(CC) $(CFLAGS) $(BOBJS) Libft-42/libft.a -o $(NAME_B)

clean:
	rm -f $(OBJS) $(BOBJS)
	make clean -C Libft-42

fclean: clean 
	rm -f $(NAME)
	make fclean -C Libft-42
	rm -rf $(NAME_B)

re: fclean all 

.PHONY: clean fclean re all
