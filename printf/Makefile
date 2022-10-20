# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfantech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 11:21:35 by gfantech          #+#    #+#              #
#    Updated: 2022/10/20 12:16:12 by gfantech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS    =  ft_printf.c ft_printhex.c ft_printchr.c ft_printmem.c ft_printnum.c \
	   ft_printstr.c ft_format_utils.c ft_formatter.c ft_format_initializer.c
NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a
OBJS		= $(SRCS:.c=.o)
RM			= rm -f
LIBC		= ar -rcs
FLAGS		= -Wall -Wextra -Werror
INCS		= .
COMPILER	= gcc

.c.o:
	${COMPILER} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)
    
clean:
	$(RM) -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)
    
re: fclean all

bonus: all
              
