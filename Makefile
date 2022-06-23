# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masamoil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:06:21 by masamoil          #+#    #+#              #
#    Updated: 2022/06/23 16:45:51 by masamoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philosophers.c data_init.c utils.c mutex.c\
		routine.c threads.c time.c parse.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread 

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) -g

.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : clean fclean re
