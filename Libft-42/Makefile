# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absaid <absaid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 07:27:30 by absaid            #+#    #+#              #
#    Updated: 2023/02/15 15:58:38 by absaid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c \
 ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_split.c \
 ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c \
  gc.c get_next_line.c get_next_line_utils.c ft_putchar_fd.c ft_strncmp.c

BONUS = ft_lstadd_front.c ft_lstnew.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c \
 ft_lstiter.c ft_lstclear.c ft_lstdelone.c


BONUSOBJS = $(BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

all:$(NAME)

%.o:%.c libft.h
	$(CC) $(CFLAGS) -c $<

bonus : $(BONUSOBJS) $(NAME)
	ar cr $(NAME) $(BONUSOBJS) 	

$(NAME):$(OBJS)
	ar cr $(NAME) $(OBJS)


clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all