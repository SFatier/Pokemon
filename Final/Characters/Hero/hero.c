#include <stdlib.h>
#include <time.h>
#include "hero.h"
#include "../Creature/creature.h"
#include "../../libmy/libmy.h"

t_creature      *get_creature_by_index(t_hero hero, int index);
int		team_length(t_hero hero);

t_hero		*createHero(char *name)
{
  t_hero	*hero;

  hero = malloc(sizeof(*hero));
  if (hero == NULL)
    return (NULL);
  hero->name = name;
  hero->team = 0;
  hero->rupees = 420;
  hero->magic_box = 5;
  hero->mushrooms = 0;
  return (hero);
}

void			freeHero(t_hero *hero)
{
  t_creature_in_team	*tmp;
  t_creature_in_team	*tmp2;
  
  tmp = hero->team;
  while (tmp != 0)
    {
      tmp2 = tmp->next;
      free_creature(tmp->creature);
      free(tmp);
      tmp = tmp2;
    }
  free(hero);
}
