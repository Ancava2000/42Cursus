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
# -------

# Sources
# -------
NAME = push_swap
SRCS_1 = push_swap.c\

SRCS_2 = addnodes.c\
		apply_cases.c\
		cases_cost_ab.c\
		cases_cost_ba.c\
		error_checkers.c\
		find_rotate_case.c\
		free_all.c\
		operations_1.c\
		operations_2.c\
		operations_3.c\
		sort_all.c\
		sort_three.c\
		utils_1.c\
		utils_2.c\

BONUS = checker
BONUS_SRCS = checker_bonus.c\
# -------

# Utils
# -------
LIBFTDIR = ./libft/
INCLUDE = -L ./libft/ -lft

OBJS_1 = ${SRCS_1:.c=.o}
OBJS_2 = ${SRCS_2:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o} 


CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# -------

# Compile
# -------
all: ${NAME} ${BONUS}
bonus: ${BONUS}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS_1} ${OBJS_2}
	@echo "$(HOT_PINK)$(BOLD) Compiling ...$(DEF_COLOR)"
	@make -C $(LIBFTDIR)
	@echo "$(CYAN_2)$(ITALIC) libft created ✓$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${OBJS_1} ${OBJS_2} -o ${NAME} ${INCLUDE}
	@echo "$(CYAN_2)$(ITALIC) $(NAME) created ✓$(DEF_COLOR)"
	@echo "$(CYAN_2)$(ITALIC) $(NAME) indexed ✓$(DEF_COLOR)"

${BONUS} : ${OBJS_2} ${BONUS_OBJS}
	@echo "$(HOT_PINK)$(BOLD) Compiling bonus...$(DEF_COLOR)"
	@make -C $(LIBFTDIR)
	@echo "$(CYAN_2)$(ITALIC) libft created ✓$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${BONUS_OBJS} ${OBJS_2} -o ${BONUS} ${INCLUDE}
	@echo "$(CYAN_2)$(ITALIC) $(BONUS) created ✓$(DEF_COLOR)"
	@echo "$(CYAN_2)$(ITALIC) $(BONUS) indexed ✓$(DEF_COLOR)"

# -------

# Clean
# -------
clean:
	@echo "$(DARK_CYAN)$(BOLD) Removing .o  ...$(DEF_COLOR)"
	@${RM} ${OBJS_1} ${OBJS_2} ${BONUS_OBJS}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "$(LIGHT_PINK)$(ITALIC) Libft OBJS deleted :($(DEF_COLOR)"
	@echo "$(LIGHT_PINK)$(ITALIC) OBJS deleted :($(DEF_COLOR)"

fclean: clean
	@echo "$(DARK_GREEN)$(BOLD) Removing push swap and checker...$(DEF_COLOR)"
	@${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "$(DARK_GREEN)$(BOLD) Removing libft...$(DEF_COLOR)"
	@echo "$(VIOLET)$(ITALIC) all deleted D:$(DEF_COLOR)"

re: fclean all

.PHONY : all clean fclean re bonus