#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "deplacement.h"


int deplacement_possible(int **plateau, int taille, int x, int y, char direc, int entite){ //x,y coord de lentite dans le tableau
	if (direc=='h'){
		if (x>0){
			if(entite!=2 && (plateau[x-1][y]==2 || plateau[x-1][y]==5)){
				return deplacement_possible(plateau, taille, x-1,y,'h',2);
			}
			else if(plateau[x-1][y]==0 || plateau[x-1][y]==3 ){
				return 1;
			}
		}
	}
	else if (direc=='b'){
		if (x<taille-1){
			if(entite!=2 && (plateau[x+1][y]==2 || plateau[x+1][y]==5) ){
				return deplacement_possible(plateau,taille, x+1,y,'b',2);
			}
			else if(plateau[x+1][y]==0 || plateau[x+1][y]==3 ){
				return 1;
			}
		}
	}
	else if (direc=='d'){
		if (y<taille-1){
			if(entite!=2 && (plateau[x][y+1]==2 || plateau[x][y+1]==5) ){
				return deplacement_possible(plateau,taille, x,y+1,'d',2);
			}
			else if(plateau[x][y+1]==0 || plateau[x][y+1]==3 ){
				return 1;
			}
		}
	}
	else{ //direct=='g'
		if (y>0){
			if(entite!=2 && (plateau[x][y-1]==2 || plateau[x][y-1]==5)){
				return deplacement_possible(plateau,taille,x,y-1,'g',2);
			}
			else if(plateau[x][y-1]==0 || plateau[x][y-1]==3 ){
				return 1;
			}
		}
	}
	return 0;

}

void deplacememt(int ** plateau, int taille, int *x, int *y){

	int direc;
	int val;
	//scanf("%c",&direc);
	direc = getchar();
	if (direc=='h'){
		if(deplacement_possible(plateau, taille, *x, *y, direc, 1)==1){
			plateau[*x][*y]-=1;
			if(plateau[*(x)-1][*(y)]==5){
				plateau[*(x)-1][*(y)]=4;
				plateau[*(x)-2][*(y)]=2;
			}
			else if(plateau[*(x)-1][*(y)]==3){
				plateau[*(x)-1][*(y)]=4;
			}
			else{
				val=plateau[*(x)-1][*(y)];
				plateau[*(x)-1][*(y)]=1;
				plateau[*(x)-2][*(y)]+=val;	
			}
			*x-=1;	
		}
	}
	else if (direc=='b'){
		if(deplacement_possible(plateau, taille, *x, *y, direc, 1)==1){
			plateau[*x][*y]-=1;
			if(plateau[*(x)+1][*y]==5){
				plateau[*(x)+1][*y]=4;
				plateau[*(x)+2][*y]=2;
			}
			else if(plateau[*(x)+1][*(y)]==3){
				plateau[*(x)+1][*(y)]=4;
			}
			else{
				val=plateau[*(x)+1][*y];
				plateau[*(x)+1][*y]=1;
				plateau[*(x)+2][*y]+=val;	
			}
			*x+=1;	
		}
	}
	else if (direc=='g'){
		if(deplacement_possible(plateau, taille, *x, *y, direc, 1)==1){

			plateau[*x][*y]-=1;
			if(plateau[*x][*(y)-1]==5){
				plateau[*x][*(y)-1]=4;
				plateau[*x][*(y)-2]=2;
			}
			else if(plateau[*(x)][*(y)-1]==3){
				plateau[*(x)][*(y)-1]=4;
			}
			else{
				val=plateau[*x][*(y)-1];
				plateau[*x][*(y)-1]=1;
				plateau[*x][*(y)-2]+=val;	
			}
			*y-=1;	
		}
	}
	else if (direc=='d'){
		if(deplacement_possible(plateau, taille, *x, *y, direc, 1)==1){

			plateau[*x][*y]-=1;
			if(plateau[*x][*(y)+1]==5){
				plateau[*x][*(y)+1]=4;
				plateau[*x][*(y)+2]=2;
			}
			else if(plateau[*(x)][*(y)+1]==3){
				plateau[*(x)][*(y)+1]=4;
			}
			else{
				val=plateau[*x][*(y)+1];
				plateau[*x][*(y)+1]=1;
				plateau[*x][*(y)+2]+=val;	
			}
			*y+=1	;
		}
	}
	
}


int detect_fin(int **plateau, int taille){
	int nb_indices_restants=0;
	int bloque;
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			if(plateau[i][j]==4 || plateau[i][j]==3){
				nb_indices_restants++;
			}
			else if (plateau[i][j]==1 ){
				bloque=0;
				bloque+=deplacement_possible(plateau, taille, i, j, 'h', 1);
				bloque+=deplacement_possible(plateau, taille, i, j, 'b', 1);
				bloque+=deplacement_possible(plateau, taille, i, j, 'g', 1);
				bloque+=deplacement_possible(plateau, taille, i, j, 'd', 1);
				if (bloque==0){
					return -1;
				}
			}
			else if(plateau[i][j]==2){
				bloque=0;
				bloque+=deplacement_possible(plateau, taille, i, j, 'h', 2);
				bloque+=deplacement_possible(plateau, taille, i, j, 'b', 2);
				bloque+=deplacement_possible(plateau, taille, i, j, 'g', 2);
				bloque+=deplacement_possible(plateau, taille, i, j, 'd', 2);
				if (bloque<2){
					return -1;
				}
			}
			
		}
	}
	if(nb_indices_restants==0){return 1;}
	return 0;
}