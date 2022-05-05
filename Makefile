# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:57:24 by agirardi          #+#    #+#              #
#    Updated: 2022/05/05 17:19:08 by agirardi         ###   ########lyon.fr    #
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

CFLAGS		:=	-Wall -Wextra -Werror

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

.SILENT:

mlx:
	make -C ./mlx

ft_printf:
	make -C ./ft_printf

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS) Makefile | $(OBJ_PATH)
	${CC} ${CFLAGS} -I $(INC_PATH) -I mlx -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) $<\n"

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

${NAME}: ${OBJS} ${PRINTF_AR}
	printf "$(GREEN)> All the .c files from so_long have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	${CC} ${OBJS} ${PRINTF_AR} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

bonus : all

clean:
	${RM} ${OBJ_PATH}
	make clean -C ./ft_printf
	make clean -C ./mlx
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	${RM} ${NAME}
	${RM} ${PRINTF_AR}
	make fclean -C ./ft_printf
	${RM} ${MLX_AR}
	make clean -C ./mlx
	printf "$(GREEN)> all executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all ft_printf bonus mlx clean fclean re
