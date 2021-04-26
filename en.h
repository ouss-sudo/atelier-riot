#ifndef ENNEMY_H_INCLUDED
#define ENNEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include "player.h"
#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700
#define VITESSE_INIT_VOIT 70// vitesse de ennemi 

#define NB_VOIES 3//combien de animation de voiture 
#define LARG_enemi 175
#define LONG_enemi 175


#define MAX_enemi   1900 


typedef enum STATE STATE;
enum STATE{
WAITING,
//FOLLOWING,
ATTACKING
};

/**
@struct Ennemy 
@bref  struct for ennemi
*/
typedef struct 
{
//SDL_Surface *Animation_G[4];
SDL_Surface *Animation_D[4];
SDL_Surface *image;
int Animation;
    SDL_Rect Position;
//bool Direction;
STATE state;
int distance;
//int distance_a;
int vitesse ;
int xvoies[NB_VOIES];
int voie ; 
int y ; 
int ys ; 
int visible ; 

}Ennemy;
/**
@struct perso 
@bref  struct for perso
*/
typedef struct 
{ 
SDL_Rect poss ; 
} perso ; 
int  collision(SDL_Rect poss,Ennemy *e) ;
//int collision (SDL_Rect position1,SDL_Rect position2) ;
void InitEnnemi(Ennemy * e);
void afficherEnnemi(Ennemy *e,SDL_Surface *screen);
void deplacerIA(Ennemy *e,SDL_Rect possperso);
void animerEnnemi(Ennemy *e )  ;
void Free_Ennemy(Ennemy *e);
void setrectss(SDL_Rect clips[9][4]) ;


#endif
