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

SRCS	= philosophers.c errors.c data_init.c utils.c\
		routine.c threads.c time.c

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -pthread #-fsanitize=thread

all : ${NAME}

$(NAME) : $(OBJS)
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean re
