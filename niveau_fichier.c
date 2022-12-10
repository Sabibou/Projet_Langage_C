#include <stdio.h>
#include <stdlib.h>

#include "niveau_fichier.h"


void level_to_fichier(char *fichier, int** plateau){
	FILE *f=fopen(fichier, "w");
	if(f==NULL){
		exit(-1);
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			fprintf(f,"%d ",plateau[i][j]);
		}
	}
	fclose(f);
}

void fichier_to_level(char * fichier, int **plateau){
	FILE *f=fopen(fichier, "r");
	if(f==NULL){
		exit(-1);
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			fscanf(f,"%d ",&plateau[i][j]);
		}
	}
	fclose(f);
}