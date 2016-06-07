#include <stdlib.h>
#include <time.h>
#include "../Characters/hero.h"
#include "../Characters/creature.h"
#include "../libmy/libmy.h"

/*
** Return 1 if the attaque could be executed
** active = 1 if your creature attaks, 0 if your enemy attacks
*/
int    slash(t_creature *lanceur, t_creature *cible)
{
  if (lanceur->pm >= 3)
    {
      my_putstr("Slash attack!!!!....\n");
      rm_pv(cible, 15);
      rm_pm(lanceur, 3);
      return (1);
    }
  return (0);
}

int     magic_catch(t_creature *creature)
{
  int luck;
  int result;

  luck = ((creature->pvmax - creature->pv) * 100) / creature->pvmax;
  srand(time(NULL));
  result = rand() % 100;
  if (result <= luck )
    {
      my_putstr("You have captured the creature\n");
      return (1);
    }
  else
    {
      my_putstr("You don't have captured the creature\n");
      return (0);
    }
}

int	fire(t_creature *lanceur, t_creature *cible)
{
  if (lanceur->pm >= 7)
    {
      my_putstr("Fire attack!!!!...\n");
      rm_pv(cible, 30);
      rm_pm(lanceur, 7);
      return (1);
    }
  return (0);
}

int		gamble(t_creature *lanceur, t_creature *cible)
{
  int		crea_aleatoire;

  my_putstr("Gamble attack!!!!...\n");
  srand(time(NULL));
  crea_aleatoire = rand() % 21;
  if (crea_aleatoire % 2 == 0)
      rm_pv(lanceur, crea_aleatoire);
  else
    rm_pv(cible, crea_aleatoire);
  return (1);
}

int	rest(t_creature *lanceur)
{
  my_putstr("Skip the turn....\n");
  add_pm(lanceur, 10);
  my_putstr(lanceur->name);
  my_putstr(" : pm + 10\n");
  return (1);
}
