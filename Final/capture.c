#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "libmy/libmy.h"
#include "Characters/Creature/creature.h"
#include "OutOfBattle/outOfBattle.h"

char	*readLine();
void	hero_against_creature(t_hero *hero, t_creature *creature);
int     magicCatch(t_hero *hero, t_creature *creature);
void	help_me(t_hero *hero, t_creature *creature);

/*
** Phase de capture d'un monstre avant de commencer la battle
*/
void          capture(t_hero *hero)
{
  t_creature  *creature;

  creature = getCreature();
  if (creature == 0)
    return ;
  my_putstr("The creature ");
  my_putstr(creature->name);
  my_putstr(" is gonna attack you\n");
  hero_against_creature(hero, creature);
}

void		hero_against_creature(t_hero *hero, t_creature *creature)
{
  char		*action;
  
  my_putstr("\nChoose an action [help me !!! - magic catch - q]\n>");
  action = readLine();
  if (my_strcmp(action, "help me !!!") == 0)
      help_me(hero, creature);
  else
    {
      if (my_strcmp(action, "magic catch") == 0)
	  magicCatch(hero, creature);
      else
	{
	  if (my_strcmp(action, "q") == 0)
	      free_creature(creature);
	  else
	    {
	      my_putstr("error : Unknown command\n");
	      hero_against_creature(hero, creature);
	    }
	}
    }
  free(action);
}

int	magicCatch(t_hero *hero, t_creature *creature)
{
  srand(time(NULL));
  if (rand() % 3 == 2)
    {
      my_putstr("Yes ! You have captured the creature !\n");
      add_creature_to_team(hero, creature);
      my_putstr("\n\nSummary of the creature :\n\n");
      summary(*creature);
      battle(hero);
      return (1);
    }
  else
    {
      my_putstr("Missed ! You have not captured the creature\n");
      free_creature(creature);
      capture(hero);
      return (0);
    }  
}


void help_me(t_hero *hero, t_creature *creature)
{
  my_putstr("You run like a coward\n");
  free_creature(creature);
  capture(hero);
}
