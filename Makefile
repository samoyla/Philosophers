# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masamoil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 17:44:31 by masamoil          #+#    #+#              #
#    Updated: 2022/05/09 17:46:54 by masamoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS	= philosophers.c errors.c init.c utils.c

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -pthread #-fsanitize=thread

all : ${NAME}

$(NAME) : $(OBJS)
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -o $@ -c $<

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean re
