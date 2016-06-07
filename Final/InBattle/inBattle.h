#include "../Characters/Creature/creature.h"
#include "../Characters/Hero/hero.h"

#ifndef __FIGHT_H__
# define __FIGHT_H__

void	fight(t_hero *hero, t_creature *creature_team);
int     execute_attaque(char *attaque, t_creature *lanceur, t_creature *cible);
void    ask_attaque(t_hero *hero, t_creature *creature_team, t_creature *creature);
void    ia_attaque(t_hero *hero, t_creature *creature, t_creature *creature_team);
void    recap(t_creature *creature, t_creature *creature_team);
int     match_is_finish(t_hero *hero, t_creature *creature_team, t_creature *creature);
void    process_attack(char *attaque,
		       t_hero *hero,
		       t_creature *creature_team,
		       t_creature *creature);

#endif
