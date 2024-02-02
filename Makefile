NAME = pipex

SOURCE = main.c

OBJECT = $(SOURCE:.c=.o)

CFLAGS =  -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -LLibft -lft -o $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)
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

.PHONY: all clean fclean re