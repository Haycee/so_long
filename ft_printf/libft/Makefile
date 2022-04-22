SRCS	=	ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_atoi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_calloc.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_substr.c \
			ft_split.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_striteri.c \
			ft_memmove.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
CFLAGS	=  -Wall -Wextra -Werror

RM = rm -rf

ERASE	:=	\033[2K\r
BOLD	:=	\033[1m
redir	:=	\033[31m
GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
BOLD	:=	\033[1m
END		:=	\033[0m

all : ${NAME}

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) $<\n"

${NAME}	: ${OBJS}
	printf "$(GREEN)> All the libft.c files have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the libft archive file :$(END) $@\n"
	ar rcs ${NAME} ${OBJS}
	printf "$(GREEN)> Libft archive has been compiled successfully !$(END)\n"

bonus: all

clean :
	${RM} ${OBJS}

fclean : 	clean
	${RM} ${NAME}

re : fclean all

.PHONY: all bonus clean fclean re