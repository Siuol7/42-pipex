#Source files
SRCS = ./ft_base_check_fd.c ./ft_print_address_fd.c ./ft_printf_format_fd.c ./ft_printf_fd.c ./ft_putchar_fd.c\
		./ft_putnbr_base_fd.c ./ft_putstr_fd.c ./ft_strdup.c ./ft_strlen.c ./ft_strjoin.c ./ft_memcpy.c

#Object files
OBJS = ${SRCS:.c=.o}

#Library name
NAME = libftprintf.a

#Default target
all :${NAME}

#Rules to compile
%.o : %.c
		@cc -Wall -Wextra -Werror -c -I. $< -o $@

#Target to create library
${NAME} : ${OBJS}
		@ar rcs $@ $^

#Target to clean
clean :
		@rm -f ${OBJS}

#Target to clean
fclean :
		@rm -rf ${NAME} ${OBJS}

#Clean and build again
re : fclean all

.PHONY : all clean fclean re