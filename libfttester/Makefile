NAME	= libft.a

CC		= gcc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra

copy:
	cd ../libft
	make
	cp libft.a ../libfttester/
	cd ../libfttest


itoa:	${copy}
	${CC} ${CFLAGS} ${FILE} -L. -lft
