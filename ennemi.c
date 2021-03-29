#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "ennemi.h"
#define Ennemi_WIDTH 237
#define Ennemi_HEIGHT 600
int loadEnnemiImages(Ennemi *A)
{  

	A->image = SDL_DisplayFormat(IMG_Load("cars.png"));

	/*if (A->image == NULL)
	{
		printf("Unable to load Ennemi jpg:%s\n", SDL_GetError());
		return (-1);
	}*/

	return (0);
}
 
void initEnnemi(Ennemi *E)
{
	E->positionAbsolue.x = 800;
	E->positionAbsolue.y = 350;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	
}

void setrects(SDL_Rect* clips)
{
clips[0].x=0 ; 
clips[0].y=0 ;
clips[0].w=226 ;
clips[0].h=339 ;

clips[1].x=400 ; 
clips[1].y=0 ;
clips[1].w=226 ;
clips[1].h=339 ;

clips[2].x=600 ; 
clips[2].y=0 ;
clips[2].w=226 ;
clips[2].h=339 ;

clips[3].x=790; 
clips[3].y=0 ;
clips[3].w=226 ;
clips[3].h=339 ;

clips[4].x=950 ; 
clips[4].y=0 ;
clips[4].w=339 ;
clips[4].h=226 ;
   
}
void setrectss(SDL_Rect clips[9][4])
{
int j,i ;
  for(int j=0;j<8;j++)
  {
    for (int i=0;i<4;i++)
    {
      clips[j][i].x=i*1536;
      clips[j][i].y=j*864;
      clips[j][i].h=864;
      clips[j][i].w=1536;
    }
  }
  for (int i=0;i<4;i++)
  {
    clips[8][i].x=i*1536;
    clips[8][i].y=j*864;
    clips[8][i].h=864;
    clips[8][i].w=1536;
  }
}
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}
