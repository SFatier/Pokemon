/*
** my_string.c for  in /home/jsdurier/Piscine_C/Libmy/durier_j/libmy_01
** 
** Made by DURIER Jean-Samuel
** Login   <durier_j@etna-alternance.net>
** 
** Started on  Sat Mar 26 09:26:08 2016 DURIER Jean-Samuel
** Last update Sat Mar 26 17:38:01 2016 DURIER Jean-Samuel
*/
int     my_strlen(char *str)
{
  int   length;

  length = 0;
  while (*str != '\0')
    {
      length += 1;
      str += 1;
    }
  return (length);
}

int     my_strcmp(char *s1, char *s2)
{
  int length1;
  int length2;

  length1 = my_strlen(s1);
  length2 = my_strlen(s2);
  while (*s1 != '\0' && *s2 != '\0')
    {
      if (*s1 > *s2)
	return (1);
      if (*s1 < *s2)
	return (-1);
      s1 += 1;
      s2 += 1;
    }
  if (length1 > length2)
    return (1);
  if (length1 < length2)
    return (-1);
  return (0);
}

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  for (i = 0; i < n && *s1 != '\0' && *s2 != '\0'; i++)
    {
      if (*s1 > *s2)
	return (1);
      if (*s1 < *s2)
	return (-1);
      s1 += 1;
      s2 += 1;
    }
  if ((*s1 == '\0') == (*s2 != '\0'))
    {
      if (*s1 == '\0')
	return (-1);
      return (1);
    }
  return (0);
}

char    *my_strstr(char *str, char *to_find)
{
  char  *res;
  char  *to_find_cp;
  static char *str_null = "null";
  
  res = 0;
  to_find_cp = to_find;
  while (*str != '\0' && *to_find != '\0')
    {
      if (*str == *to_find)
	{
	  if (res == 0)
	    res = str;
	  to_find += 1;
	}
      else
	{
	  res = 0;
	  to_find = to_find_cp;
	}
      str += 1;
    }
  if (res == 0 || *to_find != '\0')
      return str_null;
  return (res);
}
