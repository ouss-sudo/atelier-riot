/** 
* @struct bg 
* @brief struct for background 
*/ 




#ifndef background_H_INCLUDED
#define background_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct bg
	{
    SDL_Surface *back /* ,mask*/;
	SDL_Rect camera;
	}bg;

    void initBack(bg * b);
    void aficherBack(bg b, SDL_Surface * screen);
    void scrolling (bg * b, int dir, int pasAvancement);


    #endif // DS_H_INCLUDED
