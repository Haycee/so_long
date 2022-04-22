# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:57:24 by agirardi          #+#    #+#              #
#    Updated: 2022/04/22 19:54:30 by agirardi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long

INC_PATH	:=	includes
SRC_PATH	:=	srcs
OBJ_PATH	:=	.objects

LST_INCS	:=	so_long.h

LST_SRCS	:=	hook.c \
				map_parser.c \
				map_render.c \
				map_render_utils.c \
				player.c \
				player_event.c \
				player_initialization.c \
				so_long.c \
				so_long_utils.c \
				sprites_initialization.c

LST_OBJS	:=	$(LST_SRCS:.c=.o)

INCS		:=	$(addprefix $(INC_PATH)/,$(LST_INCS))
SRCS		:=	$(addprefix $(SRC_PATH)/,$(LST_SRCS))
OBJS		:=	$(addprefix $(OBJ_PATH)/,$(LST_OBJS))

MLX_AR		:=	./mlx/libmlx.a

PRINTF_AR	:=	./ft_printf/libftprintf.a

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror -I mlx

RM			:=	rm -rf

ERASE		:=	\033[2K\r
BOLD		:=	\033[1m
redir		:=	\033[31m
GREEN		:=	\033[32m
BLUE		:=	\033[34m
PINK		:=	\033[35m
BOLD		:=	\033[1m
END			:=	\033[0m

all : mlx ft_printf ${NAME}


mlx:
	make -C ./mlx

ft_printf:
	make -C ./ft_printf

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS) Makefile | $(OBJ_PATH)
	${CC} ${CFLAGS} -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) $<\n"

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)


${NAME}: ${OBJS} ${PRINTF_AR}
	${CC} ${OBJS} ${PRINTF_AR} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"

bonus : all

clean:
	${RM} ${OBJ_PATH}
	make clean -C ./ft_printf
	make clean -C ./mlx
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"


fclean: clean
	${RM} ${NAME}
	printf "$(GREEN)> so_long executable file have been removed successfully !$(END)\n"
	${RM} ${PRINTF_AR}
	make fclean -C ./ft_printf
	${RM} ${MLX_AR}
	make clean -C ./mlx


re: fclean all

.PHONY: all ft_printf mlx clean fclean re

.SILENT:




















