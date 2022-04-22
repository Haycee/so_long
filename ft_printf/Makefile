SRCS		:=	ft_printf.c \
				utils.c

LIBFT_AR	:= ./libft/libft.a

OBJS		:= ${SRCS:.c=.o}

NAME		:= libftprintf.a

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

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

%.o: %.c ft_printf.h libft./libft.h
	${CC} ${FLAGS} -o $@ -c $<
	printf "$(BLUE)> Compiling :$(END) libft/$<\n"

${NAME}	: libft ${OBJS} 
	cp ./libft/libft.a ${NAME}
	printf "$(GREEN)> All the printf.c files have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the Printflibft archive file :$(END) $@\n"
	ar -crs ${NAME} ${OBJS}
	printf "$(GREEN)> Printflibft archive has been compiled successfully !$(END)\n"

clean :
	${RM} ${OBJS}
	make clean -C ./libft

fclean : clean
	${RM} ${NAME}
	make fclean -C ./libft

re : fclean all

.PHONY: all clean libft fclean re
