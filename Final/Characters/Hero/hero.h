#include "../Creature/creature.h"

#ifndef __HERO_H__
#define  __HERO_H__

typedef	struct			s_creature_in_team
{
  t_creature                    *creature;
  struct s_creature_in_team	*next;
}				t_creature_in_team;

typedef struct		s_hero
{
  char			*name;
  t_creature_in_team	*team;
  int			rupees;
  int			mushrooms;
  int			magic_box;
}			t_hero;

t_hero		*createHero(char *name);
int		add_creature_to_team(t_hero *hero, t_creature *creature);
void		team(t_hero hero);
int		team_length(t_hero hero);
t_creature      *choose_creature(t_hero hero);
void            removeCreatureFromTeam(t_hero *hero, t_creature *creature);
void		freeHero(t_hero *hero);
void		buy_mushroom(t_hero *hero);
void		buy_magic_box(t_hero *hero);
void		use_mushroom(t_hero *hero, t_creature *creature);
int		use_magic_box(t_hero *hero);
void		show_hero_basket(t_hero hero);
void		win_random_rupees(t_hero *hero);

#endif
