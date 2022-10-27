SRCS	= ft_printf.c

NAME	= libftprintf.a

TMP	= tmp.a

CC	= gcc

RM	= rm -f

AR	= ar rc

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} 
	echo ${TMP}
	${MAKE} bonus -C ./libft 
	cp ./libft/libft.a ${TMP}
	${AR} ${NAME} ${OBJS} ${TMP}
	ranlib ${NAME}

all: 	${NAME}

clean:		
	${RM} ${TMP}
	make fclean -C ./libft
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
