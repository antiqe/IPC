##
## Makefile for Makefile in /home/guiho_r/projet/myscript
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Mon Feb 18 11:13:16 2013 ronan guiho
## Last update Thu Mar 28 17:44:34 2013 ronan guiho
##

NAME 		= libmsg.a

SRC_DIR		= ./src/
INC_DIR		= ./inc/

SRC		= $(SRC_DIR)send.c \
		  $(SRC_DIR)recv.c

OBJ		= $(SRC:.c=.o)

LDFLAGS		=

CFLAGS		+= -W -Werror -Wall -Wextra -fPIC -O3 -g
CFLAGS		+= -I $(INC_DIR)

CC		= gcc
AR		= ar rcs
DEL_FILE	= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $@ $^ $(LDFLAGS)
		ranlib $@

%.o:		%.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		$(DEL_FILE) $(OBJ)

fclean:		clean
		$(DEL_FILE) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re