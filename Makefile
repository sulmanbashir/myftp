##
## Makefile for Makefile in /home/bashir_s/rendu/PSU_2014_myftp
## 
## Made by sulman bashir
## Login   <bashir_s@epitech.net>
## 
## Started on  Sun Mar 22 21:08:20 2015 sulman bashir
## Last update Sun Jul 19 13:37:55 2015 sulman bashir
##

CC	= gcc

RM	= rm -f

##CFLAGS 	+= -Wextra -Wall -Wextra -Werror

SRC_CLI	= clients/client.c \
	  clients/error_cli.c

SRC_SER	= server/server.c \
	  str_to_wordtab.c \
	  my_command.c \
	  server/error.c


OBJ_CLI	= $(SRC_CLI:.c=.o)

OBJ_SER	= $(SRC_SER:.c=.o)

NAME_C	= client

NAME_S	= serveur

all:	$(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_CLI)
	$(CC) -o $(NAME_C) $(SRC_CLI)

$(NAME_S): $(OBJ_SER)
	$(CC) -o $(NAME_S) $(SRC_SER)

clean:
	$(RM) $(OBJ_SER)
	$(RM) $(OBJ_CLI)

fclean: clean
	$(RM) $(NAME_S)
	$(RM) $(NAME_C)

re: fclean all
