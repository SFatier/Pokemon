/*
** libmy.h for  in /home/jsdurier/Piscine_C/Chifumi/durier_j/chifumi/libmy
** 
** Made by DURIER Jean-Samuel
** Login   <durier_j@etna-alternance.net>
** 
** Started on  Fri Apr  1 22:53:19 2016 DURIER Jean-Samuel
** Last update Fri Apr  1 22:57:21 2016 DURIER Jean-Samuel
*/
void    my_putchar(char c);
int     my_isneg(int n);
void    my_put_nbr(int nb);
void    my_swap(int *a, int *b);
void    my_putstr(char *str);
int     my_strlen(char *str);
int     my_getnbr(char *str);
char    *my_strcpy(char *dest, char *src);
char    *my_strncpy(char *dest, char *src, int n);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strcat(char *str1, char *str2);
char    *my_strncat(char *str1, char *str2, int n);
char    *my_strstr(char *str, char *to_find);
char    *my_strdup(char *str);
char    **my_str_to_wordtab(char *str);
