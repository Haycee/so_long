# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:57:24 by agirardi          #+#    #+#              #
#    Updated: 2022/01/04 06:07:59 by alex             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INCS		=	./includes/so_long.h
	
SRCS		=	./srcs/hook.c \
				./srcs/player.c \
				./srcs/so_long.c \
				./srcs/map_parser.c \
				./srcs/map_render.c \
				./srcs/player_event.c \
				./srcs/so_long_utils.c \
				./srcs/initialization.c \
				./srcs/map_render_utils.c

LIBFT_AR	=	./libft/libft.a

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I mlx

RM			=	rm -rf

all : mlx libft ${NAME}

libft:
	@make -C ./libft --no-print-directory

mlx:
	@make -C ./mlx --no-print-directory

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -I mlx -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_AR}
	${CC} ${OBJS} ${LIBFT_AR} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${LIBFT_AR}
	${RM} ${NAME}
	make -C mlx clean

re: fclean all

.PHONY: all libft mlx clean fclean re
