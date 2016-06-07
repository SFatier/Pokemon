#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "libmy/libmy.h"
#include "Characters/creature.h"

char	*readLine();
void	process_action(t_creature *creature);
void     magicCatch(t_creature *creature);
void	help(t_creature *creature);

void          battle()
{
  t_creature  *creature;

  creature = getCreature();
  my_putstr("Le monstre ");
  my_putstr(creature->name);
  my_putstr(" va vous affronter\n");
  process_action(creature);
}

void		process_action(t_creature *creature)
{
  char		*action;
  
  my_putstr("\n*  *  *  *  *  *\n");
  my_putstr("Votre tour [help me !!! - magic catch - q]\n> ");
  action = readLine();
  if (my_strcmp(action, "help me !!!") == 0)
    {
      help(creature);
    }
  else
    {
      if (my_strcmp(action, "magic catch") == 0)
	  magicCatch(creature);
      else
	{
	  if (my_strcmp(action, "q") == 0)
	    free_creature(creature);
	  else
	    {
	      my_putstr("L'entree n'existe pas\n");
	      process_action(creature);
	    }
	}
    }
  free(action);
}

void	magicCatch(t_creature *creature)
{
  srand(time(NULL));
  if (rand() % 3 == 2)
    {
      my_putstr("Vous avez réussi à capturer la créature\n");
      my_putstr("\n-----Résumé de la créature-----\n");
      summary(*creature);
      my_putstr("\n");
      free_creature(creature);
    }
  else
    {
      my_putstr("Vous n'avez pas réussi à capturer la créature\n");
      free_creature(creature);
      battle();
    }
}

void help(t_creature *creature)
{
  my_putstr("Vous avez fuit\n");
  free_creature(creature);
  battle();
}
