#include <stdlib.h>
#include <time.h>
#include "../Characters/hero.h"
#include "../Characters/creature.h"
#include "../libmy/libmy.h"

static char *g_attaques[] =
  {
    "slash",
    "fire",
    "gamble",
    "rest"
  };

char    *get_attaque(t_creature creature)
{
  int   rnd;
  char  *attack;

  srand(time(NULL));
  while (1)
    {
      rnd = rand() % 3;
      attack = g_attaques[rnd];
      if (my_strcmp(attack, "slash") == 0)
	{
	  if (creature.pm >= 3)
	    return (attack);
	}
      else
	{
	  if (my_strcmp(attack, "fire") == 0)
	    {
	      if (creature.pm >= 7)
		return (attack);
	    }
	  else
	    return (attack);
	}
    }
}
