#include <stdlib.h>
#include "libmy/libmy.h"
#include "Characters/creature.h"
#include "Characters/hero.h"
#include "capture.h"

void	print_usage();

int		main(int argc, char **argv)
{
  t_hero	*hero;

  if (argc == 3)
    {
      if (my_strcmp(argv[1], "-n") == 0)
	{
	  hero = createHero(argv[2]);
	  if (hero == 0)
	    return (1);
	  else
	  {
	      my_putstr("Bienvenue ");
	      my_putstr(hero->name);
	      my_putstr(" dans le jeu Battle For Midgard\n");
	      capture(hero);
	  }
	}
    }
  else
    {
      print_usage();
    }
  freeHero(hero);
  my_putstr("\n----------Au revoir----------\n");
  return (0);
}

void	print_usage()
{
  my_putstr("usage : ./sta -n name \n");
}
