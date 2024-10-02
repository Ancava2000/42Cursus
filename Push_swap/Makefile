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
SRCS =  push_swap.c\
		addnodes.c\
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

LIBFTDIR = ./libft/
OBJS = ${SRCS:.c=.o}
INCLUDE = -L ./libft/ -lft

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

${NAME} : ${OBJS}
	@echo "$(HOT_PINK)$(BOLD) Compiling ...$(DEF_COLOR)"
	@make -C $(LIBFTDIR)
	@echo "$(CYAN_2)$(ITALIC) libft created ✓$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INCLUDE}
	@echo "$(CYAN_2)$(ITALIC) $(NAME) created ✓$(DEF_COLOR)"
	@echo "$(CYAN_2)$(ITALIC) $(NAME) indexed ✓$(DEF_COLOR)"

%.o: %.c push_swap.h
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "$(DARK_CYAN)$(BOLD) Removing .o  ...$(DEF_COLOR)"
	@${RM} ${OBJS}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "$(LIGHT_PINK)$(ITALIC) Libft OBJS deleted :($(DEF_COLOR)"
	@echo "$(LIGHT_PINK)$(ITALIC) OBJS deleted :($(DEF_COLOR)"

fclean: clean
	@echo "$(DARK_GREEN)$(BOLD) Removing push swap...$(DEF_COLOR)"
	@${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "$(DARK_GREEN)$(BOLD) Removing libft...$(DEF_COLOR)"
	@echo "$(VIOLET)$(ITALIC) all deleted D:$(DEF_COLOR)"

re: fclean all

.PHONY : all clean fclean re