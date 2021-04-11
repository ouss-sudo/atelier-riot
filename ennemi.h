#ifndef Ennemi_H
#define Ennemi_H

#include <SDL/SDL.h>
//#include "ennemi.h"

#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700
#define VITESSE_INIT_VOIT 15// vitesse de ennemi

#define NB_VOIES 3//combien de animation de voiture 
#define LARG_enemi 175//largeur ennnemi
#define LONG_enemi 175//longeur ennemi
#define MAX_enemi   1900
struct enemi {
 int vite; //vitesse de ennemi 
  int ys;     /*   on place la ennemi à l'origine 0 */
    int voie;
    // int y;     /* 0 est le début de la route */
    SDL_Rect coord;     /* coordonnées calculées à l'écran, si le ennemi
                         est visible */
SDL_Surface *Animation_G[4];
SDL_Surface *Animation_D[4];
SDL_Surface *en ; 
  int vitesse;
    int visible;
    int  nbre_vie  ; 
 
    // int vitesse; //vitesse de ennemi 
  int y;     
  int xvoies[NB_VOIES];
  SDL_Rect poss ;
};



void initEnnemi(struct enemi enemis[]);
void deplaceranimer( struct enemi enemis[]);

int collision(SDL_Rect posHero, struct enemi enemis[]) ;

void afficher(SDL_Surface *ecran, struct enemi enemis[]);
void setrectss(SDL_Rect clips[9][4]) ;


#endif
