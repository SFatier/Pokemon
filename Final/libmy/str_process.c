/*
** str_process.c for  in /home/jsdurier/Piscine_C/Libmy/durier_j/libmy_01
** 
** Made by DURIER Jean-Samuel
** Login   <durier_j@etna-alternance.net>
** 
** Started on  Sat Mar 26 10:05:42 2016 DURIER Jean-Samuel
** Last update Sat Mar 26 17:39:35 2016 DURIER Jean-Samuel
*/
int     my_strlen(char *str);

char    *my_strcpy(char *dest, char *src)
{
  int   length;
  int   i;
  
  length = my_strlen(src);
  for (i = 0; i < length; i++)
    {
      dest[i] = src[i];
    }
  dest[length] = '\0';
  return (dest);
}

char    *my_strncpy(char *dest, char *src, int n)
{
  int   length_src;
  int   i;
  
  length_src = my_strlen(src);
  for (i = 0; i < n; i++)
    {
      if (i < length_src)
	{
	  dest[i] = src[i];
	}
      else
	{
	  if (i == length_src)
	    {
	      dest[i] = '\0';
	    }
	  else
	    {
	      dest[i] = 0;
	    }
	}
    }
  return (dest);
}

char    *my_strcat(char *str1, char *str2)
{
  int   length1;
  int   length2;
  int   length;
  int i;

  length1 = my_strlen(str1);
  length2 = my_strlen(str2);
  length = length1 + length2 + 1;
  for (i = 0; i < length2; i++)
    {
      *(str1 + length1 + i) = str2[i];
    }
  *(str1 + length - 1) = '\0';
  return (str1);
}

char    *my_strncat(char *str1, char *str2, int n)
{
  int   length1;
  int   length2;
  int i;

  length1 = my_strlen(str1);
  length2 = my_strlen(str2);
  for (i = 0; i < n; i++)
    {
      if (i < length2)
	*(str1 + length1 + i) = str2[i];
      else
	*(str1 + length1 + i) = 0;
    }
  if (i > length2)
    *(str1 + length1 + i) = '\0';
  return (str1);
}
