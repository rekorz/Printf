# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egallego <egallego@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 17:27:00 by egallego          #+#    #+#              #
#    Updated: 2021/03/18 17:27:13 by egallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_uitoa.c ft_atoi.c ft_flags.c convers.c ft_itoa.c ft_strdup.c ft_strlen.c ifunsigned_utils.c\
ft_utoi.c ifchar.c ifhex_cap.c ifhex.c ifinteger.c ifint_utils.c ifpercentage.c ifpointer.c ifstring.c ifunsigned.c restart.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

RM		=	rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
