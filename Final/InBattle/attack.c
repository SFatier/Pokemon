#include <stdlib.h>
#include "../libmy/libmy.h"
#include "../Characters/Creature/creature.h"
#include "../Characters/Hero/hero.h"
#include "attaques.h"
#include "inBattle.h"

void process_attack(char *attaque,
		    t_hero *hero,
		    t_creature *creature_team,
		    t_creature *creature);

void process_attack2(char *attaque,
		     t_hero *hero,
		     t_creature *creature_team,
		     t_creature *creature);

void process_attack(char *attaque,
		    t_hero *hero,
		    t_creature *creature_team,
		    t_creature *creature)
{ 
  if (my_strcmp(attaque, "magic catch") == 0)
    {
      free(attaque);
      if (magic_catch(hero, creature) == 1)
	return;
    }
  else
    {
      if (my_strcmp(attaque, "quit") == 0)
	{
	  free(attaque);
	  free_creature(creature);
	  my_putstr("You left the IB mode\n");
	  return;
	}
      else
	{
	  process_attack2(attaque, hero, creature_team, creature);
	}
    }
  ia_attaque(hero, creature, creature_team);
}

void process_attack2(char *attaque,
		     t_hero *hero,
		     t_creature *creature_team,
		     t_creature *creature)
{
  int res_attaque;
  
  res_attaque = execute_attaque(attaque, creature_team, creature);
  free(attaque);
  if (res_attaque == 0)
    {
      my_putstr("You don't have enough pm\n");
      my_putstr("You don't have enough pm\n");
    }
  else
    {
      if (res_attaque == -1)
	{
	  ask_attaque(hero, creature_team, creature);
	  return ;
	}
      else
	{
	  recap(creature, creature_team);
	  if (match_is_finish(hero, creature_team, creature) == 1)
	    return ;
	}
    }
}
