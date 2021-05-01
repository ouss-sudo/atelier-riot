/** 
* @file main.c 
* @brief tache perso. 
* @author Fakhreddine Souibgui
* @version 1 
* @date Apr 01, 2021
* 
* Testing program for perso * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "perso.h"


int main()
{

/*------partie declaration des variables-------*/
SDL_Surface *screen;
SDL_Event event;
SDL_Surface *back;
perso p;
int continuer=1,droite=0,gauche=0,up=0,dir=2;
Uint32 dt, t_prev;




/*-------partie initialisation-------*/
screen=SDL_SetVideoMode (1100,450,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
back=IMG_Load("background.png");
initPerso(&p);



/*--------- debut dboucle de jeu -----------*/
while (continuer)
{
t_prev=SDL_GetTicks();

  /*-------- gestion de l'input--------*/  
while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                break;
            case SDLK_UP:
                up=1;
                break;        
        }
    break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                dir=2;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
                gauche=0;
                p.vitesse=0;
                dir=3;
                break;
            case SDLK_UP:
                up=0;
                break;        
        }
    break;
    
    }
}//fin de linput



/*-------------update----------*/

if (droite==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=0;
}
if (gauche==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=1;
}
if (up==1) saut(&p);

p.acceleration -=0.3;

if (p.acceleration<0 ) p.acceleration=0;
if (p.acceleration>4 ) p.acceleration=4;
SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;
deplacerPerso(&p,dt);
animerPerso(&p);

if ((p.vitesse==0)&&(p.acceleration==0))
{
    p.direction=dir;
}

p.position.y += p.vitesseV;
p.vitesseV += 10; 
if (p.position.y >= 350)
{
    p.vitesseV=0;
    p.position.y=350;
}







/*---------------affichage------------
*/
SDL_BlitSurface(back,NULL,screen,NULL);
afficherPerso(p,screen);
SDL_Flip(screen);
SDL_Delay(50);





}
}

