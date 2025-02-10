# Colors
# ------
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
CYAN_2 =        \033[38;5;50m
DARK_CYAN =     \033[38;5;36m
DARK_GREEN =    \033[38;5;22m
HOT_PINK =      \033[38;5;169m
LIGHT_PINK =    \033[38;5;218m
VIOLET =        \033[38;5;134m
# ------

# Sources
# -------
PROG		= pipex
PROG_BONUS	= pipex_bonus

SRCS 	= srcs/pipex.c srcs/utils.c
SRCS_B	= srcs/pipex_bonus.c srcs/utils_bonus.c

OBJS 	= ${SRCS:.c=.o}
OBJS_B 	= ${SRCS_B:.c=.o}

MAIN	= srcs/pipex.c
MAIN_B	= src/pipex_bonux.c
# -------

# Compilation
# -------
HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -o ${PROG}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

bonus:		${PROG_BONUS}

${PROG_BONUS}:	${OBJS_B}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS_B} -Llibft -lft -o ${PROG_BONUS}
					@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
# -------

# Clean
# -------
clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

re_bonus:	fclean bonus
# -------

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re re_bonus bonus party
