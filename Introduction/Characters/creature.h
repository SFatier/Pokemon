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
void		free_creature(t_creature *creature);

#endif
