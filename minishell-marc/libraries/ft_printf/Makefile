# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 00:07:39 by marcfer3          #+#    #+#              #
#    Updated: 2025/06/11 01:20:54 by marcfer3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}


RM		= rm -f

GCCF = gcc -Wall -Wextra -Werror

LIB = ar -rcs

SRCS =	ft_printf.c\
		ft_putchar.c\
		ft_putchar_i.c\
		ft_puthex.c\
		ft_putnbr.c\
		ft_putptr.c\
		ft_putstr.c\
		ft_put_unsigned_nbr.c\

.c.o:
		${GCCF} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${LIB} ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

test: all
	gcc -Wall -Wextra -Werror testing.c -L. -lftprintf

