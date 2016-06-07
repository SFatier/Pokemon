NAME    = libmy.a
SRC     = my_math.c my_stdio.c my_string.c str_process.c my_str_to_word_tab.c my_strdup.c
OBJ     = $(SRC:%.c=%.o)
RM	= rm -f
CFLAGS	= -W -Wall -Werror
LDFLAGS = -lmy

$(NAME):
		gcc -c $(SRC) $(CFLAGS)
		ar r $(NAME) $(OBJ)
		ranlib $(NAME)
all:		$(NAME)
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
