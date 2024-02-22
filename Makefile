NAME = pipex

SOURCE = 	main.c		\
			path.c		\
			error.c		\
			access.c	\
			free_matrix.c

SOURCEB = 	bonus/main_bonus.c		\
			bonus/path_bonus.c		\
			bonus/error_bonus.c		\
			bonus/access_bonus.c		\
			bonus/free_matrix_bonus.c


OBJECT = $(SOURCE:.c=.o)

OBJECTB = $(SOURCEB:.c=.o)

LIBFT = Libft/libft.a

CFLAGS =  -Wextra -Werror -Wall -g3

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFT)
	@$(CC) $(OBJECT) -LLibft -lft -o $(NAME)

bonus:	$(OBJECTB) $(LIBFT)
	@$(CC) $(OBJECTB) -LLibft -lft -o bonus/$(NAME)

$(LIBFT): 
	@make bonus -C Libft/

clean:
	@rm -f $(OBJECT)
	@rm -f $(OBJECTB)
	@make clean -C Libft/


fclean: clean
	@rm -f $(NAME)
	@rm -f bonus/$(NAME)
	@make fclean -C Libft/

re: fclean all

git:
	@read -p "Archivo [./main.c]: " answer; \
	git add "$$answer"
	git status
	@read -p "Quieres continuar? [y/n]: " answer; \
	if [ "$$answer" = "y" ]; then \
		read -p "Mensaje para el commit: " message; \
		git commit -m "$$message"; \
		git push; \
	fi 

.PHONY: all clean fclean re bonus