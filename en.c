#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "en.h"
#include <time.h>
#include<unistd.h>
#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700
#define VITESSE_INIT_VOIT 70// vitesse de ennemi 
#define NB_VOIES 3//combien de animation de voiture 
#define LARG_enemi 175
#define LONG_enemi 175
#define MAX_enemi   1900 
/**
* @bref en.c 
* @bref tache ennemi 
* @author oussama ben hamida
* @version 1 
* @date Apr 26,2021
*
*Testing program for ennemi *

*/
int  collision(SDL_Rect poss,Ennemy *e)
{
  
//int nb=3 ;
if 
((poss.y>e->Position.y + e->Position.h ) ||( poss.y+poss.h< e->Position.y )||(poss.x+poss.w<e->Position.x) || (poss.x>e->Position.x + e->Position.w ))
 {

  return 0 ;
 // return 0 ;
 }else
 {
 return 1 ;
 } 

}
void InitEnnemi(Ennemy * e)
{
int n  ; 

   //srand(time(NULL)) ; 
e->Position.x=750;
e->Position.y=0;


e->Animation=1;
e->state=WAITING;
e->distance=300;


//e->image=IMG_Load("voiture") ; 
e->Animation_D[1]=IMG_Load("1g.png");
e->Animation_D[2]=IMG_Load("2g.png");
e->Animation_D[3]=IMG_Load("3g.png");


/*for (n=0; n<NB_VOIES; n++) 
    
        e->xvoies[n] = (LARGEUR_FENETRE / NB_VOIES /2) + ((LARGEUR_FENETRE / NB_VOIES) * n)- (LARG_enemi/ 3); // 2= position de l'ennemi par rapp au perso
    
    e->vitesse = VITESSE_INIT_VOIT;
    e->y = 0; // 0= pos de descente de ennemi
 for (n=0; n<MAX_enemi; n++) {
        en[n].voie = rand() % NB_VOIES;
        en[n].y = (LONG_enemi + (LONG_enemi * 4) ) *(n + 1); // la descente dans chaque voie
        en[n].Position.w = LARG_enemi;
        en[n].Position.h = LONG_enemi;
    }*/
}

void afficherEnnemi(Ennemy *e,SDL_Surface *screen)
{

SDL_BlitSurface(e->Animation_D[e->Animation], NULL, screen, &e->Position);

}



void animerEnnemi(Ennemy *e ) 
{
int n ; 
   srand(time(NULL)) ; 
 for (n=0; n<NB_VOIES; n++) 
{
 e->xvoies[n] = (LARGEUR_FENETRE / NB_VOIES /2) + ((LARGEUR_FENETRE / NB_VOIES) * n) ;// 2= position de l'ennemi par rapp au perso
}
if (e->Position.y==0)
{
 e->voie = rand() % 3;
  //e->Position.y = (LONG_enemi + (LONG_enemi * 1) ) *(n + 1);
 e->Position.x = e->xvoies[e->voie];
       }
 
}
void deplacerIA(Ennemy *e, SDL_Rect possperso)
{

//Ennemy en[MAX_enemi] ; 
 /*e->y += e->vitesse;
    for (n=0; n<MAX_enemi ; n++) {
     

      if (abs(e[n].y - e->y) < HAUTEUR_FENETRE) {
          e[n].visible = 1;
          e[n].Position.x = e->xvoies[e[n].voie];//position aleatoire enemi
            e[n].Position.y = HAUTEUR_FENETRE - (e[n].ys - e->y);//enemi deplacemnt aleatoire descend
            
       } else
            e[n].visible = 0;
    }*/

int dist = (possperso.x - e->Position.x);
//position aleatoire enemi
if   ((dist > - e->distance) && (dist <  e->distance))
{
e->state=ATTACKING;
}
else
{
e->state=WAITING;
}
switch(e->state)
{
case WAITING:
{
/*if (e->Position.y==300) 
{ 
e->Position.y-=20 ; 
}*/
e->Animation++;

if(e->Animation==4)
{
e->Animation=1;
}




e->Position.y-=20;


//e->Position.y-=200;
//sleep(1) ;
//}
/*
else
{
e->Position.y+=20;

}*/

break;
}


case ATTACKING:
{
if (e->Position.y==300) 
{ 
e->Position.y-=20 ; 
}
e->Animation++;

if(e->Animation==4)
{
e->Animation=1;
}
if(dist<0)
{
e->Position.y+=20;

}
else
{
e->Position.y-=20;
/*if(e->Position.y==300)
{
e->Position.y+=20 ; 
} */
}

break;
}

}
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
void Free_Ennemy(Ennemy *e)
{
for(int i=1;i<4;i++)
{
SDL_FreeSurface(e->Animation_D[i]);

}
}
