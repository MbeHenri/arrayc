#---------------------#
#  0.                 #
#  VARIABLES          #
#---------------------#

#-> Compilation
#	+ compilateur $(CC)
CC = gcc
#	+ parametres du compilateur
CFLAGS = -W -Wall -lm -fPIC -Wextra

#-> Dossier de devellopement 
dir_dev = ./dev
#		- tmp [dossier temporaire utile pour contenir les binaires de devellopement et autres fichiers temporaires]
dir_dev_tmp = $(dir_dev)/tmp
#		- lib/header [dossier d'entete des librairies]
dir_dev_lib_h = $(dir_dev)/lib/header
#		- lib/source [dossier de sources des librairies]
dir_dev_lib_s = $(dir_dev)/lib/source
#		- lib/test [dossier des sources de test de librairie]
dir_dev_lib_t = $(dir_dev)/lib/test

#-> Dossier de distribution
NAME_LIBRARY = arrayc

DIR_DIST_LIBRARY =./$(NAME_LIBRARY)
DIR_INCLUDE_DIST_LIBRARY =./$(NAME_LIBRARY)/include
DIR_LIB_DIST_LIBRARY =./$(NAME_LIBRARY)/lib

#-> Autres variables
liste_sources =$(dir_dev_lib_s)/arrayc.c $(dir_dev_lib_s)/base.c
liste_objets =$(dir_dev_tmp)/arrayc.o $(dir_dev_tmp)/base.o

#---------------------------------#
#  1.                             #
#  COMMANDES DE DISTRIBUTION      #
#---------------------------------#
build : $(liste_sources)
	mkdir $(DIR_DIST_LIBRARY) -p
	mkdir $(DIR_INCLUDE_DIST_LIBRARY) -p
	cp -r $(dir_dev_lib_h)/* $(DIR_INCLUDE_DIST_LIBRARY)
	
	mkdir $(DIR_INCLUDE_DIST_LIBRARY) -p
	mkdir $(dir_dev_tmp) -p
	$(CC) -c $(liste_sources) $(CFLAGS)
	
	gcc -shared $(liste_objets) -o $(DIR_INCLUDE_DIST_LIBRARY)/libarrayc.so.1.0.0 -fPIC -Wl,-soname,libarrayc.so.1

#--------------------------------------------#
#  2.                                        #
#  COMMANDES D'INSTALLATION/SUPPRESSION      #
#--------------------------------------------#
install :
	
	mkdir /usr/local/lib/arrayc -p
	mkdir /usr/local/include/arrayc -p
	
	cp -r $(DIR_INCLUDE_DIST_LIBRARY)/* /usr/local/include/arrayc
	cp -r $(DIR_INCLUDE_DIST_LIBRARY)/* /usr/local/lib/arrayc
	
	chmod -R 777 /usr/local/lib/arrayc
	chmod -R 777 /usr/local/include/arrayc
	
	ln -s /usr/local/lib/arrayc/libarrayc.so.1.0.0 /usr/local/lib/libarrayc.so.1
	ln -s /usr/local/lib/libarrayc.so.1 /usr/local/lib/libarrayc.so
	ldconfig

remove : 
	rm -rf /usr/local/lib/arrayc
	rm -rf /usr/local/include/arrayc
	rm -rf /usr/local/lib/lib*.so
	ldconfig

#-------------------------#
#  2.                     #
#  COMMANDES DE TEST      #
#-------------------------#
testArrayc : $(dir_dev_lib_t)/testArrayc.c
	mkdir $(dir_dev_tmp) -p
	$(CC) $(dir_dev_lib_t)/testArrayc.c -o $(dir_dev_tmp)/testArrayc -l arrayc $(CFLAGS)