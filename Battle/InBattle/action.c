#include <stdio.h>
#include <stdlib.h>
#include "../libmy/libmy.h"
#include "../Characters/creature.h"
#include "../Characters/hero.h"
#include "attaques.h"

char    *readLine();
int     execute_attaque(char *attaque, t_creature *lanceur, t_creature *cible);
void    ask_attaque(t_hero *hero, t_creature *creature_team, t_creature *creature);
void    ia_attaque(t_hero *hero, t_creature *creature, t_creature *creature_team);
void    recap(t_creature *creature, t_creature *creature_team);
int     match_is_finish(t_hero *hero, t_creature *creature_team, t_creature *creature);
int	action2(char *attaque, t_hero *hero, t_creature *creature_team, t_creature *creature);
int     action3(char *attaque, t_hero *hero, t_creature *creature_team, t_creature *creature);

void	action(char *attaque,
	       t_hero *hero,
	       t_creature *creature_team,
	       t_creature *creature)
{
  int	res_func;
  
  if (my_strcmp(attaque, "magic catch") == 0)
    {
      free(attaque);
      if (magic_catch(creature) == 1)
	{
	  add_creature_to_team(hero, creature);
	  return;
	}
    }
  else
    {
      res_func = action2(attaque, hero, creature_team, creature);
      if (res_func == 1)
	return ;
   }
  ia_attaque(hero, creature, creature_team);
}

int execute_attaque(char *attaque, t_creature *lanceur, t_creature *cible)
{
  int res;

  if (my_strcmp(attaque, "slash") == 0)
    res = slash(lanceur, cible);
  else
    {
      if (my_strcmp(attaque, "gamble") == 0)
	res = gamble(lanceur, cible);
      else
	{
	  if (my_strcmp(attaque, "fire") == 0)
	    res = fire(lanceur, cible);
	  else
	    {
	      if (my_strcmp(attaque, "rest") == 0)
		res = rest(lanceur);
	      else
		{
		  my_putstr("L'attaque n'existe pas\n");
		  return (-1);
		}
	    }
	}
    }
  return(res);
}

/*
** return 1 if the fight continue
*/
int	action2(char *attaque,
		t_hero *hero,
		t_creature *creature_team,
		t_creature *creature)
{
  if (my_strcmp(attaque, "quit") == 0)
    {
      free(attaque);
      free_creature(creature);
      my_putstr("Vous left th IB mode\n");
      return (1);
    }
  else
      return (action3(attaque, hero, creature_team, creature));
}

/*                                                                                                                                                                                                              
** return 1 if the fight continue                                                                                                                                                                               
*/
int	action3(char *attaque,
		t_hero *hero,
		t_creature *creature_team,
		t_creature *creature)
{
  int	res_attaque;
  
  res_attaque = execute_attaque(attaque, creature_team, creature);
  free(attaque);
  if (res_attaque == 0)
    my_putstr("Vous n'avez pas assez de pm pour effectuer cette attaque\n");
  else
    {
      if (res_attaque == -1)
	my_putstr("Cette attaque n'existe pas\n");
      else
	{
	  recap(creature, creature_team);
	  if (match_is_finish(hero, creature_team, creature) == 1)
	    return (1);
	}
    }
  return (0);
}
