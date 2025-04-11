# Colors
# ------
ITALIC =		\033[3m
BOLD =			\033[1m
RESET =			\033[0m
DEF_COLOR =		\033[0;39m
CYAN_2 =        \033[38;5;50m
DARK_CYAN =     \033[38;5;36m
DARK_GREEN =    \033[38;5;22m
HOT_PINK =      \033[38;5;169m
LIGHT_PINK =    \033[38;5;218m
VIOLET =        \033[38;5;134m
# -------

# Name of executable
# ----- 
NAME = philo
# -----

# Utils
# -----
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -pthread
HEADER = include/philo.h
# -----

# Sources
# -----
SRC = main.c init_data.c dinner.c forks.c waiter.c utils_str.c utils_simulation.c
SRC_DIR = src
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# -----

# Compile
# -----
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
				@$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJ)
				@echo "$(HOT_PINK)"
				@sleep 0.1
				@echo "██████╗ ██╗███╗   ██╗███╗   ██╗███████╗██████╗     ██████╗ ███████╗ █████╗ ██████╗ ██╗   ██╗██╗"
				@sleep 0.1
				@echo "██╔══██╗██║████╗  ██║████╗  ██║██╔════╝██╔══██╗    ██╔══██╗██╔════╝██╔══██╗██╔══██╗╚██╗ ██╔╝██║"
				@sleep 0.1
				@echo "██║  ██║██║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝    ██████╔╝█████╗  ███████║██║  ██║ ╚████╔╝ ██║"
				@sleep 0.1
				@echo "██║  ██║██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗    ██╔══██╗██╔══╝  ██╔══██║██║  ██║  ╚██╔╝  ╚═╝"
				@sleep 0.1
				@echo "██████╔╝██║██║ ╚████║██║ ╚████║███████╗██║  ██║    ██║  ██║███████╗██║  ██║██████╔╝   ██║   ██╗"
				@sleep 0.1
				@echo "╚═════╝ ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝    ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝   ╚═╝"
				@sleep 0.1
				@echo
				@sleep 0.1
				@echo "					$(LIGHT_PINK)🍝 Prepare to EAT! 🍝$(RESET)"
				@sleep 0.1
                                                                                               


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
				@$(CC) -c $< -o $@
$(OBJ_DIR):
				@echo "$(CYAN_2)$(ITALIC) objects created ✓$(DEF_COLOR)"
				@mkdir -p $(OBJ_DIR)
# -----

# Clean
# -----
clean:
	@echo "$(DARK_CYAN)$(BOLD) Removing plates  ...$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(DARK_GREEN)$(BOLD) Removing diners...$(DEF_COLOR)"
	@rm -rf $(NAME)
	@echo "$(VIOLET)$(ITALIC) the restaurant is closed D:$(DEF_COLOR)"
# -----

# Re-compile
# -----
re: fclean all
# -----

.PHONY: all clean fclean re
