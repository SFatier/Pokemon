#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "creature.h"
#include "../libmy/libmy.h"

#define NBCREA 5

static t_creature g_creatures[] =
  {
    {"Koopa", 1, 10, 10, 20, 20},
    {"Bob bomb", 1, 10, 10, 20, 20},
    {"Yoshi", 1, 10, 10, 20, 20},
    {"Maskas", 1, 10, 10, 20, 20},
    {"Kucco", 1, 10, 10, 20, 20},
    {NULL, 0, 0, 0, 0, 0}
  };

t_creature	*getCreature()
{
  int		rnd;
  t_creature	*crea;

  srand(time(NULL));
  rnd = rand() % NBCREA;
  if ((crea = malloc(sizeof(t_creature))) == NULL)
    return (NULL);
  crea->name = strdup(g_creatures[rnd].name);
  if (!crea->name)
    return (NULL);
  crea->lvl = g_creatures[rnd].lvl;
  crea->pv = g_creatures[rnd].pv;
  crea->pvmax = g_creatures[rnd].pvmax;
  crea->pm = g_creatures[rnd].pm;
  crea->pmmax = g_creatures[rnd].pmmax;
  return (crea);
}

void summary(t_creature creature)
{
  my_putstr("Nom : ");
  my_putstr(creature.name);
  my_putstr("\nlvl : ");
  my_put_nbr(creature.lvl);
  my_putstr("\npv : ");
  my_put_nbr(creature.pv);
  my_putstr("\npvmax : ");
  my_put_nbr(creature.pvmax);
  my_putstr("\npm : ");
  my_put_nbr(creature.pm);
  my_putstr("\npmmax : ");
  my_put_nbr(creature.pmmax);
  my_putstr("\n");
}

void    free_creature(t_creature *creature)
{
  free(creature->name);
  free(creature);
}
