#include "hero.h"
#include "../Creature/creature.h"
#include "../../libmy/libmy.h"
#include <time.h>
#include <stdlib.h>

void	buy_mushroom(t_hero *hero)
{
  if (hero->rupees < 30)
    {
      my_putstr("Vous n'avez pas assez de rupees pour acheter des champignons\n");
      return;
    }
  hero->rupees -= 30;
  hero->mushrooms += 1;
  my_putstr("Vous venez d'ajouter un champignon à votre panier\n");
}

void	buy_magic_box(t_hero *hero)
{
  if (hero->rupees < 90)
    {
      my_putstr("Vous n'avez pas assez de rupees pour acheter une magic box\n");
      return;
    }
  hero->rupees -= 90;
  hero->magic_box += 1;
  my_putstr("Vous venez d'acheter une magic box\n");
}

void	use_mushroom(t_hero *hero, t_creature *creature)
{
  int	bonus;

  if (hero->mushrooms <= 0)
    {
      my_putstr("error : Vous n'avez plus de champignons\n");
      return ;
    }
  hero->mushrooms -= 1;
  srand(time(NULL));
  bonus = ((rand() % 11 + 15) * creature->pvmax / 100);
  add_pv(creature, bonus);
  my_putstr("La créature ");
  my_putstr(creature->name);
  my_putstr(" a gagné ");
  my_put_nbr(bonus);
  my_putstr(" pm\n");
}

int	use_magic_box(t_hero *hero)
{
  if (hero->magic_box <= 0)
    {
      my_putstr("error : Vous n'avez plus de magic box\n");
      return (0);
    }
  hero->magic_box -= 1;
  return (1);
}

void	show_hero_basket(t_hero hero)
{
  my_putstr("\n-----\nPanier de votre héro :\n-----\n\n");
  my_putstr("Rupees : ");
  my_put_nbr(hero.rupees);
  my_putstr("\nMushrooms : ");
  my_put_nbr(hero.mushrooms);
  my_putstr("\nMagic box : ");
  my_put_nbr(hero.magic_box);
  my_putstr("\n\n");
}

void	win_random_rupees(t_hero *hero)
{
  int	rupees;

  srand(time(NULL));
  rupees = 90 + (rand() % 31);
  hero->rupees += rupees;
  my_putstr("Votre héro vient de remporter ");
  my_put_nbr(rupees);
  my_putstr(" rupees\n");
}
