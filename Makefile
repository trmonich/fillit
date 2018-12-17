# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 12:30:35 by alesteph          #+#    #+#              #
#    Updated: 2018/12/17 12:30:40 by alesteph         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC= gcc

FLAGS= -Wall -Werror -Wextra

NAME= fillit

SRCS= srcs/backtrack.c \
	  srcs/bitwise.c \
	  srcs/check_tetri.c \
	  srcs/display.c \
	  srcs/pieces.c \
	  srcs/read.c \
	  srcs/main.c

INCLUDES= ./includes/

LIB= ./srcs/libft/

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@(cd ./srcs/libft/ && $(MAKE) re)
	$(GCC) $(FLAGS) -o $(NAME) -L $(LIB) -lft -I $(INCLUDES) $(OBJS)

%.o: %.c
	$(GCC) $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)
	@(cd ./srcs/libft/ && $(MAKE) clean)

fclean: clean
	rm -f $(NAME)
	@(cd ./srcs/libft/ && $(MAKE) fclean)

re: fclean all

.PHONY: clean fclean
