NAME =		push_swap
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror 
RM =		rm -f
LIBFT =		-L./42lib -lft
SRCS =		srcs/main.c \
			srcs/push_swap_utils.c \
			srcs/push_swap_checking_input.c \
			srcs/push_swap_piles.c \
			srcs/push_swap_piles2.c \
			srcs/push_swap_piles_frame.c \
			srcs/push_swap_pile_operation.c \
			srcs/push_swap_pile_operation_double.c \
			srcs/push_swap_solve_engine.c \
			srcs/push_swap_sol_5.c \
			srcs/push_swap_sol_5_3.c

OBJS =		$(SRCS:.c=.o) 
DCFLAGS =	-g3 -fsanitize=address
ARG = "3 5 6 7 2 43 23 0   "

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

test: all
	$(CC) $(CFLAGS) $(DCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@./push_swap $(ARG)

.PHONY: all clean fclean re 
