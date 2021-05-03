/** 
* @file background.c 
* @brief background source. 
* @author MohamedLouay Hamrouni 
* @version 1 
* @date Apr 01, 2021
* 
* Testing program for background scrollilng * 
*/


#include "background.h"

void initBack(bg * b){
    b->back=IMG_Load("map_jeu.png");
    b->camera.x=0;
    b->camera.y=0;
    b->camera.w=1000;
    b->camera.h=700;
}


void aficherBack(bg b, SDL_Surface * screen){
    SDL_BlitSurface(b.back,&b.camera,screen,NULL); //// a modifierr
}

void scrolling (bg * b, int dir, int pasAvancement){
    if (dir==0)
    {
        b->camera.x += pasAvancement;
    }
    else if (dir==1)
    {
        b->camera.x -= pasAvancement;
    }   
}

