NAME    = checker
INCS    = includes
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
OBJDIR  = obj

SRCS    = checker.c commands.c extra.c

OBJS    = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

.SILENT:

all: ${NAME}

${OBJDIR}/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	make all -C ../libft
	cp ../libft/libft.a ../checker_src
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
	rm libft.a
	
debug: ${OBJS}
	make all -C ../libft
	cp ../libft/libft.a ../checker_src
	${CC} ${CFLAGS} -g -o ${NAME} ${OBJS} libft.a
	rm libft.a
	echo "${DEF_COLOR}DEBUG READY"

clean:
	${RM} -rf ${OBJDIR} libft.a

re: clean all
