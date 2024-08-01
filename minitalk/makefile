# Sources
# -------
NAME = minitalk

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT = client
SERVER = server

# Colors
# ------
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =           \033[0;91m
GREEN =         \033[0;92m
YELLOW =        \033[0;93m
BLUE =          \033[0;94m
MAGENTA =       \033[0;95m
CYAN =          \033[0;96m
CYAN_2 =        \033[38;5;50m
DARK_CYAN =     \033[38;5;36m
WHITE =         \033[0;97m
BLACK =         \033[0;99m
ORANGE =        \033[38;5;209m
BROWN =         \033[38;2;184;143;29m
DARK_GRAY =     \033[38;5;234m
MID_GRAY =      \033[38;5;245m
DARK_GREEN =    \033[38;5;22m
DARK_YELLOW =   \033[38;5;143m
HOT_PINK =      \033[38;5;169m
TURQUOISE =     \033[38;5;45m
LIGHT_PINK =    \033[38;5;218m
VIOLET =        \033[38;5;134m
# -------

all: ${NAME}

${SERVER} : ${SERVER}.c minitalk.h
	@echo "$(HOT_PINK)$(BOLD)Make all. Compiling the server.$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o ${SERVER} ${SERVER}.c
	@echo "$(DARK_GREEN)$(ITALIC) [OK✓]$(DEF_COLOR)"

${CLIENT} : ${CLIENT}.c minitalk.h
	@echo "$(TURQUOISE)$(BOLD)Compiling the client.$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o ${CLIENT} ${CLIENT}.c
	@echo "$(DARK_GREEN)$(ITALIC) [Success!]$(DEF_COLOR)"

$(NAME): ${SERVER} ${CLIENT}

clean:
	@echo "$(HOT_PINK)$(BOLD)Removing .o  ...$(DEF_COLOR)"
	@${RM} ${CLIENT} ${SERVER}
	@echo "$(LIGHT_PINK)$(ITALIC) Finished$(DEF_COLOR)"

fclean: clean
	@echo "$(LIGHT_PINK)$(BOLD)Removing all  ...$(DEF_COLOR)"
	@${RM} $(CLIENT) $(SERVER)
	@echo "$(LIGHT_PINK)$(ITALIC) Finished$(DEF_COLOR)"

re: fclean all

.PHONY : all clean fclean re