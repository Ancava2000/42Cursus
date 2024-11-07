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

#Sources
#-------
NAME = so_long
CFILES = so_long.c            \
		checkers.c            \
		end_window.c          \
		errors.c              \
		frees.c               \
		generate_map_array.c  \
		generate_map_images.c \
		generate_map_game.c   \
#-------

#Utils
#-------

MLX42 = ../MLX42/build/libmlx42.a

LIBFT = libft/libft.a
#-------

#Compile
#-------
all: $(NAME)

$(NAME): $(MLX42) $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "$(CYAN_2)$(ITALIC) $(NAME) created ✓$(DEF_COLOR)"
	@echo "$(CYAN_2)$(ITALIC) $(NAME) indexed ✓$(DEF_COLOR)"

$(MLX42):
	@echo "$(HOT_PINK)$(BOLD) Compiling ...$(DEF_COLOR)"
	@make -C MLX42/build/
	@echo "$(CYAN_2)$(ITALIC) MLX42 created ✓$(DEF_COLOR)"

$(LIBFT):
	@echo "$(HOT_PINK)$(BOLD) Compiling ...$(DEF_COLOR)"
	@make -C libft
	@echo "$(CYAN_2)$(ITALIC) libft created ✓$(DEF_COLOR)"
#-------

#Cleaning
#--------
clean:
	@echo "$(DARK_CYAN)$(BOLD) Removing ${NAME} and MLX42 ...$(DEF_COLOR)"
	@rm -rf $(NAME)
	@echo "$(LIGHT_PINK)$(ITALIC) ${NAME} and MLX42 deleted :($(DEF_COLOR)"
fclean: clean
	@echo "$(DARK_GREEN)$(BOLD) Removing all libft...$(DEF_COLOR)"
	@make fclean -C libft
	@echo "$(VIOLET)$(ITALIC) all deleted D:$(DEF_COLOR)"

re: fclean all
#--------

.PHONY: all clean fclean re