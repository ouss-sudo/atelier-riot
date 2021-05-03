/** 
* @file main.c 
* @brief tache background. 
* @author MohamedLouay Hamrouni 
* @version 1 
* @date Apr 01, 2021
* 
* Testing program for background scrollilng * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"

int main()
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
screen=SDL_SetVideoMode (1000,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

int dir=0;
int vitesse=0;
SDL_WM_SetCaption("background\t1",NULL);
bg b;
SDL_Event event;
int continuer=1;
initBack(&b);
SDL_EnableKeyRepeat(100,10);

while(continuer)
{
    
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
                    dir=1;
                    vitesse++;
                    /////////////////
                break;
                case SDLK_RIGHT:
                    dir=0;
                    vitesse++;
                break;
                   

            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    vitesse=0;
                break;
                case SDLK_RIGHT:
                    vitesse=0;
                break;
               
            }

        break;    
        }
    }  
    aficherBack(b,screen);
   if ((b.camera.x >= 0) && (b.camera.x <= 2358))
   {
     scrolling(&b,dir,vitesse);  
   }
    
if (b.camera.x > 2358)    b.camera.x = 2358;

if (b.camera.x < 0)    b.camera.x = 0;




SDL_Flip(screen);
SDL_Delay(50);



}      








}



