#include <stdlib.h>
#include <time.h>
#include "../Characters/Hero/hero.h"
#include "../Characters/Creature/creature.h"
#include "../libmy/libmy.h"

#define NB_ATTACKS 4;

static char *g_attaques[] =
  {
    "slash",
    "fire",
    "gamble",
    "rest"
  };

char	*get_attaque(t_creature creature)
{
  int	rnd;
  char	*attack;
  
  srand(time(NULL));
  while (1)
    {
      rnd = rand() % NB_ATTACKS;
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

/*
** Return 1 if the attaque could be executed
** active = 1 if your creature attaks, 0 if your enemy attacks
*/
int    slash(t_creature *lanceur, t_creature *cible)
{
  if (lanceur->pm >= 3)
    {
      my_putstr("Attaque Slash !!!!....\n");
      rm_pv(cible, 15);
      rm_pm(lanceur, 3);
      return (1);
    }
  return (0);
}

/*
** Return 1 if the enemy has been caught
*/
int     magic_catch(t_hero *hero, t_creature *enemy)
{
  int luck;
  int result;

  if (use_magic_box(hero) == 0)
    return (0);
  luck = ((enemy->pvmax - enemy->pv) * 100) / enemy->pvmax;
  srand(time(NULL));
  result = rand() % 100;
  if (result <= luck )
    {
      my_putstr("Vous avez capturé la créature\n");
      add_creature_to_team(hero, enemy);
      return (1);
    }
  else
    {
      my_putstr("Vous n'avez pas réussi à capturer la créature\n");
      return (0);
    }
}

/*
** Return 1 if the attack has been run
*/
int	fire(t_creature *lanceur, t_creature *cible)
{
  if (lanceur->pm >= 7)
    {
      my_putstr("Attaque Fire !!!!...\n");
      rm_pv(cible, 30);
      rm_pm(lanceur, 7);
      return (1);
    }
  return (0);
}

void		gamble(t_creature *lanceur, t_creature *cible)
{
  int		crea_aleatoire;

  srand(time(NULL));
  crea_aleatoire = rand() % 21;
  if (crea_aleatoire % 2 == 0)
      rm_pv(lanceur, crea_aleatoire);
  else
      rm_pv(cible, crea_aleatoire);
}

void	rest(t_creature *lanceur)
{
  my_putstr("Consomme un tour....\n");
  add_pm(lanceur, 10);
}
