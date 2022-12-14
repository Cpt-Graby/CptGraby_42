NAME =		push_swap
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror 
RM =		rm -f
LIBFT =		-L./42lib -lft
SRCS =		srcs/main.c \
			srcs/push_swap_utils.c \
			srcs/push_swap_checking_input.c \
			srcs/push_swap_piles.c

OBJS =		$(SRCS:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	make -C 42lib
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	make clean -C 42lib
	

fclean: clean
	rm -f 42lib/libft.a
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
