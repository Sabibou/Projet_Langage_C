#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "deplacement.h"
#include "niveau_fichier.h"
//-1 : mur, 1 :pers, 2 :caisse, 0 : vide, 3:objectif, 5:caisse sur objectif ,4:perso sur objectif


int main(){
	int **tab=malloc(sizeof(int*)*10);
	if(tab==NULL){
		printf("probleme tab");
	}
	for(int i=0;i<10;i++){
		tab[i]=malloc(sizeof(int)*10);
		if(tab[i]==NULL){
			printf("probleme tab[i]");
			for(int k;k<i;k++){
				free(tab[k]);
			}
			free(tab);
		}

	}
	fichier_to_level("level.txt", tab);
	int a,b;
	int complete=0;
	int *x=&a,*y=&b;  //coord perso
	a=3;
	b=3;

	while(complete==0){
		system("clear");
		//affiche_tab_2D(tab,10,10);
		affichage(tab, 10);
		complete=detect_fin(tab, 10);
		deplacememt(tab,10,x,y);
	}
	for(int i=0;i<5;i++){
		free(tab[i]);
	}
	free(tab);
	return 0;
}