INCL = tinker.h
CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = ft_ls
PESKY = tinker.h.gch
LPATH = -L./libft
LIB = -lft
OBJ = $(CF:.c=.o)
CF = tinker.c main.c cleans.c inits.c prints.c flags.c helpers.c long.c\
	 sorts.c flags_helps.c inits_helps.c prints_helps.c sorts_helps.c\
		more_prints.c tinker_helps.c long_helps.c more_helps.c
RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LPATH) $(LIB)

all: $(OBJ) $(LIB) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LPATH) $(LIB)

$(OBJ):
	$(CC) $(FLAGS) -c $(CF) $(INCL)

$(LIB):
	cd libft/ && make fclean && make all && make clean

clean: $(NAME)
	$(RM) $(OBJ) $(PESKY)

fclean:
	$(RM) $(OBJ) $(NAME) $(PESKY)

re:
	make clean && make $(NAME)
