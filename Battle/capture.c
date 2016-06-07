#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "libmy/libmy.h"
#include "Characters/creature.h"
#include "OutOfBattle/outOfBattle.h"

char	*readLine();
void	hero_against_creature(t_hero *hero, t_creature *creature);
int     magicCatch(t_hero *hero, t_creature *creature);
void	help_me(t_creature *creature);
void	func(char *action, t_creature *creature, t_hero *hero);

/*
** Phase de capture d'un monstre avant de commencer la battle
*/
void          capture(t_hero *hero)
{
  t_creature  *creature;

  creature = getCreature();
  if (creature == 0)
    return ;
  my_putstr("\n*  *  *  *  *\n\nLe monstre ");
  my_putstr(creature->name);
  my_putstr(" va vous affronter\n");
  hero_against_creature(hero, creature);
}

void		hero_against_creature(t_hero *hero, t_creature *creature)
{
  char		*action;
  
  my_putstr("\nEntrez une action [help me !!! - magic catch]\n>");
  action = readLine();
  if (my_strcmp(action, "help me !!!") == 0)
    {
      free(action);
      help_me(creature);
      capture(hero);
    }
  else
    {
      if (my_strcmp(action, "magic catch") == 0)
	{
	  free(action);
	  if (magicCatch(hero, creature) == 0)
	      capture(hero);
	  else
	    battle(hero);
	}
      else
	  func(action, creature, hero);
    }
}

int	magicCatch(t_hero *hero, t_creature *creature)
{
  srand(time(NULL));
  if (rand() % 3 == 2)
    {
      my_putstr("Vous avez capturé la créature\n");
      add_creature_to_team(hero, creature);
      my_putstr("\n\nRésumé de la créature capturée :\n\n");
      summary(*creature);
      return (1);
    }
  else
    {
      my_putstr("Vous n'avez pas réussi à capturer la créture\n");
      my_putstr("Celle-ci va vous forcer à fuir\n");
      free_creature(creature);
      return (0);
    }  
}


void help_me(t_creature *creature)
{
  my_putstr("Vous avez fuit comme un lâche\n");
  free_creature(creature);
}

void func(char *action, t_creature *creature, t_hero *hero)
{
  if (my_strcmp(action, "q") == 0)
    {
      free_creature(creature);
      free(action);
    }
  else
    {
      free(action);
      my_putstr("L'entree n'existe pas\n");
      hero_against_creature(hero, creature);
    }
}
