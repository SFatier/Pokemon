#include <stdio.h>
#include <stdlib.h>
#include "../libmy/libmy.h"
#include "../Characters/Creature/creature.h"
#include "../Characters/Hero/hero.h"
#include "attaques.h"

char	*readLine();
int	execute_attaque(char *attaque, t_creature *lanceur, t_creature *cible);
void    ask_attaque(t_hero *hero, t_creature *creature_team, t_creature *creature);
void	ia_attaque(t_hero *hero, t_creature *creature, t_creature *creature_team);
void	recap(t_creature *creature, t_creature *creature_team);
int	match_is_finish(t_hero *hero, t_creature *creature_team, t_creature *creature);
void	process_attack(char *attaque,
		    t_hero *hero,
		    t_creature *creature_team,
		    t_creature *creature);

void		fight(t_hero *hero, t_creature *creature_team)
{
  t_creature	*creature;

  my_putstr("\n");
  my_putstr(creature_team->name);
  my_putstr(" will fight for you\n\n");
  my_putstr("\n----------\n\nIn Battle Mode\n\n----------\n\n");
  creature = getCreature();
  if (creature == 0)
    return ;
  my_putstr("The creature ");
  my_putstr(creature->name);
  my_putstr(" is gonna attack you\n");
  summary(*creature);
  ask_attaque(hero, creature_team, creature);
}

int execute_attaque(char *attaque, t_creature *lanceur, t_creature *cible)
{
  int res;

  if (my_strcmp(attaque, "slash") == 0)
    {
      res = slash(lanceur, cible);
    }
  else
    {
      if (my_strcmp(attaque, "gamble") == 0)
	{
	  gamble(lanceur, cible);
	  res = 1;
	}
      else
	{
	  if (my_strcmp(attaque, "fire") == 0)
	    {
	      res = fire(lanceur, cible);
	    }
	  else
	    {
	      if (my_strcmp(attaque, "rest") == 0)
		{
		  rest(lanceur);
		  res = 1;
		}
	      else
		{
		  my_putstr("error : this command does not exist\n");
		  return (-1);
		}
	    }
	}
    }
  return(res);
}

void	ask_attaque(t_hero *hero, t_creature *creature_team, t_creature *creature)
{
  char	*attaque;
  
  my_putstr("\n\n*  *  *  *  *  *  *  *  *  *\n\n");
  my_putstr("Choose an attack : [slash - fire - gamble - rest - magic catch - quit]\n>");
  attaque = readLine();
  process_attack(attaque, hero, creature_team, creature);
}

void ia_attaque(t_hero *hero, t_creature *creature, t_creature *creature_team)
{
  char	*attaque;
  int	res;

  my_putstr("\n\n*  *  *  *  *  *  *  *  *  *\n\n");
  my_putstr("Enemy tour :\n>");
  attaque = get_attaque(*creature);
  my_putstr(attaque);
  my_putstr("\n");
  res = execute_attaque(attaque, creature, creature_team);
  if (res == 0)
    ia_attaque(hero, creature, creature_team);
  else
    {
      recap(creature, creature_team);
      if (match_is_finish(hero, creature_team, creature) == 1)
	;
      else
	ask_attaque(hero, creature_team, creature);
    }
}

void recap(t_creature *creature, t_creature *creature_team)
{
  my_putstr("\nResult :\n\n- Your creature :\n");
  print_state(*creature_team);
  my_putstr("\n- Enemy :\n");
  print_state(*creature);
  my_putstr("\n");
}

int match_is_finish(t_hero *hero, t_creature *creature_team, t_creature *creature)
{
  if (creature_team->pv <= 0)
    {
      my_putstr("Your creature is dead\n");
      removeCreatureFromTeam(hero, creature_team);
      free_creature(creature);
      return (1);
    }
  else
    {
      if (creature->pv <= 0)
	{
	  my_putstr("Yes ! You've just killed your enemy !\n");
	  free_creature(creature);
	  win_random_rupees(hero);
	  return (1);
	}
    }
  return (0);
}
