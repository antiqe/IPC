##
## Makefile for Makefile in /home/guiho_r/projet/objdump/nm
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Wed Mar  6 09:50:55 2013 ronan guiho
## Last update Thu Mar 28 17:05:01 2013 alexis leprovost
##

NAME		=	liblist.a

SRC_DIR		= 	./src/
INC_DIR		= 	./inc/

SRC		=	$(SRC_DIR)list.c \
			$(SRC_DIR)list1.c \
			$(SRC_DIR)list2.c

OBJ		=	$(SRC:.c=.o)

LDFLAGS		=

CFLAGS		+= 	-W -Werror -Wall -Wextra -fPIC -O3
CFLAGS		+= 	-I $(INC_DIR)

CC		=	gcc
AR		= 	ar rcs
DEL_FILE	=	rm -f


all:			$(NAME)

$(NAME):		$(OBJ)
			$(AR) $@ $^ $(LDFLAGS)
			ranlib $@

%.o:			%.c
			$(CC) -o $@ -c $< $(CFLAGS)

clean:
			$(DEL_FILE) $(OBJ)

fclean:			clean
			$(DEL_FILE) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re