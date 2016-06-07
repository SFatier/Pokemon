#include <stdlib.h>
#include <time.h>
#include "hero.h"
#include "creature.h"
#include "../libmy/libmy.h"

void            removeCreatureFromTeam(t_hero *hero, t_creature *creature)
{
  t_creature_in_team    *tmp;

  tmp = hero->team;
  if (tmp->creature == creature)
    {
      free_creature(creature);
      hero->team = tmp->next;
      free(tmp);
      return ;
    }
  while (tmp->creature != creature && tmp->next != 0)
    {
      if (tmp->next->creature == creature)
	{
	  free_creature(creature);
	  free(tmp->next);
	  tmp->next = tmp->next->next;
	  return ;
	}
      tmp = tmp->next;
    }
  if (tmp != 0 && tmp->creature == creature)
    {
      free_creature(creature);
      free(tmp);
    }
}

int                     add_creature_to_team(t_hero *hero, t_creature *creature)
{
  t_creature_in_team    *teamCreature;

  teamCreature = malloc(sizeof(*teamCreature));
  if (teamCreature == NULL)
    return (0);
  creature->pvmax *= 2;
  creature->pmmax *= 2;
  creature->pv = creature->pvmax;
  creature->pm = creature->pmmax;
  teamCreature->creature = creature;
  teamCreature->next = hero->team;
  hero->team = teamCreature;
  return (1);
}

void                    team(t_hero hero)
{
  t_creature_in_team    *tmp;

  my_putstr("\n----- Votre team ----- \n\n");
  tmp = hero.team;
  while (tmp != 0)
    {
      summary(*(tmp->creature));
      my_putstr("\n");
      tmp = tmp->next;
    }
}
