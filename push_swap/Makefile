#####################
# GENERIC VARIABLES #
#####################

NAME    = push_swap
INCS    = includes
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
OBJDIR  = obj/
SRCDIR  = 
B_DIR	= checker_src/

#########
# FILES #
#########

SRCS    = main.c merge_sort.c swap_commands.c utils.c simple_sort.c smart_shift.c groups.c group_utils.c

OBJS    = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

B_SRCS  = checker.c commands.c extra.c cmd_utils.c

B_FILES = 

B_OBJS  = $(addprefix $(OBJDIR),$(B_SRCS:.c=.o))

##########
# COLORS #
##########

DEF_COLOR = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;91m
CIANO = \033[0;36m

.SILENT:

all: ${NAME}

${OBJDIR}%.o: ${SRCDIR}%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

${OBJDIR}%.o: ${B_DIR}%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	make all -C libft
	cp libft/libft.a ${CURDIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
	${RM} -f libft.a
	echo "${GREEN}OK"


#debug: ${OBJS}
#	make all -C libft
#	gcc ${CFLAGS} -o ${NAME} ${OBJS} libft.a
#	echo "${DEF_COLOR}DEBUG READY"

bonus: ${B_OBJS}
	make all -C libft
	cp libft/libft.a ${CURDIR}
	${CC} ${CFLAGS} -o checker ${B_OBJS} libft.a
	${RM} -f libft.a

clean:
	${RM} -rf ${OBJDIR}
	make clean -C libft
	echo "${CIANO}Pulito"

fclean: clean
	${RM} -f ${NAME}
	make fclean -C libft
	${RM} -f checker
	echo "${CIANO}Tutto"

re: fclean all
