#####################
# GENERIC VARIABLES #
#####################

NAME    = estimate
INCS    = includes
CC      = g++
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -std=c++98 -lgnuplot -lm


OBJDIR  = obj/
SRCDIR  =
B_DIR	=

#########
# FILES #
#########

T_SRCS	= train.cpp

E_SRCS	= estimate.cpp

T_OBJS	= $(addprefix $(OBJDIR),$(T_SRCS:.cpp=.o))

E_OBJS	= $(addprefix $(OBJDIR),$(E_SRCS:.cpp=.o))

##########
# COLORS #
##########

DEF_COLOR = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;91m
CIANO = \033[0;36m

.SILENT:

all: ${T_OBJS} ${E_OBJS}
	${CC} ${E_OBJS} ${CFLAGS} -o ${NAME}
	${CC} ${T_OBJS} -L/path/to/gnuplot/library ${CFLAGS} -o train; 
	echo "${GREEN}Both ready"

${OBJDIR}%.o: ${SRCDIR}%.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

${NAME}: ${E_OBJS}
	${CC} ${E_OBJS} ${CFLAGS} -o ${NAME}
	echo "${GREEN}OK"
#-fsanitize=thread -O1

train: ${T_OBJS}
	${CC} ${T_OBJS} -L/path/to/gnuplot/library ${CFLAGS} -o train; 

clean:
	${RM} -rf ${OBJDIR}
	echo "${CIANO}Pulito"

fclean: clean
	${RM} -f ${NAME} train
	echo "${CIANO}Tutto"

re: fclean all
