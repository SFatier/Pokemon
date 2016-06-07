/*
** my_math.c for  in /home/jsdurier/Piscine_C/Libmy/durier_j/libmy_01
** 
** Made by DURIER Jean-Samuel
** Login   <durier_j@etna-alternance.net>
** 
** Started on  Sat Mar 26 09:19:25 2016 DURIER Jean-Samuel
** Last update Tue Mar 29 15:49:01 2016 DURIER Jean-Samuel
*/
int     my_isneg(int n)
{
  if (n < 0)
    return (0);
  return (1);
}

void    my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
}

int     my_pow(int nb, int p)
{
  int   res;
  int   i;

  res = 1;
  for (i = 0; i < p; i++)
    {
      res *= nb;
    }
  return (res);
}

int     is_alpha_number(char c)
{
  if ((c >= 65 && c <= 90) ||
      (c >= 97 && c <= 122) ||
      (c >= 48 && c <= 57))
    return (1);
  return (0);
}
