/*
** str_to_wordtab.c for str_to_wordtab in /home/bashir_s/rendu/PSU_2014_myftp
** 
** Made by sulman bashir
** Login   <bashir_s@epitech.net>
** 
** Started on  Wed Mar 25 17:35:33 2015 sulman bashir
** Last update Wed Mar 25 19:15:43 2015 sulman bashir
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_ftp.h"

char    **my_str_to_wordtab(char *str)
{
  int   i;
  int   k;
  char  **point;
  int   count;

  i = 0;
  k = 0;
  count = strlen(str);
  if ((point = malloc(count * sizeof(char*))) == NULL)
    {
      printf("\nError in malloc()\n");
      return (NULL);
    }
  while (i <= count)
    point[i++] = malloc(1024 * sizeof(char));
  if (point == NULL)
    printf("\nError\n");
  point = my_str_to_wordtab_preview(point, str, i, k);
  return (point);
}

char    **my_str_to_wordtab_preview(char  **point, char *str, int i, int k)
{
  int   j;

  i = 0;
  j = 0;
  k = 0;
  while (str[i])
    {
      while ((str[i] == ':' || str[i] == ' ') && str[i] != '\0')
        i++;
      if (str[i] != '\0')
        {
          while (str[i] != ':' && str[i] != ' ' && str[i] != '\0')
            {
              point[j][k] = str[i];
              i++;
              k++;
            }
        }
      point[j][k] = '\0';
      j++;
      k = 0;
    }
  point[j] = NULL;
  i = 0;
  return (point);
}
