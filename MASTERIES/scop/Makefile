#####################
# GENERIC VARIABLES #
#####################

NAME    = scop
INCS    = includes
CC      = g++
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -lglfw -lGL -g

OBJDIR  = obj/
SRCDIR  =
B_DIR	=

#########
# FILES #
#########

SRCS	= main.cpp loaders.cpp camera.cpp controls.cpp Matrix.cpp Vertex.cpp


OBJS	= $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))


##########
# COLORS #
##########

DEF_COLOR = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;91m
CIANO = \033[0;36m

.SILENT:

all: ${NAME}

${OBJDIR}%.o: ${SRCDIR}%.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}
	echo "${GREEN}OK"

clean:
	${RM} -rf ${OBJDIR}
	echo "${CIANO}Pulito"

fclean: clean
	${RM} -f ${NAME}
	echo "${CIANO}Tutto"

re: fclean all
