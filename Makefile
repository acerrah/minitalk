SRC = 		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c\
			ft_strlen.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_calloc.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_itoa.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_split.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_striteri.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRCS = ${addprefix ./utils/libft/,${SRC}} \
		utils/srcb/ft_check_arg.c \
		utils/srcb/ft_convert_to_hexa.c \
		utils/srcb/ft_flag_check.c \
		utils/srcb/ft_flag_check2.c \
		utils/srcb/ft_len.c \
		utils/srcb/ft_printf_bonus.c \
		utils/srcb/ft_print_start.c \
		utils/srcb/ft_print_star2.c \
		utils/srcb/ft_reset.c \
		utils/srcb/ft_print_hex.c \
		utils/srcb/ft_print_dec.c \
		utils/srcb/ft_print_dec_2.c \
		utils/srcb/ft_print_unsigned.c \
		utils/srcb/ft_print_unsigned_2.c \
		utils/srcb/ft_print_string.c \
		utils/srcb/ft_print_char.c

OBJS = ${SRCS:.c=.o}
NAME = utils.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBC = ar -rcs
SERVER = server
CLIENT = client

all: ${NAME} ${SERVER} ${CLIENT}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

${SERVER}: ${NAME} server.c
	@${CC} ${CFLAGS} -o ${SERVER} server.c ${NAME}

${CLIENT}: ${NAME} client.c
	@${CC} ${CFLAGS} -o ${CLIENT} client.c ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@${RM} ${NAME} ${SERVER} ${CLIENT}

re: fclean all
	./server

.PHONY: all clean fclean re .c.o
