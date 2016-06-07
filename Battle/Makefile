##
## Makefile for  in /home/jsdurier/FDI/DEVC/Battle For Midgard
## 
## Made by DURIER Jean-Samuel
## Login   <durier_j@etna-alternance.net>
## 
## Started on  Mon May 23 20:09:38 2016 DURIER Jean-Samuel
## Last update Fri May 27 10:53:44 2016 DURIER Jean-Samuel
##
NAME    = sta
SRC     = 	main.c\
		Characters/creature.c\
		Characters/hero.c\
		Characters/points.c\
		Characters/team.c\
		Characters/team_tools.c\
		capture.c\
		readline.c\
		OutOfBattle/outOfBattle.c\
		InBattle/fight.c\
		InBattle/attaques.c\
		InBattle/get_attaque.c\
		InBattle/action.c\
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
