##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile lib and source or execute unit test
##

# VARIABLES
# ----------------------->
SILENT = @

EXEC =	my_defender
OBJ_FOLDER =	objects/

SRC	=	main.c \
		init_data.c \
		init_map.c \
		init_tower.c \
		init_convoy.c \
		start.c \
		animation.c \
		points_list.c \
		update_mob.c \
		event_map.c \
		gest_tower.c \
		gest_tower2.c \
		event_tower.c \
		disp_tower.c \
		click_tower.c \
		set_pos_tower.c \
		init_texture_tower.c \
		disp_tower_fire.c \
		change_angle.c \
		move.c \
		anim_proj.c \
		tower.c

SRC_OBJ_FOLDER =	$(OBJ_FOLDER)src/
SRC_OBJ	=	$(patsubst %.c, $(SRC_OBJ_FOLDER)%.o, $(SRC))

INCLUDE =	-I include/ -I Librairy/include/
# ----------------------->

# LIBRAIRIE
# ----------------------->
LIB_NAME =	-l utils
LIB_FOLDER =	-L Librairy/
LFOLDER =	Librairy/
LIB_EXT =	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm
# ----------------------->

# MODE
# ----------------------->
MODE =  debug
FAST = 	fast
DEBUG = 	debug
DEFAULT = 	default
# ----------------------->

# FLAG
# ----------------------->
ifeq ($(MODE), debug)
FLAG =	#-Wall -Wextra -pedantic -g3

else ifeq ($(MODE), fast)
FLAG =	#-Wall -Wextra -pedantic -Ofast

else
FLAG = 	#-Wall -Wextra -pedantic

endif
# ----------------------->

# COMPILE
# ----------------------->
all:	lib directories $(EXEC)

directories:
	$(SILENT)mkdir -p $(OBJ_FOLDER)
	$(SILENT)mkdir -p $(SRC_OBJ_FOLDER)

objects/src/%.o : %.c
	$(SILENT)gcc -c -o $@ $< $(FLAG) $(INCLUDE)

$(EXEC): $(SRC_OBJ)
	$(SILENT)gcc -o $(EXEC) $(SRC_OBJ) $(LIB_FOLDER) $(LIB_NAME) $(LIB_EXT) $(INCLUDE) $(FLAG) 
# ----------------------->

# COMPILE LIB
# ----------------------->
lib:
	$(SILENT)make -C $(LFOLDER)

libre:
	$(SILENT)make -C $(LFOLDER) re

libclean:
	$(SILENT)make -C $(LFOLDER) clean

libfclean:
	$(SILENT)make -C $(LFOLDER) fclean
# ----------------------->

# CHANGE MODE
# ----------------------->
debug:
	$(SILENT)sed -i "s/MODE =  $(MODE)/MODE =  $(DEBUG)/" Makefile

fast:
	$(SILENT)sed -i "s/MODE =  $(MODE)/MODE =  $(FAST)/" Makefile

default:
	$(SILENT)sed -i "s/MODE =  $(MODE)/MODE =  $(DEFAULT)/" Makefile
# ----------------------->

# CLEAN
# ----------------------->
clean:	libclean
	$(SILENT)rm -f header.h.gch
	$(SILENT)rm -f vgcore.*
	$(SILENT)rm -rf .vscode

fclean: libfclean clean
	$(SILENT)rm -rf objects/
	$(SILENT)rm -f *.gc*
	$(SILENT)rm -f $(UT_NAME)
	$(SILENT)rm -f $(EXEC)
# ----------------------->

re: libre fclean all

.PHONY: clean fclean re