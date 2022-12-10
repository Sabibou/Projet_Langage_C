#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"

#ifndef DEPLACEMENT	
#define DEPLACEMENT

int deplacement_possible(int **plateau, int taille, int x, int y, char direc, int entite);
void deplacememt(int ** plateau, int taille, int *x, int *y);
int detect_fin(int **plateau, int taille);



#endif 