#####################
# GENERIC VARIABLES #
#####################

NAME    = fdf
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

SRCS    = main.c window_utils.c key_utils.c graphic_utils.c \
	rotation_sphere.c sphere_keys.c color_utils.c free.c utils.c utils_2.c

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
	${RM} -f libft.a
	${RM} -f libmlx_Linux.a
	echo "${GREEN}OK"

clean:
	${RM} -rf ${OBJDIR}
	make clean -C libft
	echo "${CIANO}Pulito"

fclean: clean
	${RM} -f ${NAME}
	make fclean -C libft
	echo "${CIANO}Tutto"

re: fclean all
