#---------------------#
#  0.                 #
#  VARIABLES          #
#---------------------#

#-> Compilation
#	+ compilateur $(CC)
CC = gcc
#	+ parametres du compilateur
CFLAGS = -W -Wall -lm -fPIC

#-> Dossiers utiles
#   + dev [dossier de devellopement]
dir_dev = ./dev
#		- tmp [dossier temporaire utile pour contenir les binaires de devellopement et autres fichiers temporaires]
dir_dev_tmp = $(dir_dev)/tmp
#		- lib/header [dossier d'entete des librairies]
dir_dev_lib_h = $(dir_dev)/lib/header
#		- lib/source [dossier de sources des librairies]
dir_dev_lib_s = $(dir_dev)/lib/source
#		- lib/test [dossier des sources de test de librairie]
dir_dev_lib_t = $(dir_dev)/lib/test

#   + dist [dossier de distribution]
dir_dist = ./dist
#		- lib [dossier des librairies utilisable pour la compilation et l'execution]
dir_dist_lib = $(dir_dist)/lib

#-> Librairies

#---------------------------------#
#  2.                             #
#  COMMANDES DE DEVELLOPEMENT     #
#---------------------------------#

#-> variables
ouput_dev_obj =$(dir_dev_tmp)/obj
ouput_dev_bin =$(dir_dev_tmp)/bin
l1 =$(ouput_dev_obj)/arrayc.o $(ouput_dev_obj)/base.o
liste_objets =$(l1)

#-> Librairies
base.o : $(dir_dev_lib_s)/base.c
	mkdir $(dir_dev_tmp) -p
	mkdir $(ouput_dev_obj) -p
	$(CC) -c $(dir_dev_lib_s)/base.c -o $(ouput_dev_obj)/base.o $(CFLAGS)

arrayc.o : $(dir_dev_lib_s)/arrayc.c
	mkdir $(dir_dev_tmp) -p
	mkdir $(ouput_dev_obj) -p
	$(CC) -c $(dir_dev_lib_s)/arrayc.c -o $(ouput_dev_obj)/arrayc.o $(CFLAGS)

libarrayc : $(liste_objets)
	gcc -o libarrayc.so -shared $(liste_objets)
	
install : ./libarrayc.so
	cp libarrayc.so /usr/local/lib
	chmod -R 777 /usr/local/lib/libarrayc.so

remove : 
	rm -rf /usr/local/lib/libarrayc.so

#-> binaires de test
testBase :  $(liste_objets) $(dir_dev_lib_t)/testBase.c
	$(CC) -c $(dir_dev_lib_t)/testBase.c -o $(ouput_dev_obj)/testBase.o $(CFLAGS)
	$(CC) $(ouput_dev_obj)/testBase.o $(liste_objets) -o $(ouput_dev_bin)/testBase $(CFLAGS)

testBase_launch :  $(ouput_dev_bin)/testBase
	./$(ouput_dev_bin)/testBase

testArrayc :  $(liste_objets) $(dir_dev_lib_t)/testArrayc.c
	$(CC) -c $(dir_dev_lib_t)/testArrayc.c -L/usr/local/lib -larrayc -o $(ouput_dev_obj)/testArrayc.o $(CFLAGS)
	$(CC) $(ouput_dev_obj)/testArrayc.o -o $(ouput_dev_bin)/testArrayc $(CFLAGS)
	
testArrayc_launch :  $(ouput_dev_bin)/testArrayc
	./$(ouput_dev_bin)/testArrayc

#---------------------------------#
#  3.                             #
#  COMMANDES DE DEPLOIMENT        #
#---------------------------------#


#---------------------------------#
#  4.                             #
#  COMMANDES GENERIQUES           #
#---------------------------------#