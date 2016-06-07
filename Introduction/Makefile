##
## Makefile for  in /home/jsdurier/FDI/DEVC/Battle For Midgard
## 
## Made by DURIER Jean-Samuel
## Login   <durier_j@etna-alternance.net>
## 
## Started on  Mon May 23 20:09:38 2016 DURIER Jean-Samuel
## Last update Fri May 27 09:07:58 2016 DURIER Jean-Samuel
##
NAME    = sta
SRC     =	main.c\
		Characters/creature.c\
		Characters/hero.c\
		capture.c\
		readline.c\
		libmy/my_stdio.c\
		libmy/str_process.c\
		libmy/my_string.c\
		libmy/my_math.c\

OBJ     = $(SRC:%.c=%.o)
CFLAGS  = -W -Werror -Wall
RM      = rm -f
$(NAME):
		gcc -c $(SRC) $(CFLAGS)
		gcc *.o -o $(NAME)
all:		$(NAME)
		$(RM) *.o
clean:
		$(RM) *.o
fclean:		clean
		$(RM) $(NAME)
re:		fclean all
