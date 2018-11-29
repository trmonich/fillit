# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 12:57:53 by alesteph          #+#    #+#              #
#    Updated: 2018/11/29 16:20:47 by alesteph         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC= gcc

FLAGS= -Wall -Werror -Wextra

NAME= fillit

SRCS= srcs/*.c

INCLUDES= ./includes/

LIB= ./srcs/libft/

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): 
	@(cd ./srcs/libft/ && $(MAKE))
	$(GCC) $(FLAGS) -o $(NAME) -L $(LIB) -lft -I $(INCLUDES) $(SRCS)

%.o: %.c
	$(GCC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
