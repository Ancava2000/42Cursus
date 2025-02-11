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
					@echo "\n$(HOT_PINK)$(BOLD) Compiling libft...$(DEF_COLOR)\n"
					@make re -C ./libft
					@echo "\n$(HOT_PINK)$(BOLD) Compiling pipex...$(DEF_COLOR)\n"
					@$(CC) ${OBJS} -Llibft -lft -o ${PROG}
					@echo "\n$(CYAN_2)$(ITALIC) Pipex created ✓$(DEF_COLOR)\n"
					@echo "\n$(CYAN_2)$(ITALIC) Pipex indexed ✓$(DEF_COLOR)$  $(HOT_PINK)ᕦ(♥_♥)ᕤ\n"

bonus:		${PROG_BONUS}

${PROG_BONUS}:	${OBJS_B}
					@echo "\n$(CYAN_2)$(BOLD) Compiling libft...$(DEF_COLOR)\n"
					@make re -C ./libft
					@echo "\n$(CYAN_2)$(BOLD) Compiling bonus...$(DEF_COLOR)\n"
					@$(CC) ${OBJS_B} -Llibft -lft -o ${PROG_BONUS}
					@echo "\n$(HOT_PINK)$(ITALIC) Bonus created ✓$(DEF_COLOR)\n"
					@echo "\n$(HOT_PINK)$(ITALIC) Bonus indexed ✓$(DEF_COLOR)  $(CYAN_2)ᕦ(♥_♥)ᕤ\n"
# -------

# Clean
# -------
clean:
					@echo "\n$(DARK_CYAN)$(BOLD) Removing .o in libft...$(DEF_COLOR)\n"
					@make clean -C ./libft
					@echo "\n$(DARK_CYAN)$(BOLD) Removing .o in pipex...$(DEF_COLOR)\n"
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@echo "\n$(DARK_CYAN)$(BOLD) Removing .a in libft...$(DEF_COLOR)\n"
					@make fclean -C ./libft
					@echo "\n$(DARK_CYAN)$(BOLD) Removing ${PROG} y ${PROG_BONUS} ...$(DEF_COLOR)"
					@rm -f $(NAME)
					@rm -f ${PROG}
					@rm -f ${PROG_BONUS}
					@echo "\n$(VIOLET)$(BOLD) Deleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

re_bonus:		fclean bonus
# -------

yipi:
					@printf "\033c"
					@echo "$(CYAN_2)ayyy er pipex♪"
					@sleep 0.8
					@printf "\033c"
					@echo "$(HOT_PINK)ole los caracoles♪"
					@sleep 0.8
					@printf "\033c"
					@echo "$(DARK_GREEN)peritaa el programa♪"
					@sleep 0.8
					@printf "\033c"
					@echo "$(VIOLET) $(BOLD)⊂(◉‿◉)つ\n"

.PHONY: all clean fclean re re_bonus bonus yipi
