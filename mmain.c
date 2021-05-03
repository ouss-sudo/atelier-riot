/**
* @file main.c
* @brief tache main	
* @author hamza aouichaoui
* @ version 1
* @date Apr 01,2021
*
*Testing program for main *


*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "minimap.h"
#include "collision.h"
#include "temps.h"



int main()
{
    TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen , *mask, *perso;
screen=SDL_SetVideoMode (800,537,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("perso\t1",NULL);
SDL_Rect camera,posperso;
SDL_Event event;
minimap m;
temps t;
SDL_Surface *back;
perso=IMG_Load("hero.png");
back=IMG_Load("map.jpg");
mask=IMG_Load("mask.png");
int continuer=1;
init_map(&m);
camera.x=0;
camera.y=0;
camera.w=1300;
camera.h=700;
posperso.x=0;
posperso.y=260;
SDL_EnableKeyRepeat(100,10);////
initialiser_temps(&t);
while(continuer)
{
    
    SDL_BlitSurface(back,NULL,screen,NULL);
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                 if (collision_parfaite_left(mask,posperso)==0)
                 {
                     /* code */posperso.x-=5;
                 }
                    
                break;
                case SDLK_RIGHT:
                   if (collision_parfaite_right(mask,posperso)==0)
                      posperso.x+=5;
                   
                   
                    
                break;
                case SDLK_UP:
                    if (collision_parfaite_up(mask,posperso)==0) posperso.y-=5;
                break;  
                case SDLK_DOWN:
                    if (collision_parfaite_down(mask,posperso)==0) posperso.y+=5;
                break;  

            }
            break;
            
        }
    }        






SDL_BlitSurface(perso,NULL,screen,&posperso);


MAJMinimap(posperso ,  &m, camera, 20);
afficherminimap(m,screen);

afficher_temps(&t,screen);




SDL_Flip(screen);
//SDL_Delay();

}

    return 0;
}





