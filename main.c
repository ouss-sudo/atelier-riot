#include <stdio.h>
#include <SDL/SDL.h>
//#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"

#define Ennemi_WIDTH 237
#define Ennemi_HEIGHT 600
int main(int argc, char **argv)
{
	int Done =0;
	Ennemi ennemi;

	SDL_Event event;
	SDL_Rect posback;
	posback.x=0 ; 
	posback.x=0 ;
	SDL_Surface *back=NULL;
	int keysHeld[323] = {0}; 
	SDL_Surface *screen;

	SDL_Init(SDL_INIT_VIDEO);
int framej=0,frame=0,framejj=0 ,framee=0;
	screen = SDL_SetVideoMode(1500, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
	back = IMG_Load("sprite.png");
	SDL_Rect rects[5] ;
 setrects(rects) ;
 SDL_Rect rectss[9][4] ;
 setrectss(rectss) ;
  SDL_BlitSurface(back,&rectss[framejj][framee],screen,&posback) ; 
	   loadEnnemiImages(&ennemi);

	   			
				//SDL_BlitSurface(ennemi.image,&rects[frame],screen,&ennemi.positionAbsolue);
  			 //SDL_Flip(screen) ;
	while (!Done)
{


		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				Done = 1;
				break;
			/*case SDL_KEYDOWN:
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				break;*/
				
			}
			/*if (keysHeld[SDLK_ESCAPE])
			{
				Done = 1;
				
		}*/
		}

		initEnnemi(&ennemi);
	   	 SDL_BlitSurface(back,&rectss[framejj][framee],screen,&posback) ; 
		SDL_BlitSurface(ennemi.image,&rects[frame],screen,&ennemi.positionAbsolue);
		  SDL_Flip(screen);
	 frame++  ; 
		        if (frame==5) 
		 {
		        frame=0 ; 
		  }      
	 framee++;
 if (framee==3)
 {
 framee=0 ;
 framejj++;
 }
if (framejj==8)
 {
 if (framee==2)
{
 framejj=0;
 framee=0;
 }
 
 }
		      //SDL_Flip(screen);
	} 
freeEnnemi(&ennemi);
SDL_FreeSurface(screen);
SDL_FreeSurface(back) ; 
SDL_Quit();

	return (0);

}
