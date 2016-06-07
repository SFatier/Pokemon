
#include "../libmy/libmy.h"
#include <stdlib.h>
#include "../Characters/Hero/hero.h"
#include "../Characters/Creature/creature.h"
#include "../InBattle/inBattle.h"

void    ask_action(t_hero *hero, t_creature *creature_chosen);
void	battle(t_hero *hero);
int     action2(char *input, t_hero *hero, t_creature *creature_chosen);
int     action3(char *input, t_hero *hero, t_creature *creature_chosen);
int     action4(char *input, t_hero *hero, t_creature *creature_chosen);

void action(char *input, t_hero *hero, t_creature *creature_chosen)
{
  if (my_strcmp(input, "team") == 0)
    {
      free(input);
      team(*hero);
    }
  else
    {
      if (my_strcmp(input, "you are the chosen one") == 0)
       {
	 free(input);
	 creature_chosen = choose_creature(*hero);
       }
      else
	{
	  if (action2(input, hero, creature_chosen) == 1)
	    return ;
	}
    }
  ask_action(hero, creature_chosen);
}

int	action2(char *input, t_hero *hero, t_creature *creature_chosen)
{
  if (my_strcmp(input, "let's fight") == 0)
    {
      free(input);
      if (creature_chosen == 0)
	my_putstr("Vous devez d'abord choisir une créature pour combattre\n");
      else
	{
	  fight(hero, creature_chosen);
	  battle(hero);
	  return (1);
	}
    }
  else
    {
      if (my_strcmp(input, "see basket") == 0)
	{
	  free(input);
	  show_hero_basket(*hero);
	}
      else
	{
	  return (action3(input, hero, creature_chosen));
	}
    }
  return (0);
}

int	action3(char *input, t_hero *hero, t_creature *creature_chosen)
{
  if (my_strcmp(input, "buy mushroom") == 0)
    {
      free(input);
      buy_mushroom(hero);
    }
  else
    {
      if (my_strcmp(input, "buy magic box") == 0)
	{
	  free(input);
	  buy_magic_box(hero);
	}
      else
	{
	  return (action4(input, hero, creature_chosen));
	}
    }
  return (0);
}

int	action4(char *input, t_hero *hero, t_creature *creature_chosen)
{
  if (my_strcmp(input, "eat mushroom") == 0)
    {
      free(input);
      if (creature_chosen == 0)
	my_putstr("Vous devez d'abord choisir une créature\n");
      else
	use_mushroom(hero, creature_chosen);
    }
  else
    {
      if (my_strcmp(input, "q") == 0)
	{
	  free(input);
	  return (1);
	}
    }
  return (0);
}
