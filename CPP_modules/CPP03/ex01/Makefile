#####################
# GENERIC VARIABLES #
#####################

NAME    = ClapTraps
INCS    = includes
CC      = g++
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -std=c++98
OBJDIR  = obj/
SRCDIR  =
B_DIR	=

#########
# FILES #
#########

SRCS    = $(wildcard *.cpp)

OBJS    = $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))

B_SRCS  =

B_FILES = 

B_OBJS  = $(addprefix $(OBJDIR),$(B_SRCS:.cpp=.o))

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

${OBJDIR}%.o: ${B_DIR}%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME} 
	echo "${GREEN}OK"
#-fsanitize=thread -O1

debug: ${OBJS}
	${CC} ${CFLAGS} -g -o ${NAME} ${OBJS}
	echo "${DEF_COLOR}DEBUG READY"

bonus: ${B_OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${B_OBJS}

clean:
	${RM} -rf ${OBJDIR}
	echo "${CIANO}Pulito"

fclean: clean
	${RM} -f ${NAME}
	echo "${CIANO}Tutto"

re: fclean all
