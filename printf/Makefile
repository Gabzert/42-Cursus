# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfantech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 11:21:35 by gfantech          #+#    #+#              #
#    Updated: 2022/10/14 17:38:59 by gfantech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS    =  ft_printf.c ft_printhex.c ft_printchr.c ft_printmem.c ft_printnum.c ft_printstr.c
OBJS    = ${SRCS:.c=.o}
INCS    = includes
NAME    = libftprintf.a
LIBC    = ar rc
LIBR    = ranlib
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS} -L. -lftprintf -lft

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
              
