SRCS	= ft_printf.c \
		  ft_transfert.c

NAME	= libftprintf.a

CC	= gcc

RM	= rm -f

AR	= ar rc

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} 
	${MAKE} bonus -C ./libft 
	cp ./libft/libft.a ${NAME}
	${AR} ${NAME} ${OBJS} 
	ranlib ${NAME}

all: 	${NAME}

clean:		
	${RM} ${TMP}
	make fclean -C ./libft
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

test: all
	${CC} ${CFLAGS} print_test.c ft_printf.h  -L. -lftprintf
	./a.out
	rm a.out

.PHONY:		all clean fclean re
