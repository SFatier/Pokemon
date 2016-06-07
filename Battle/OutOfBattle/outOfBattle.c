#include <stdlib.h>
#include "../libmy/libmy.h"
#include "../Characters/hero.h"
#include "../Characters/creature.h"
#include "../InBattle/inBattle.h"

char    *readLine();
void    ask_action(t_hero *hero, t_creature *creature_chosen);
void	process_user_choice(char *input, t_hero *hero, t_creature *creature_chosen);
int	process_user_choice2(char *input, t_hero *hero, t_creature *creature_chosen);

void		battle(t_hero *hero)
{
  t_creature    *creature_chosen;

  if (team_length(*hero) <= 0)
      my_putstr("Nobody is in your team anymore\n");
  else
    {
      creature_chosen = 0;
      my_putstr("\n----------\n\nOut of Battle Mode\n\n----------\n\n");
      ask_action(hero, creature_chosen);
    }
}

void	ask_action(t_hero *hero, t_creature *creature_chosen)
{
  char	*input;
  
  my_putstr("\nWhat do you want to do?");
  my_putstr("[team - you are the chosen one - let's fight - q]\n> ");
  input = readLine();
  process_user_choice(input, hero, creature_chosen);
}

void process_user_choice(char *input, t_hero *hero, t_creature *creature_chosen)
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
	  my_putstr("You have chosen ");
	  my_putstr(creature_chosen->name);
	  my_putstr(" to fight for you\n");
	  summary(*creature_chosen);
	}
      else
	{
	  if (process_user_choice2(input, hero, creature_chosen) == 1)
	    return;
	}
    }
  ask_action(hero, creature_chosen);
}

int process_user_choice2(char *input, t_hero *hero, t_creature *creature_chosen)
{
  if (my_strcmp(input, "let's fight") == 0)
    {
      free(input);
      if (creature_chosen == 0)
	my_putstr("error : First you have to choose a creature\n");
      else
	{
	  fight(hero, creature_chosen);
	  battle(hero);
	  return (1);
	}
    }
  else
    {
      if (my_strcmp(input, "q") == 0)
	{
	  free(input);
	  my_putstr("\nAu revoir !\n");
	  return (1);
	}
      else
	free(input);
    }
  return (0);
}
