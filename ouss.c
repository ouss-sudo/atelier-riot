#include <stdio.h> 
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
//#include <SDL/SDL_ttf.h> 
#include "ennemi.h"
/* constantes */
#define LARGEUR_FENETRE 1500 //largeur fenetre 
#define HAUTEUR_FENETRE 700  //hauteur fenetre 
#define VITESSE_INIT_VOIT 15
// vitesse de ennemi

#define NB_VOIES 3 //combien de animation de voiture 
#define LARG_enemi 175
#define LONG_enemi 175

#define MAX_enemi  1900 //
int main(int argc ,char *argv[]) 
{ 
 //struct perso perso ; 
int framej=0,frame=0,aux=0;
SDL_Init(SDL_INIT_VIDEO) ; 
 fprintf(stderr,"EROOR SDL ;%s\n",SDL_GetError()) ; 
SDL_Surface *screen=NULL ,*back=NULL,*voiture=NULL,*enemii=NULL ; 
screen=SDL_SetVideoMode(1500,700,24,SDL_HWSURFACE|SDL_DOUBLEBUF) ; 
back=IMG_Load("sprite.png") ; 
 SDL_Rect rectss [9][4] ;
 setrectss(rectss) ;
 
 //voiture
 voiture=IMG_Load("voiture.png") ; 
 
 //enemii=IMG_Load ("SS.png") ;  
 //SDL_Rect  poss ; 
// perso.poss.x=580 ;  
 //perso.poss.y=400 ; 
  
  
 

int continuer=1, framee=0;  
//int c=3 ;  
SDL_Rect pos ; 
Uint32 starttick;
pos.x=0; 
pos.y=0 ; 


	//struct car car;
    struct enemi enemis[MAX_enemi];

    
 initEnnemi(enemis);
//SDL_Flip(screen) ; 
const int fps=30;
int n ;
int nbre_vie=3  ; 
int score=3; 
 while(continuer) 
 { 
  
   starttick = SDL_GetTicks();
    

               deplaceranimer(enemis)  ;

       if  (collision (enemis->poss,enemis)) 
               {
               continuer=0 ; 
               }else 
               {
                              deplaceranimer(enemis)  ;
               continuer=1 ;
                //   initEnnemi(enemis);
               //deplaceranimer(enemis)  ;
               
                // SDL_Flip(screen);
               }
       
 
               SDL_BlitSurface(voiture,NULL, screen, &enemis->poss);
     
  
         
    
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
 { 
 if(event.key.keysym.sym==SDLK_ESCAPE)
 {
return 0 ;  
}  

// effzfzgzg

if (event.key.keysym.sym==SDLK_RIGHT)
{
enemis->poss.x+=450;
 if  (collision (enemis->poss,enemis)) 
               {
               continuer=0 ; 
                                   //          SDL_Flip(screen);
               }else 
               {
               continuer=1 ;
  
               }
//aux++;
//if (aux==3) 
//{
//poss.y+=50 ;
//poss.x=-300 ;
//system("PAUSE") ;   
//}
 //SDL_BlitSurface(image,&rects[framej][frame],screen,&pos) ;

 //SDL_Flip(screen) ; 
} else if (event.key.keysym.sym=SDLK_LEFT)
{ 

enemis->poss.x-=450 ; 

 if  (collision (enemis->poss,enemis)) 
               {
               continuer=0 ; 
               }else 
               {
               continuer=1 ;

               }
                                               
                              //  SDL_Flip(screen);
 }
  /*if (enemis->poss.x-=580)
 {
 if  (collision (enemis->poss,enemis)) 
               {
               continuer=0 ; 
               }else 
               {
               continuer=1 ;
                                // SDL_Flip(screen);
               }
                               // SDL_Flip(screen);
 }*/ 
 
//if (perso.poss.x==700) 
//{
//perso.poss.x+=300;
//}
}


}
  
}
 
               if  (collision (enemis->poss,enemis)) 
               {
               continuer=0 ; 
               }else 
               {
               continuer=1 ;
               }
              


 SDL_BlitSurface(back,&rectss[framej][frame],screen,&pos) ; 
                 SDL_BlitSurface(voiture,NULL, screen, &enemis->poss);
afficher(screen,enemis) ;
   //int vie ; 
   //vie=3 ;   
        
     
   
         
   

		  SDL_Flip(screen);
		  if(1000/fps>SDL_GetTicks()-starttick)
{
SDL_Delay( 1000/fps-(SDL_GetTicks()-starttick) );
} 
}
SDL_FreeSurface(back) ; 
SDL_FreeSurface(voiture) ; 
SDL_FreeSurface(enemii) ; 
SDL_FreeSurface(screen) ; 
SDL_Quit() ;
return  0;   
} 
