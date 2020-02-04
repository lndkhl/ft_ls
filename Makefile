INCL = tinker.h
CC = gcc -g
FLAGS = -Wall -Werror -Wextra
NAME = ft_ls
PESKY = tinker.h.gch
LPATH = -L./libft
LIB = -lft
OBJ = $(CF:.c=.o)
CF = tinker.c main.c cleans.c inits.c prints.c flags.c helpers.c long.c sorts.c
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
