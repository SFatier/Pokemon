#include "../hero.h"
#include "../../Creature/creature.h"

int     team_length(t_hero hero)
{
  int   res;
  t_creature_in_team    *tmp;

  res = 0;
  tmp = hero.team;
  while (tmp != 0)
    {
      res += 1;
      tmp = tmp->next;
    }
  return (res);
}

t_creature      *get_creature_by_index(t_hero hero, int index)
{
  t_creature_in_team    *tmp;
  int                   i;

  tmp = hero.team;
  for (i = 0; i < index; i += 1)
    {
      if (tmp == 0)
	return (0);
      tmp = tmp->next;
    }
  return (tmp->creature);
}
