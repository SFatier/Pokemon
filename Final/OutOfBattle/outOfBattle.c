#include <stdlib.h>
#include "../libmy/libmy.h"
#include "../Characters/Hero/hero.h"
#include "../Characters/Creature/creature.h"
#include "../InBattle/inBattle.h"

char    *readLine();
void    ask_action(t_hero *hero, t_creature *creature_chosen);
void	action(char *input, t_hero *hero, t_creature *creature_chosen);

void		battle(t_hero *hero)
{
  t_creature    *creature_chosen;

  if (team_length(*hero) <= 0)
    {
      my_putstr("Nobody is in your team anymore\n");
    }
  else
    {
      creature_chosen = 0;
      my_putstr("\n----------\n");
      my_putstr("\nOut of Battle Mode\n\n----------\n\n");
      ask_action(hero, creature_chosen);
    }
}

void	ask_action(t_hero *hero, t_creature *creature_chosen)
{
  char	*input;
  
  my_putstr("\nWhat do you want to do?? [team - you are the chosen one ");
  my_putstr("- let's fight - see basket - buy mushroom - ");
  my_putstr("buy magic box - eat mushroom - q]\n> ");
  input = readLine();
  action(input, hero, creature_chosen);
}
