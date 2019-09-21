# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 14:40:09 by lnkambul          #+#    #+#              #
#    Updated: 2019/07/22 11:43:34 by lnkambul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = libft.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
PESKY = libft.h.gch
OBJECTS = $(CFILES:.c=.o)
CFILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memcpy.c\
		ft_memdel.c ft_memset.c ft_putchar.c ft_putendl.c ft_putstr.c\
		ft_strcat.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
		ft_strdup.c ft_strequ.c ft_striter.c ft_strjoin.c ft_strlen.c\
		ft_strmap.c ft_strnew.c ft_strtrim.c ft_tolower.c ft_toupper.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_memccpy.c\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_striteri.c ft_strmapi.c\
		ft_strncmp.c ft_strnequ.c ft_strsub.c ft_strchr.c ft_strncpy.c\
		ft_putnbr.c ft_strncat.c ft_strlcat.c ft_putnbr_fd.c ft_strsplit.c\
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_lstnew.c ft_lstdelone.c\
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_whitespace_skipper.c\
		ft_wordcount.c get_next_line.c
RM = rm -f

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

all: $(NAME)

$(OBJECTS):
	$(CC) $(CFLAGS) -c $(CFILES) $(INCLUDE)

clean:
	$(RM) $(OBJECTS) $(PESKY)

fclean:
	$(RM) $(OBJECTS) $(NAME) $(PESKY)

re: fclean all
