##
## Makefile for Makefile in /home/guiho_r/projet/myscript
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Mon Feb 18 11:13:16 2013 ronan guiho
## Last update Sun Mar 31 17:02:59 2013 ronan guiho
##

NAME 		= gameboard

SRC_DIR		= ./src/
INC_DIR		= ./inc/
MESSAGE_DIR	= ../message/
LIST_DIR	= ../list/

PATH_MOD_WIN	= window
PATH_MOD_BOARD	= board
PATH_MOD_RUN	= run
PATH_MOD_GAME	= game
PATH_MOD_TOOL	= tool

SRC		= $(SRC_DIR)main.c \
		  $(SRC_DIR)$(PATH_MOD_TOOL)/color.c \
		  $(SRC_DIR)$(PATH_MOD_GAME)/team.c \
		  $(SRC_DIR)$(PATH_MOD_GAME)/player.c \
		  $(SRC_DIR)$(PATH_MOD_GAME)/display.c \
		  $(SRC_DIR)$(PATH_MOD_GAME)/victory.c \
		  $(SRC_DIR)$(PATH_MOD_GAME)/display_team.c \
		  $(SRC_DIR)$(PATH_MOD_BOARD)/console.c \
		  $(SRC_DIR)$(PATH_MOD_RUN)/run.c \
		  $(SRC_DIR)$(PATH_MOD_RUN)/run_init.c \
		  $(SRC_DIR)$(PATH_MOD_RUN)/run_wait.c \
		  $(SRC_DIR)$(PATH_MOD_RUN)/run_message.c \
		  $(SRC_DIR)$(PATH_MOD_RUN)/run_message_client.c \
		  $(SRC_DIR)$(PATH_MOD_WIN)/window.c \
		  $(SRC_DIR)$(PATH_MOD_WIN)/font.c \
		  $(SRC_DIR)$(PATH_MOD_WIN)/window_func.c \
		  $(SRC_DIR)$(PATH_MOD_BOARD)/board.c \
		  $(SRC_DIR)$(PATH_MOD_BOARD)/board_func.c

OBJ		= $(SRC:.c=.o)

LDFLAGS		= -L $(LIST_DIR) -llist -L $(MESSAGE_DIR) -lmsg -lSDL -lSDL_ttf -lSDL_mixer

CFLAGS		+= -W -Wall -Wextra -O3
CFLAGS		+= -I $(INC_DIR) -I $(MESSAGE_DIR)inc/ -I $(LIST_DIR)inc/ -I/usr/lib64/

CC		= gcc `pkg-config --cflags --libs sdl`
DEL_FILE	= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@cd $(MESSAGE_DIR) && $(MAKE)
		@cd $(LIST_DIR) && $(MAKE)
		$(CC) -o $@ $^ $(LDFLAGS)

%.o:		%.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		$(DEL_FILE) $(OBJ)

fclean:		clean
		$(DEL_FILE) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re