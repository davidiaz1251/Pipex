NAME = pipex

SOURCE = main.c

OBJECT = $(SOURCE:.c=.o)

CFLAGS =  -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re