#include <stdio.h>
#include <stdlib.h>


#include "affichage.h"

void affichage(int **plateau, int taille){

	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			if(plateau[i][j]==-1){
				printf("#");
			}
			else if(plateau[i][j]==1){
				printf("P");
			}
			else if(plateau[i][j]==4){
				printf("P");
			}
			else if(plateau[i][j]==0){
				printf(" ");
			}
			else if(plateau[i][j]==2){
				printf("c");
			}
			else if(plateau[i][j]==5){
				printf("ç");
			}
			else{
				printf("I");
			}
		}
		printf("\n");
	}
}

void affiche_tab_2D(int **t, int n, int m){
	for(int i=0; i<n; i++){
		printf("|");
		for(int j=0;j<m;j++){
			printf(" %d |", t[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}