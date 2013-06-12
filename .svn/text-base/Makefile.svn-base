##
## Makefile for Makefile in /home/guiho_r/projet/lemipc
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Wed Mar 27 10:14:06 2013 ronan guiho
## Last update Thu Mar 28 20:33:20 2013 alexis leprovost
##

DEBUG		=	NO

GAMEBOARD	=	gameboard
LEMIPC		=	lemipc

EXEC		=	$(LEMIPC) $(GAMEBOARD)

GAMEBOARD_DIR	=	./module/gameboard/
LEMIPC_DIR	=	./module/lemipc/
MESSAGE_DIR	=	./module/message/

DEL_FILE	=	rm -f

ifeq ($(DEBUG), YES)
 export CFLAGS +=	-g
endif

all:			$(EXEC)

$(GAMEBOARD):
			@cd $(GAMEBOARD_DIR) && $(MAKE)
			@cp $(GAMEBOARD_DIR)$@ .
$(LEMIPC):
			@cd $(LEMIPC_DIR) && $(MAKE)
			@cp $(LEMIPC_DIR)$@ .

clean:
			@cd $(GAMEBOARD_DIR) && $(MAKE) clean
			@cd $(LEMIPC_DIR) && $(MAKE) clean

fclean:
			@cd $(GAMEBOARD_DIR) && $(MAKE) fclean
			@cd $(LEMIPC_DIR) && $(MAKE) fclean
			@$(DEL_FILE) $(EXEC)

re:			fclean all

.PHONY:			all clean fclean re