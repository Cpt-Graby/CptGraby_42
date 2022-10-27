SRCS	= ft_printf.c

NAME	= libftprintf.a

TMP		= libft_tmp.a

CC		= gcc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:
	make -C bonus ./libft
	cp ./libft/libft.a ${NAME}

${NAME}:	${OBJS} libft
	${AR} ${NAME} ${OBJS} ${TMP}
	ranlib ${NAME}

all: ${NAME}

clean:		
	rm ${TMP}
	make -C fclean ./libft
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
