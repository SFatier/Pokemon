#include "../Characters/creature.h"

#ifndef __ATTAQUES_H__
#define __ATTAQUE_H__

int     magic_catch(t_creature *creature);
int	slash(t_creature *lanceur, t_creature *cible);
int	gamble(t_creature *lanceur, t_creature *cible);
int     fire(t_creature *lanceur, t_creature *cible);
char    *get_attaque(t_creature creature);
int	attack_is_available(t_creature creature, char *attack);
int     rest(t_creature *lanceur);

#endif
