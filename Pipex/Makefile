NAME =		pipex
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
# -fsanitize=address
RM =		rm -f
LIBFT =		-L./42lib -lft
SRCS =		srcs/main.c \
			srcs/pipex_file_descriptor.c \
			srcs/pipex_get_env.c \
			srcs/pipex_cmd.c \
			srcs/pipex_utils.c \
			srcs/pipex_parsing.c

OBJS =		$(SRCS:.c=.o)

DCFLAGS =	-g3 -fsanitize=address
all: $(NAME)

$(NAME): $(OBJS)
	make -C 42lib
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C 42lib
	$(RM) $(OBJS)

fclean: clean
	rm -f 42lib/libft.a
	$(RM) $(NAME)

re: fclean all


test: $(OBJS)
	@make -C 42lib
	$(CC) $(CFLAGS) $(DCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Voici un super long text pour mettre plusieurs un" > file1
	cat file1
	./pipex file1 cat "wc -w" file2
	@echo ""
	cat file2
	@echo ""
	rm file1 file2

.PHONY: all clean fclean re libft test
