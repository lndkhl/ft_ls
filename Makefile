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

FLAGS	= -Wall -Werror -Wextra
CC	= gcc

NAME	= ft_ls
IDIR	= ./includes/
BDIR	= ./build/
SDIR	= ./sources/
LDIR	= ./libft/
LBFT	= ./libft/libft.a
SRCS	= $(shell ls $(SDIR) | grep -E ".+\.c")
SRCE	= $(addprefix $(SDIR), $(SRCS))
OBJS	= $(addprefix $(BDIR), $(SRCS:.c=.o))

.DELETE_ON_ERROR:
all: $(BDIR) $(LIBFT) $(NAME)

$(BDIR):
	@echo "making $(NAME)"
	@mkdir $(BDIR)

$(BDIR)%.o: $(SDIR)%.c
	@$(CC) $(CFLAGS) -I $(IDIR) -o $@ -c $<

$(LBFT):
	@make -C $(LDIR)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -L $(LDIR) $(LBFT) -o $(NAME)
	@echo "made $(NAME)"

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all fclean clean re
