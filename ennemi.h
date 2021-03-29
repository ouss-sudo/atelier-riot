#ifndef Ennemi_H
#define Ennemi_H

#include <SDL/SDL.h>

struct Ennemi
{
	SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface *image;
	
};
typedef struct Ennemi Ennemi;

int loadEnnemiImages(Ennemi *);

void initEnnemi(Ennemi *E);

void setrects(SDL_Rect clips[5])  ; 
void setrectss(SDL_Rect clips[9][4]) ;
void freeEnnemi(Ennemi *E);

#endif
