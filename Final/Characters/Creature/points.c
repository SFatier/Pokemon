#include "creature.h"

void    add_pm(t_creature *creature, int pm)
{
  creature->pm += pm;
  if (creature->pm > creature->pmmax)
    creature->pm = creature->pmmax;
}

void    add_pv(t_creature *creature, int pv)
{
  creature->pv += pv;
  if (creature->pv > creature->pvmax)
    creature->pv = creature->pvmax;
}

void rm_pm(t_creature *creature, int pm)
{
  creature->pm -= pm;
  if (creature->pm < 0)
    creature->pm = 0;
}

void rm_pv(t_creature *creature, int pv)
{
  creature->pv -= pv;
  if (creature->pv < 0)
    creature->pv = 0;
}
