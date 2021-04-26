#include <stdio.h> 
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include<unistd.h>
//#include <SDL/SDL_mixer.h>
//#include <SDL/SDL_ttf.h> 
#include "en.h"

/**
* @bref ou.c 
* @bref tache ennemi 
* @author oussama ben hamida
* @version 1 
* @date Apr 26,2021
*
*Testing program for ennemi *

*/
/* constantes */
#define LARGEUR_FENETRE 1500 //largeur fenetre 
#define HAUTEUR_FENETRE 700  //hauteur fenetre 
#define VITESSE_INIT_VOIT 70// vitesse de ennemi

#define NB_VOIES 3 //combien de animation de voiture 
#define LARG_enemi 175
#define LONG_enemi 175

#define MAX_enemi  1900 //
int main(int argc ,char *argv[]) 
{ 
perso perso ; 
  Ennemy ennemy  ;
int framej=0,frame=0,aux=0;
SDL_Init(SDL_INIT_VIDEO) ; 
 fprintf(stderr,"EROOR SDL ;%s\n",SDL_GetError()) ; 
SDL_Surface *screen=NULL ,*back=NULL,*voiture=NULL,*enemii=NULL,*arbre1=NULL,*arbre2=NULL,*arbre3=NULL,*ar=NULL ; 
screen=SDL_SetVideoMode(1500,700,24,SDL_HWSURFACE|SDL_DOUBLEBUF) ; 
ar=IMG_Load("game.png") ; 
back=IMG_Load("sprite.png") ; 
arbre1=IMG_Load("g.png") ; 
arbre2=IMG_Load("gg.png") ; 
arbre3=IMG_Load("ggg.png") ; 
 SDL_Rect rectss [9][4] ;
 SDL_Rect g,gg,ggg,pr ; 
 pr.x=0 ; 
 pr.y=0 ; 
 g.x=200 ; 
 g.y=0 ; 
 gg.x=1200 ; 
 gg.y=0 ;
 ggg.x=700 ; 
 ggg.y=0 ;  
 setrectss(rectss) ;
 perso.poss.y=400 ; 
perso.poss.x=580  ;   
perso.poss.h=392  ; 
perso.poss.w=386 ; 
 //voiture
 voiture=IMG_Load("voiture.png") ; 
 //enemii=IMG_Load ("SS.png") ;  
 //SDL_Rect  poss ; 
// perso.poss.x=580 ;  
 //perso.poss.y=400 ; 
  
  
 

int continuer=1,framee=0;  
//int c=3 ;  
SDL_Rect pos ; 
Uint32 starttick;
pos.x=0; 
pos.y=0 ; 
    InitEnnemi(&ennemy);
const int fps=30;
int n ;
int nbre_vie ; 
int score=3; 
int nb=2 ; 
 while(continuer) 
 { 
  
   starttick = SDL_GetTicks();
  
     animerEnnemi(&ennemy)  ;

         deplacerIA(&ennemy ,perso.poss);
  SDL_BlitSurface(arbre1,NULL, screen,&g); 
  SDL_BlitSurface(arbre2,NULL, screen,&gg); 
  SDL_BlitSurface(arbre3,NULL, screen,&ggg); 
  afficherEnnemi(&ennemy,screen) ;
  SDL_BlitSurface(voiture,NULL, screen, &perso.poss);    
                                     
frame++;
 if (frame==3)
 {
 frame=0 ;
 framej++;
 }
if (framej==8)
 {
 if (frame==2)
{
 framej=0;
 frame=0;
 }
 }

  framee++  ; 
  if (framee==4) 
{
     framee=0 ; 
     }
SDL_Event event  ; 
while (SDL_PollEvent(&event))  
{ 
switch(event.type) 
{ 
 case SDL_QUIT  : 
 { 
 return 0 ; 
 break; 
 } 
  case SDL_KEYDOWN :
 { if(event.key.keysym.sym==SDLK_ESCAPE)
 {
return 0 ;  
}  
}


if (event.key.keysym.sym==SDLK_RIGHT)
{ 
perso.poss.x+=450;

} else if (event.key.keysym.sym=SDLK_LEFT)
{
perso.poss.x-=450;

}
}
}


 SDL_BlitSurface(back,&rectss[framej][frame],screen,&pos) ; 
              SDL_BlitSurface(voiture,NULL, screen, &perso.poss);
              int nb=2 ; 
   

     afficherEnnemi(&ennemy,screen) ;
      SDL_BlitSurface(arbre1,NULL, screen,&g); 
                                         SDL_BlitSurface(arbre2,NULL, screen,&gg); 
                                       SDL_BlitSurface(arbre3,NULL, screen,&ggg); 
if (collision (perso.poss,&ennemy)) 
               {
               //SDL_BlitSurface(back,NULL,screen,&pos) ; 
              
             
                SDL_BlitSurface(ar,NULL, screen,&pr) ;
                /*while (SDL_PollEvent(&event))  
{ 
switch(event.type) 
{ 
            case SDL_KEYDOWN :
 { 
 if(event.key.keysym.sym==SDLK_ESCAPE)
 
 
{
               continuer=0 ;
               }
               }
               }
               }
               }
               else 
               {
               continuer=1 ; */
               }
               
  // afficher(screen,voiture,enemii, enemis,&perso);     

		  SDL_Flip(screen);
		  if(1000/fps>SDL_GetTicks()-starttick)
{
SDL_Delay( 1000/fps-(SDL_GetTicks()-starttick) );
} 
}
SDL_FreeSurface(back) ; 
SDL_FreeSurface(voiture) ; 
Free_Ennemy(&ennemy) ;
//SDL_FreeSurface(enemii) ; 
SDL_FreeSurface(screen) ; 
SDL_Quit() ;
return  0;   
} 
