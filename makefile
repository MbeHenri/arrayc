#---------------------#
#  1.                 #
#  VARIABLES          #
#---------------------#

#-> Compilation
#	+ compilateur $(CC)
CC = gcc
#	+ parametres du compilateur
CFLAGS = -W -Wall -lm

#-> Dossiers utiles
#   + dev [dossier de devellopement]
#		- tmp [dossier temporaire utile pour contenir les binaires de devellopement et autres fichiers temporaires]
dir_dev_tmp = dev/tmp
#		- lib/header [dossier d'entete des librairies]
dir_dev_lib_h = dev/lib/header
#		- lib/source [dossier de sources des librairies]
dir_dev_lib_s = dev/lib/source
#		- lib/test [dossier des sources de test de librairie]
dir_dev_lib_t = dev/lib/test

#   + dist [dossier de distribution]
#		- lib [dossier des librairies utilisable pour la compilation et l'execution]
dir_dist_lib = dist/lib
 
#---------------------------------#
#  2.                             #
#  COMMANDES DE DEVELLOPEMENT     #
#---------------------------------#


#---------------------------------#
#  3.                             #
#  COMMANDES DE DEPLOIMENT        #
#---------------------------------#


#---------------------------------#
#  4.                             #
#  COMMANDES GENERIQUES           #
#---------------------------------#