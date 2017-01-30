/*
** my_ftp.h for my_ftp.h in /home/bashir_s/rendu/PSU_2014_myftp
** 
** Made by sulman bashir
** Login   <bashir_s@epitech.net>
** 
** Started on  Wed Mar 25 17:35:51 2015 sulman bashir
** Last update Fri Apr 10 14:58:36 2015 sulman bashir
*/

#ifndef _MY_FTP_H_
# define _MY_FTP_H_

typedef struct s_client
{
  int		s;
  int		port;
  int		error;
  char		*str;
  int		cs;
  int		client_len;
}		t_client;

typedef struct s_server
{
  int		s;
  int		port;
  int		error;
  char		*str;
  char		*str2;
  int		cs;
  fd_set	readfds;
  int		my_select;
  int		client_len;
}	       t_server;

char	**my_str_to_wordtab(char *str);
char	**my_str_to_wordtab_preview(char **point, char *str, int i, int k);
char	*my_malloc_check(char *str);
void	my_cdup(int cs, char *env);
int	my_cwd(int cs, char *env, char *stock);
void	getusername(int cs);
void	getpwd(int cs);
void	my_ls(int cs);
int	do_client(int cs);
void	socket_error(int s);
void	connect_error(int error);
void	argument_check(int ac);
void	bind_error(int error, int s);
void	listen_error(int error, int s);
void	accept_error(int error, int s);
void	socket_error(int s);
int	connection(char *str, int cs, int error, int s);

#endif
