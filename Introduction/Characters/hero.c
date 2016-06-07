#include <stdlib.h>
#include "hero.h"
#include "creature.h"
#include "../libmy/libmy.h"

t_hero		*createHero(char *name)
{
  t_hero	*hero;

  hero = malloc(sizeof(*hero));
  if (hero == NULL)
    return (NULL);
  hero->name = name;
  hero->team = 0;
  return (hero);
}

int			add_creature_to_team(t_hero *hero, t_creature *creature)
{
  t_creature_in_team	*teamCreature;

  teamCreature = malloc(sizeof(*teamCreature));
  if (teamCreature == NULL)
    return (0);
  teamCreature->creature = creature;
  teamCreature->next = hero->team;
  hero->team = teamCreature;
  return (1);
}

void			team(t_hero hero)
{
  t_creature_in_team	*tmp;

  my_putstr("Team du hero : \n");
  tmp = hero.team;
  while (tmp != 0)
    {
      my_putstr(tmp->creature->name);
      my_putstr("\n");
      tmp = tmp->next;
    }
}
