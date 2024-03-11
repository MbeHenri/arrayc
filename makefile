#---------------------#
#  0.                 #
#  VARIABLES          #
#---------------------#

#-> Compilation
#	+ compilateur $(CC)
CC = gcc
#	+ parametres du compilateur
CFLAGS = -W -Wall -lm -fPIC -Wextra

#-> Devellopement
dir_dev = ./dev
#		- tmp [dossier temporaire utile pour contenir les binaires de devellopement et autres fichiers temporaires]
dir_dev_tmp = $(dir_dev)/tmp
#		- lib/header [dossier d'entete des librairies]
dir_dev_lib_h = $(dir_dev)/lib/header
#		- lib/source [dossier de sources des librairies]
dir_dev_lib_s = $(dir_dev)/lib/source
#		- test [dossier des sources de test de librairie]
dir_dev_lib_t = $(dir_dev)/test

#-> Distribution
NAME_LIBRARY = arrayc

MASTER_VERSION = 1
MINOR_VERSION = 0
SUB_MINOR_VERSION = 0
VERSION_LIBRARY =$(MASTER_VERSION).$(MINOR_VERSION).$(SUB_MINOR_VERSION)

DIR_DIST_LIBRARY =./dist/$(NAME_LIBRARY)
DIR_INCLUDE_DIST_LIBRARY =$(DIR_DIST_LIBRARY)/include
DIR_LIB_DIST_LIBRARY =$(DIR_DIST_LIBRARY)/lib

#-> Deploiement
DIR_SYSTEM_LIBRARY =/usr/local
INCLUDE_DIR_SYSTEM_LIBRARY =$(DIR_SYSTEM_LIBRARY)/include
LIB_DIR_SYSTEM_LIBRARY =$(DIR_SYSTEM_LIBRARY)/lib

#-> Autres variables
liste_sources =$(dir_dev_lib_s)/arrayc.c $(dir_dev_lib_s)/base.c
liste_objets =$(dir_dev_tmp)/arrayc.o $(dir_dev_tmp)/base.o

#---------------------------------#
#  1.                             #
#  COMMANDES DE DISTRIBUTION      #
#---------------------------------#
base.o : $(dir_dev_lib_s)/base.c
	mkdir $(dir_dev_tmp) -p
	$(CC) -c $(dir_dev_lib_s)/base.c -o $(dir_dev_tmp)/base.o $(CFLAGS)

arrayc.o : $(dir_dev_lib_s)/arrayc.c
	mkdir $(dir_dev_tmp) -p
	$(CC) -c $(dir_dev_lib_s)/arrayc.c -o $(dir_dev_tmp)/arrayc.o $(CFLAGS)

build : base.o arrayc.o
	mkdir ./dist -p
	mkdir $(DIR_DIST_LIBRARY) -p
	mkdir $(DIR_INCLUDE_DIST_LIBRARY) -p
	cp -r $(dir_dev_lib_h)/* $(DIR_INCLUDE_DIST_LIBRARY)
	
	mkdir $(DIR_LIB_DIST_LIBRARY) -p
	mkdir $(dir_dev_tmp) -p
	
	gcc -shared $(liste_objets) -o $(DIR_LIB_DIST_LIBRARY)/libarrayc.so.$(VERSION_LIBRARY) -fPIC -Wl,-soname,libarrayc.so.$(MASTER_VERSION)

#--------------------------------------------#
#  2.                                        #
#  COMMANDES D'INSTALLATION/SUPPRESSION      #
#--------------------------------------------#
install : build
	
	mkdir $(LIB_DIR_SYSTEM_LIBRARY)/arrayc -p
	mkdir $(INCLUDE_DIR_SYSTEM_LIBRARY)/arrayc -p
	
	cp -r $(DIR_INCLUDE_DIST_LIBRARY)/* $(INCLUDE_DIR_SYSTEM_LIBRARY)/arrayc
	cp -r $(DIR_LIB_DIST_LIBRARY)/* $(LIB_DIR_SYSTEM_LIBRARY)/arrayc
	
	ln -s $(LIB_DIR_SYSTEM_LIBRARY)/arrayc/libarrayc.so.1.0.0 $(LIB_DIR_SYSTEM_LIBRARY)/libarrayc.so.1
	ln -s $(LIB_DIR_SYSTEM_LIBRARY)/libarrayc.so.1 $(LIB_DIR_SYSTEM_LIBRARY)/libarrayc.so
	ldconfig

remove : 
	rm -rf $(LIB_DIR_SYSTEM_LIBRARY)/arrayc
	rm -rf $(INCLUDE_DIR_SYSTEM_LIBRARY)/arrayc
	rm -rf $(LIB_DIR_SYSTEM_LIBRARY)/libarrayc.so*
	ldconfig

#-------------------------#
#  2.                     #
#  COMMANDES DE TEST      #
#-------------------------#
testArrayc : $(dir_dev_lib_t)/testArrayc.c
	mkdir $(dir_dev_tmp) -p
	$(CC) $(dir_dev_lib_t)/testArrayc.c -o $(dir_dev_tmp)/testArrayc -l arrayc $(CFLAGS)