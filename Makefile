# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:09:37 by lbuccher          #+#    #+#              #
#    Updated: 2021/10/05 11:11:10 by lbuccher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRCS = ft_printf.c 

OBJ = ${SRCS:.c=.o}

INCLUDE = ft_printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ}
	ar rc $(NAME) $(OBJ)

bonus:		${OBJ}
	ar rc $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
