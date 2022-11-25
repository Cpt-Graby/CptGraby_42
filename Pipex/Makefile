NAME =		pipex
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
# -fsanitize=address
RM =		rm -f
LIBFT =		-L./42lib -lft
SRCS =		srcs/main.c \
			srcs/pipex_file_descriptor.c

OBJS =		$(SRCS:.c=.o)

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
	$(CC) $(CFLAGS) -g3 $(OBJS) $(LIBFT) -o $(NAME)
	clear

.PHONY: all clean fclean re libft test
