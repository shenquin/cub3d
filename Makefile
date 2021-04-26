# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 14:23:23 by thgillai          #+#    #+#              #
#    Updated: 2021/04/23 13:59:23 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME =	src/main.c\
			src/parsing.c \
			src/error_handler.c \
			src/utils.c \
			src/data.c \
			src/data2.c \
			src/parsemap.c \
			src/error_handler2.c \

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= gcc -g -fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I. -I./lib/libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C lib/minilibx
		make -C lib/libft
		cp lib/minilibx/libmlx.dylib .
		${CC} -o ${NAME} ${OBJS} -L./lib/libft -lft -L. -lmlx -framework OpenGL -framework AppKit

all: 		${NAME}

clean:
			make -C lib/libft fclean
			${RM} ${OBJS} ${NAME}

fclean:		clean
			rm -f screen.bmp
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all
