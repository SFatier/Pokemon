#ifndef __CREATURE__H
# define __CREATURE__H

typedef struct  s_creature
{
  char		*name;
  int		lvl;
  int		pv;
  int		pvmax;
  int		pm;
  int		pmmax;
}		t_creature;

t_creature	*getCreature();
void		summary(t_creature creature);
void		heal_creature(t_creature *creature);
void		free_creature(t_creature *creature);
void		add_pm(t_creature *creature, int pm);
void		add_pv(t_creature *creature, int pv);
void		rm_pm(t_creature *creature, int pm);
void		rm_pv(t_creature *creature, int pv);
void		print_state(t_creature creature);

#endif
