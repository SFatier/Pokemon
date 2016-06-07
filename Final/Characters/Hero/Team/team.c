#include <time.h>
#include <stdlib.h>
#include "../../../libmy/libmy.h"
#include "../hero.h"
#include "../../Creature/creature.h"

int		team_length(t_hero hero);
t_creature      *get_creature_by_index(t_hero hero, int index);

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

  my_putstr("Team du hero : \n");
  tmp = hero.team;
  while (tmp != 0)
    {
      my_putstr(tmp->creature->name);
      my_putstr("\n");
      tmp = tmp->next;
    }
}

void			removeCreatureFromTeam(t_hero *hero, t_creature *creature)
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

t_creature      *choose_creature(t_hero hero)
{
  int           rnd;
  t_creature    *creature;

  srand(time(NULL));
  rnd = rand() % team_length(hero);
  creature = get_creature_by_index(hero, rnd);
  my_putstr("\nVous avez désigné la créature ");
  my_putstr(creature->name);
  my_putstr(" pour aller au combat\n");
  return (creature);
}
