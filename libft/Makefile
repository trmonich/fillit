# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trmonich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:34:09 by trmonich          #+#    #+#              #
#    Updated: 2018/12/07 12:35:58 by alesteph         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 
SRCS = ft_bzero.c \
	ft_memccpy.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstlen.c \
	ft_lstiter.c \
	ft_list_at.c \
	ft_lstmap.c \
	ft_memalloc.c \
	ft_is_prime.c \
	ft_power.c \
	ft_putnbr_base.c \
	ft_sqrt.c \
	ft_isspace.c \
	ft_iscntrl.c \
	ft_strndup.c \
	ft_lstappend.c \
	ft_lstdup.c \
	get_next_line.c \
	ft_strcapitalize.c
OBJS = $(SRCS:.c=.o)

INCLUDES = .

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

%.o : %.c
	gcc -Wall -Wextra -Werror -c $? -I $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
