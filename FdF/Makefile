SRCS	= srcs/main.c

NAME	= libfFdF.a

CC	= gcc

RM	= rm -f

AR	= ar rcs

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${PRINT}: ${OBJS}
	make bonus -C ./libft 
	cp ./printf/libftprintf.a 
	make fclean -C ./printf
	${AR} ${NAME} ${OBJS} 

${NAME}: ${OBJS} 
	{
all: 	${NAME}

clean:		
	make fclean -C ./libft
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

test: all
	${CC} ${CFLAGS} print_test.c  -L. -lftprintf
	./a.out
	rm a.out

.PHONY:		all clean fclean re
