NAME		:= libftprintf.a

INC_PATH	:=	includes
SRC_PATH	:=	srcs
OBJ_PATH	:=	.objects

LST_INCS	:=	ft_printf.h

LST_SRCS	:=	ft_printf.c \
				utils.c

LST_OBJS	:=	$(LST_SRCS:.c=.o)

INCS		:=	$(addprefix $(INC_PATH)/,$(LST_INCS))
SRCS		:=	$(addprefix $(SRC_PATH)/,$(LST_SRCS))
OBJS		:=	$(addprefix $(OBJ_PATH)/,$(LST_OBJS))

LIBFT_AR	:= ./libft/libft.a

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -I $(INCS)

RM			:= rm -rf

ERASE	:=	\033[2K\r
BOLD	:=	\033[1m
redir	:=	\033[31m
GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
BOLD	:=	\033[1m
END		:=	\033[0m

all	: libft ${NAME}

libft :
	make -C ./libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS) ${LIBFT_AR} Makefile | $(OBJ_PATH)
	${CC} ${FLAGS} -o $@ -c $<
	printf "$(BLUE)> Compiling :$(END) $<\n"

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

${NAME}	: ${OBJS}
	cp ./libft/libft.a ${NAME}
	printf "$(GREEN)> All the ft_printf.c files have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the Printflibft archive file :$(END) $@\n"
	ar -crs ${NAME} ${OBJS}
	printf "$(GREEN)> Libftprintf archive has been compiled successfully !$(END)\n"

clean :
	${RM} ${OBJS}
	make clean -C ./libft

fclean : clean
	${RM} ${NAME}
	make fclean -C ./libft

re : fclean all

.PHONY: all clean libft fclean re

.SILENT: