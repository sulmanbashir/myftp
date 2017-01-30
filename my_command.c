/*
** my_command.c for my_command in /home/bashir_s/rendu/PSU_2014_myftp
** 
** Made by sulman bashir
** Login   <bashir_s@epitech.net>
** 
** Started on  Wed Mar 25 18:43:37 2015 sulman bashir
** Last update Sun Mar 29 23:33:29 2015 sulman bashir
*/

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include "my_ftp.h"

void	my_cdup(int cs, char *env)
{
  write(cs, env, strlen(env));
  if (chdir(env) == -1)
    write(cs, "xxx Error", strlen("xxx Error"));
  else
    write(cs, "200 Command okay.", strlen("200 Command okay."));
}

int	my_cwd(int cs, char *env, char *stock)
{
  DIR	*dp;
  char	*add_slash;
  char	*buffer;
  char	**cmd;

  cmd = my_str_to_wordtab(stock);
  add_slash = strcat(env, "/");
  if (cmd[1] == NULL)
    write(cs, "xxx Error", 9);
  else if ((dp = opendir(cmd[1])) == NULL)
    {
      write(cs, "Cannot open directory", strlen("Cannot open directory"));
      return (-1);
    }
  buffer = strcat(add_slash, cmd[1]);
  write(cs, "250 Requested file action okay, completed.", 41);
  if (chdir(buffer) == -1)
    write(cs, "xxx Error", strlen("xxx Error"));
  return (0);
}

void	getusername(int cs)
{
  char	*name;

  name = getenv("USER");
  write(cs, name, strlen(name));
}

void	getpwd(int cs)
{
  char  *path;

  path = getenv("PWD");
  write(cs, "257 'PATHNAME' created.\n", strlen("257 'PATHNAME' created.\n"));
  write(cs, path, strlen(path));
}

void	my_ls(int cs)
{
  int	pid;
  int	status;

  pid  = fork();
  if (pid > 0)
    wait(&status);
  else if (pid == 0)
    {
      dup2(cs, 1);
      execl("/bin/ls", "ls", "-a", "-l",  NULL);
      write(cs, "226 Closing data connection.", 28);
    }
}
