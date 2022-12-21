#####################
# GENERIC VARIABLES #
#####################

NAME    = push_swap
INCS    = includes
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
OBJDIR  = obj

#########
# FILES #
#########

SRCS    = main.c merge_sort.c swap_commands.c utils.c simple_sort.c smart_shift.c groups.c group_utils.c

OBJS    = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

##########
# COLORS #
##########

DEF_COLOR = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;91m
CIANO = \033[0;36m

.SILENT:

all: ${NAME}

${OBJDIR}/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}


${NAME}: ${OBJS}
	make all -C libft
	cp libft/libft.a ${CURDIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
	${RM} -f libft.a
	echo "${GREEN}OK"


debug: ${OBJS}
	make all -C libft
	cp libft/libft.a ../${NAME}
	gcc ${CFLAGS} -o ${NAME} ${OBJS} libft.a
	echo "${DEF_COLOR}DEBUG READY"

bonus: ${OBJ_BONUS}
	make all -C checker_src
	mv checker_src/checker ${CURDIR}

clean:
	${RM} -rf ${OBJDIR}
	make clean -C libft
	make clean -C checker_src
	echo "${CIANO}Pulito"

fclean: clean
	${RM} -f ${NAME}
	make fclean -C libft
	${RM} -f checker
	echo "${CIANO}Tutto"

re: fclean all
