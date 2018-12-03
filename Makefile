# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 12:57:53 by alesteph          #+#    #+#              #
#    Updated: 2018/12/03 14:34:13 by alesteph         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC= gcc

FLAGS= -Wall -Werror -Wextra

NAME= fillit

SRCS= $(shell find srcs -maxdepth 1 -type f -name "*.c")

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
