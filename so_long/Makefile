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
CFILES	= so_long.c \
		generate_map_array.c \
		checkers.c \
		checkers_2.c \
		generate_map_images.c \
		generate_map_game.c \
		collectibles.c \
		moves.c \
		endscreen.c \
		enemies.c \
# -------

# Libreries compiled
# -------
LIBFT = Libft/libft.a
MLX42 = MLX42/build/libmlx42.a
# -------

# Main compilation
# -------
NAME = so_long
all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
	echo "$(HOT_PINK)$(BOLD) Compiling ...$(DEF_COLOR)"
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "$(CYAN_2)$(ITALIC) $(NAME) created ✓$(DEF_COLOR)"
	@echo "$(CYAN_2)$(ITALIC) $(NAME) indexed ✓$(DEF_COLOR)"
# -------

# Libft compilation
# -------
$(LIBFT):
	@echo "$(HOT_PINK)$(BOLD) Compiling libft...$(DEF_COLOR)"
	@make -C Libft
	@echo "$(CYAN_2)$(ITALIC) libft.a created ✓$(DEF_COLOR)"
# -------

# MLX42 compilation
# -------
$(MLX42):
	@echo "$(HOT_PINK)$(BOLD) Compiling MLX42...$(DEF_COLOR)"
	@make -C MLX42/build/
	@echo "$(CYAN_2)$(ITALIC) MLX42.a created ✓$(DEF_COLOR)"
# -------

# Clean
# -------
clean:
	@echo "$(DARK_CYAN)$(BOLD) Removing so_long and libraries...$(DEF_COLOR)"
	@rm -rf $(NAME)

fclean: clean
	@echo "$(DARK_CYAN)$(BOLD) Removing .o in libft...$(DEF_COLOR)"
	@make fclean -C Libft
	@echo "$(LIGHT_PINK)$(ITALIC) Libft OBJS deleted :($(DEF_COLOR)"
	@echo "$(VIOLET)$(ITALIC) all deleted D:$(DEF_COLOR)"

re: fclean all
# -------

.PHONY: all clean fclean re
