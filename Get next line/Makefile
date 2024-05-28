NAME	=	get_next_line.a

SRC	=	get_next_line.c				\
		get_next_line.h				\
		get_next_line_utils.c		\
		get_next_line_bonus.c		\
		get_next_line_bonus.h		\
		get_next_line_utils_bonus.c	\

OBJS = $(SRC:.c=.o)

CC = cgg
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re