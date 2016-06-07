/*
** my_stdio.c for  in /home/jsdurier/Piscine_C/Libmy/durier_j/libmy_01
** 
** Made by DURIER Jean-Samuel
** Login   <durier_j@etna-alternance.net>
** 
** Started on  Sat Mar 26 09:16:49 2016 DURIER Jean-Samuel
** Last update Sat Mar 26 17:38:52 2016 DURIER Jean-Samuel
*/
#include <unistd.h>
int     my_pow(int nb, int p);

void my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}

int     my_getnbr(char *str)
{
  int   res;
  int   sign;

  res = 0;
  sign = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign *= -1;
      str += 1;
    }
  while (*str != '\0' && *str > 47 && *str < 58)
    {
      if (res <= (2147483647 - (*str - 48)) / 10)
	{
	  res = res * 10;
	  res += *str - 48;
	  str += 1;
	}
      else
	return (0);
    }
  return (res * sign);
}

void    my_put_nbr(int  nb)
{
  int   var;
  int   digits;
  int   i;
  int   digit;

  digits = 1;
  var = nb / 10;
  while (var != 0)
    {
      digits += 1;
      var /= 10;
    }
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = -nb;
	}
      for (i = digits; i > 0; i--)
	{
	  digit = nb / (my_pow(10, i - 1)) % 10;
	  my_putchar(digit + 48);
	}
    }
}
