SRCS    = main.c merge_sort.c swap_commands.c utils.c simple_sort.c smart_shift.c
OBJS    = ${SRCS:.c=.o}
INCS    = includes
NAME    = push_swap
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

DEF_COLOR = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;91m
CIANO = \033[0;36m

.SILENT:
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}: ${OBJS}
	make all -C libft
	cp libft/libft.a ../${NAME}
	gcc ${CFLAGS} -o ${NAME} ${OBJS} libft.a
	echo "${GREEN}OK"

all: ${NAME}

debug: ${OBJS}
	make all -C libft
	cp libft/libft.a ../${NAME}
	gcc ${CFLAGS} -o ${NAME} ${OBJS} libft.a
	echo "${DEF_COLOR}DEBUG READY"

clean:
	${RM} -f ${OBJS} libft.a
	make clean -C libft
	echo "${CIANO}Pulito"

fclean: clean
	${RM} -f ${NAME}
	make fclean -C libft
	echo "${CIANO}Pulito Tutto"

re: fclean all
