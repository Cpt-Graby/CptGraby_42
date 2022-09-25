SRCS	=  ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c	\
	   ft_incharset.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_isspace.c \
	   ft_itoa.c \
	   ft_strlen.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_putendl_fd.c \
	   ft_putchar_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcpy.c \
	   ft_memcmp.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_nbrlen.c \
	   ft_strchr.c	\
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_substr.c \
	   ft_strtrim.c

FILE	= t_itoa.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}
			

all:		${NAME}
			${CC} ${CFLAGS} ${FILE} -L. -lft
			./a.out | cat -e
			rm a.out

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
