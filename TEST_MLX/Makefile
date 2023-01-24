#####################
# GENERIC VARIABLES #
#####################

NAME    = test
INCS    = mlx
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -g
OBJDIR  = obj/
SRCDIR  =
B_DIR	=

#########
# FILES #
#########

SRCS    = testing.c test_utils.c

OBJS    = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

B_SRCS  = main.c utils.c pipes.c

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
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS} -03

${OBJDIR}%.o: ${B_DIR}%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	make all -C libft
	cp libft/libft.a ${CURDIR}
	cp mlx/libmlx_Linux.a ${CURDIR}
	${CC} ${CFLAGS} ${OBJS} -L${INCS} -l${INCS} -L/usr/lib -I${INCS} -lXext -lX11 -lm -lz -o ${NAME} libft.a
	#${CC} ${CFLAGS} -L${INCS} -l${INCS} -I${INCS} -lXext -lX11 -lm -lz -o ${NAME} ${OBJS} libft.a libmlx_Linux.a#
	${RM} -f libft.a
	echo "${GREEN}OK"

bonus: ${B_OBJS}
	make all -C libft
	cp libft/libft.a ${CURDIR}
	${CC} ${CFLAGS} -o ${NAME} ${B_OBJS} libft.a
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
