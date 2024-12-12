# Source files
SRCS = ./execution/mandatory/pipex.c ./execution/mandatory/pipex_utils.c ./execution/mandatory/pipex_exec.c\
		./execution/mandatory/main.c ./execution/mandatory/pipex_error.c ./execution/mandatory/pipex_check.c\
		./execution/mandatory/pipex_read_quote_dquote.c ./execution/mandatory/pipex_quote_dquote.c\
		./execution/mandatory/pipex_split_sh.c  ./execution/mandatory/pipex_splitting_sh.c

#Bonus files
BONUS = ./execution/bonus/pipex_bonus.c ./execution/bonus/pipex_utils_bonus.c ./execution/bonus/pipex_exec_bonus.c\
		./execution/bonus/main_bonus.c  ./execution/bonus/pipex_heredoc_bonus.c ./execution/bonus/pipex_error_bonus.c\
		./execution/bonus/pipex_check_bonus.c ./execution/bonus/pipex_read_quote_dquote_bonus.c ./execution/bonus/pipex_quote_dquote_bonus.c\
		./execution/bonus/pipex_split_sh_bonus.c  ./execution/bonus/pipex_splitting_sh_bonus.c
# Source Object files
OBJS = ${SRCS:.c=.o}

# Bonus Object files
OBJS_BN = ${BONUS:.c=.o}

# Additional library paths
LIBFT_DIR = includes/libft
FT_PRINTF_FD_DIR = includes/ft_printf_fd

# Libraries
LIBFT = ${LIBFT_DIR}/libft.a
FT_PRINTF_FD = ${FT_PRINTF_FD_DIR}/libftprintf.a

# Final executable name
NAME = pipex

# Default target
all: ${LIBFT_DIR} ${FT_PRINTF_FD_DIR} ${NAME}

# Rule to compile .o files from .c files
%.o: %.c
	cc -Wall -Wextra -Werror -c -I. $< -o $@

# Build libft.a
${LIBFT}:
	$(MAKE) -C ${LIBFT_DIR}

# Build ft_printf.a
${FT_PRINTF_FD}:
	$(MAKE) -C ${FT_PRINTF_FD_DIR}

# Create source lib
${NAME}: ${OBJS} ${LIBFT} ${FT_PRINTF_FD}
	cc ${OBJS} ${LIBFT} ${FT_PRINTF_FD} -o ${NAME}

# Create bonus lib
bonus : .bonus
.bonus : ${OBJS_BN} ${LIBFT} ${FT_PRINTF_FD}
	cc ${OBJS_BN} ${LIBFT} ${FT_PRINTF_FD} -o ${NAME}
	@touch .bonus

# Clean target
clean:
	rm -f ${OBJS} ${OBJS_BN} .bonus
	$(MAKE) -C ${LIBFT_DIR} clean
	$(MAKE) -C ${FT_PRINTF_FD_DIR} clean

# Fclean target
fclean:
	rm -rf ${NAME} ${OBJS} ${OBJS_BN}
	$(MAKE) -C ${LIBFT_DIR} fclean
	$(MAKE) -C ${FT_PRINTF_FD_DIR} fclean

# Rebuild target
re: fclean all


.PHONY: all clean fclean re
