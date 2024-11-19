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

LIBFT = Libft/libft.a
MLX42 = MLX42/build/libmlx42.a

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(LIBFT):
	@make -C Libft

$(MLX42):
	@make -C MLX42/build/

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re
