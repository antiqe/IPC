##
## Makefile for Makefile in /home/guiho_r/projet/myscript
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Mon Feb 18 11:13:16 2013 ronan guiho
## Last update Sat Mar 30 19:02:20 2013 alexis leprovost
##

NAME		= lemipc

SRC_DIR		= ./src/
INC_DIR		= ./inc/
MESSAGE_DIR	= ../message/

SRC		= $(SRC_DIR)main.c \
		  $(SRC_DIR)hash.c \
		  $(SRC_DIR)init.c \
		  $(SRC_DIR)run.c \
		  $(SRC_DIR)lock.c \
		  $(SRC_DIR)action.c \
		  $(SRC_DIR)ia.c \
		  $(SRC_DIR)leader.c \

OBJ		= $(SRC:.c=.o)

LDFLAGS		= -lm -L $(MESSAGE_DIR) -lmsg

CFLAGS		+= -W -Wall -Werror -Wextra -O3
CFLAGS		+= -I $(INC_DIR) -I $(MESSAGE_DIR)inc/

CC		= gcc
DEL_FILE	= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@cd $(MESSAGE_DIR) && $(MAKE)
		$(CC) -o $@ $^ $(LDFLAGS)

%.o:		%.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		$(DEL_FILE) $(OBJ)

fclean:		clean
		$(DEL_FILE) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re