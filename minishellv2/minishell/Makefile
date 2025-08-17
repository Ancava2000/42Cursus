# Colors
# ------
ITALIC				=	\033[3m
BOLD				=	\033[1m
RESET				=	\033[0m
DEF_COLOR			=	\033[0;39m
CYAN_2				=	\033[38;5;50m
DARK_CYAN			=	\033[38;5;36m
DARK_GREEN			=	\033[38;5;22m
HOT_PINK			=	\033[38;5;169m
LIGHT_PINK			=	\033[38;5;218m
VIOLET				=	\033[38;5;134m
# -------

# Name of executable
# ----- 
NAME 				=	minishell
# -----

# Utils
# -----
CC 					=	gcc
CFLAGS 				=	-Wall -Wextra -Werror
RM 					=	rm -f
LIBFT_DIR			=	./libft/
LIBFT				=	$(LIBFT_DIR)/libft.a
INCLUDE				=	-L$(LIBFT_DIR) -lft \
							-lreadline
# -----

# Sources and Objects
# -------
SRC_BUILTINS		=	./builtins/cd_auxiliar.c \
									./builtins/mini_cd.c \
									./builtins/mini_echo.c \
									./builtins/mini_env.c \
									./builtins/mini_exit.c \
									./builtins/mini_pwd.c \
									./builtins/mini_export.c \
									./builtins/export_auxiliar.c \
									./builtins/mini_unset.c \
									./builtins/mini_external.c \
									./builtins/external_auxiliar.c \
									./builtins/external_utils.c 
SRC_ENV				=	./environment/environment.c
SRC_EXECUTOR		=	./executor/executor.c \
									./executor/redirections.c
SRC_EXPANDER		=	./expander/expander.c
SRC_FREE			=	./free/free.c \
									./free/free_mini.c
SRC_LEXER			=	./lexer/lexer.c \
									./lexer/tokenizer.c
SRC_MAIN			=	./main/minishell.c \
									./main/signals.c \
									./main/utils.c
SRC_PARSER			=	./parser/heredoc.c \
									./parser/parser_utils.c \
									./parser/parser.c

SRC					=	${SRC_BUILTINS} ${SRC_ENV} ${SRC_EXECUTOR} \
						${SRC_EXPANDER} ${SRC_FREE} ${SRC_LEXER} \
						${SRC_MAIN} ${SRC_PARSER}
OBJ					=	$(SRC:%.c=build/%.o)
OBJ_DIR				=	build

# Compile
# -------
all: 				${NAME}

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJ)
						@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $@
						@echo "$(HOT_PINK)"
						@sleep 0.1
						@echo "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
						@sleep 0.1
						@echo "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
						@sleep 0.1
						@echo "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
						@sleep 0.1
						@echo "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
						@sleep 0.1
						@echo "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
						@sleep 0.1
						@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
						@sleep 0.1
						@echo
						@echo "$(HOT_PINK)$(BOLD) Compiling ...$(DEF_COLOR)"
						@echo "$(CYAN_2)$(ITALIC) libft OBJ created ✓$(DEF_COLOR)"
						@echo "$(CYAN_2)$(ITALIC) build OBJ folder created ✓$(DEF_COLOR)"

$(LIBFT):
					@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

build/%.o: 			%.c
						@mkdir -p $(dir $@)
						@${CC} ${CFLAGS} -c $< -o $@
# -------

# Clean
# -------
clean:
					@echo "$(DARK_CYAN)$(BOLD) Removing .o  ...$(DEF_COLOR)"
					@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
					@rm -rf build
					@echo "$(LIGHT_PINK)$(ITALIC) Libft OBJS deleted :($(DEF_COLOR)"
					@echo "$(LIGHT_PINK)$(ITALIC) Build OBJS deleted :($(DEF_COLOR)"

fclean:				clean
					@echo "$(DARK_GREEN)$(BOLD) Removing minishell...$(DEF_COLOR)"
					@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
					@$(RM) $(NAME)
					@echo "$(VIOLET)$(ITALIC) all deleted D:$(DEF_COLOR)"

re:					fclean all

.PHONY:		 		all clean fclean re