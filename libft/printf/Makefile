# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tparadis <tparadis@student.42quebec.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:16:24 by tparadis          #+#    #+#              #
#    Updated: 2022/11/14 15:16:44 by tparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = ft_printf.c

OBJS   = ${SRCS:.c=.o}

NAME   = libftprintf.a

CC     = gcc

CFLAGS = -Wall -Wextra -Werror

all    : ${NAME}

${NAME}: ${OBJS}
				@ar -rcs  ${NAME} ${OBJS}

clean  :  
				@rm -f ${OBJS}

fclean : clean
				@rm -f ${NAME}

re     : fclean all
