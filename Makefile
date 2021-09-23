# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 14:23:23 by thgillai          #+#    #+#              #
#    Updated: 2021/09/23 16:49:49 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME =	src/main/main.c\
			src/parsing/parsing.c \
			src/utils/error_handler.c \
			src/utils/utils.c \
			src/parsing/data.c \
			src/parsing/data2.c \
			src/parsing/parsemap.c \
			src/utils/error_handler2.c \
			src/ingame/window.c \
			src/ingame/keyboard.c \
			src/ingame/keyboard2.c \

SRCS		= ${SRCNAME}

OBJS		= ${SRCS:.c=.o}

NAME		= cub3d

CC			= gcc -g -fsanitize=address
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I -I./lib/libft

CGREEN		= \033[38;2;0;153;0m
CRED		= \033[0;31m
CYELLOW		= \033[0;33m
CGREY		= \033[38;2;128;128;128m
CEND		= \033[0m


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@echo
		@echo "$(CYELLOW)Compilation of Libft and minilibx$(CEND)"
		@echo "$(CGREY)"
		make -C ./lib/minilibx
		make -C ./lib/libft
		cp lib/minilibx/libmlx.dylib .
		@echo
		${CC} -o ${NAME} ${OBJS} -L./lib/libft -lft -L. -lmlx -framework OpenGL -framework AppKit
		@echo "$(CEND)"
		@echo "$(CGREEN)Compilation done !$(CEND)"
		@echo

all:		${NAME}

clean:
		@echo
		@echo "$(CYELLOW)Deleting .o files$(CEND)"
		@echo "$(CGREY)"
		make -C ./lib/libft clean
		${RM} ${OBJS}
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

fclean:		clean
		@echo "$(CYELLOW)Deleting libft.a and cub3d$(CEND)"
		@echo "$(CGREY)"
		${RM} ${NAME} ./lib/libft/libft.a
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

re: 		fclean all

c: 			all clean

.PHONY: 	clean fclean all re