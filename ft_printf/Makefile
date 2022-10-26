SRCS	= ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:
	make -C bonus ./libft
	cp ./libft/libft.a ${NAME}

printf:	libft
	${CC} ${CFLAGS} ${SRCS} 

all:		

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
