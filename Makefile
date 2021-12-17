# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:57:24 by agirardi          #+#    #+#              #
#    Updated: 2021/12/17 17:54:46 by agirardi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INCS		=	./includes/so_long.h \

SRCS		=	./srcs/so_long.c \
				./srcs/so_long_utils.c \
				./srcs/map_parser.c \
				./srcs/map_render.c \
				./srcs/key.c \

LIBFT_AR	=	./libft/libft.a

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I mlx

RM			=	rm -rf

all : libft ${NAME}

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

re: fclean all

.PHONY: all libft mlx clean fclean re
