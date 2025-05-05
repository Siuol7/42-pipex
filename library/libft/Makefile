# Source files
SRCS	=	./ft_isalpha.c		./ft_isdigit.c		./ft_isalnum.c		./ft_isascii.c	\
			./ft_isprint.c		./ft_strlen.c		./ft_memset.c		./ft_bzero.c	\
			./ft_memcpy.c 		./ft_memmove.c		./ft_strlcpy.c		./ft_strlcat.c	\
			./ft_toupper.c		./ft_tolower.c		./ft_strchr.c		./ft_strrchr.c 	\
			./ft_strncmp.c		./ft_strnstr.c		./ft_memchr.c		./ft_memcmp.c 	\
			./ft_atoi.c			./ft_calloc.c		./ft_strdup.c		./ft_substr.c	\
			./ft_strjoin.c		./ft_strtrim.c		./ft_itoa.c			./ft_split.c\
			./ft_strmapi.c		./ft_striteri.c		./ft_strnenv.c		./ft_strcmp.c\
			./ft_strichr.c		./ft_free_2d.c		./ft_strnstr_2d.c	./ft_char_eli.c\
			./ft_free_process_2d.c ./ft_custom_substr.c  ./ft_free_3d.c  ./ft_free_process_3d.c

SRCS_BN	=	./ft_lstnew_bonus.c		./ft_lstadd_front_bonus.c	./ft_lstsize_bonus.c	\
			./ft_lstlast_bonus.c	./ft_lstadd_back_bonus.c 	./ft_lstdelone_bonus.c 	\
			./ft_lstclear_bonus.c 	./ft_lstiter_bonus.c		./ft_lstmap_bonus.c

# Object files
OBJS	=	${SRCS:.c=.o}
OBJS_BN	=	${SRCS_BN:.c=.o}

# Library name
NAME	=	libft.a

# Default target
all	:	${NAME}

# Rule to compile source files into object files
%.o: %.c
	@cc -Wall -Wextra -Werror -c -I. $< -o $@

# Target to create the library
${NAME}	:	${OBJS}
	@ar rcs $@ $^

# Target to create the library with bonus
bonus: .bonus
.bonus: ${NAME} ${OBJS_BN}
	@ar rcs ${NAME} ${OBJS_BN}
	@touch .bonus

# Target to clean object files
clean	:
	@rm -f ${OBJS} ${OBJS_BN} .bonus

# Target to clean library and object files
fclean	: clean
	@rm -f ${NAME}

# Target to rebuild (clean and build again)
re	: fclean all

# Ensure that 'clean', 'fclean', and 're' are not dependent on actual file names
.PHONY: all clean fclean re bonus
