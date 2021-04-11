#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "ennemi.h"
/* constantes */
#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700
#define VITESSE_INIT_VOIT 15// vitesse de ennemi 

#define NB_VOIES 3//combien de animation de voiture 
#define LARG_enemi 175
#define LONG_enemi 175


#define MAX_enemi   1900 
int  collision(SDL_Rect poss,struct enemi enemis[])
{
int n , p  ; 

    for (n=0; n<MAX_enemi ; n++)
     {
     //p=MAX_enemi-n ;

if 
((poss.y>enemis[n].coord.y + enemis[n].coord.h) ||( poss.y+poss.h<enemis[n].coord.y)||(poss.x+poss.w<enemis[n].coord.x) || (poss.x>enemis[n].coord.x + enemis[n].coord.w))
 {
return 0 ; 


//enemis->nbre_vie-- ;
 } else  
//(!(poss.y>enemis[n].coord.y + enemis[n].coord.h) ||(poss.x+poss.w<enemis[n].coord.x) || (poss.x>enemis[n].coord.x + enemis[n].coord.w))
 {

// initEnnemi(enemis) ; 
 //deplaceranimer(enemis) ;
  //afficher(  ecran ,enemis);
 return 1 ; 
  //return 1 ; 
 }
 
/*if (enemis->nbre_vie==0) 
{
return 1; 
}else 
{
return 0 ; 
} */
 //return debut  ;  
}
/*if (vie==0)
{ 
return 0 ;
}else 
{
return 1  ;
} */

}

 
 
void initEnnemi( struct enemi enemis[]) 
{
 
    int i,n;
   srand(time(NULL)) ; 
  
enemis->Animation_D[1]=IMG_Load("1g.png");

//enemis->Animation_D[2]=IMG_Load("2g.png");
//enemis->Animation_D[3]=IMG_Load("3g.png");

enemis->poss.y=400 ; 
enemis->poss.x=580  ;   
enemis->poss.h=392  ; 
enemis->poss.w=386 ; 

    for (n=0; n<NB_VOIES; n++) 
{
       enemis->xvoies[n] = (LARGEUR_FENETRE / NB_VOIES /2) + ((LARGEUR_FENETRE / NB_VOIES) * n)- (LARG_enemi/ 3); // 2= position de l'ennemi par rapp au perso
       //collision(enemis->poss,enemis) ;
    enemis->vite = VITESSE_INIT_VOIT;
    enemis->ys = 0; // 0= pos de descente de ennemi
}
    /* init enemi */
    for (n=0; n<MAX_enemi; n++) {
 
        enemis[n].voie = rand() % NB_VOIES;
     enemis[n].y = (LONG_enemi + (LONG_enemi * 4) ) *(n + 1); // la descente dans chaque voie
        enemis[n].coord.w = LARG_enemi;
        enemis[n].coord.h = LONG_enemi;

    }
}


void deplaceranimer( struct enemi enemis[]) 
{
    int n;
  
    enemis->ys += enemis->vite;
    for (n=0; n<MAX_enemi ; n++) {
    
   if (abs(enemis[n].y - enemis->ys) < HAUTEUR_FENETRE) {

     // if (enemis[n].y - enemis->ys < HAUTEUR_FENETRE) {
          enemis[n].visible = 1;
          enemis[n].coord.x = enemis->xvoies[enemis[n].voie];//position aleatoire enemi
           enemis[n].coord.y = HAUTEUR_FENETRE - (enemis[n].y - enemis->ys);//enemi deplacemnt aleatoire descend
          
       } else
            enemis[n].visible = 0;
    }

} 


/*int  collision (SDL_Rect posh ,struct enemi enemis[])  
{
int nb;
nb=3 ;  

if 
{

return false ;  
}else 
{ 
return true ; 
}
}*/

void afficher(  SDL_Surface *screen,  struct enemi enemis[])
{
    int p,n,i=0;
p=HAUTEUR_FENETRE/2 ; 


   for (n=0; n<MAX_enemi; n++) 
    {
   i++  ;
  
         if (enemis[n].visible)
        {
  //SDL_Delay(500) ; 
                         SDL_BlitSurface(enemis->Animation_D[1],NULL, screen, &enemis[n].coord);
                                     
                         // SDL_Flip(ecran); 
        //if(enemis[n].coord.y=100 ) 

        //{  
        //enemis[n].coord.x = game->xvoies[enemis[n].voie];       
         //enemis[n].coord.y = HAUTEUR_FENETRE - (enemis[n].y - car->y);      
               //SDL_BlitSurface(enemis->Animation_D[1],NULL, ecran, &enemis[n].coord);
             //SDL_BlitSurface(enemis->Animation_D[2],NULL, ecran, &enemis[n].coord);

                           //   SDL_Flip(ecran);
                            //    SDL_BlitSurface(enemis->Animation_D[2],NULL, ecran, &enemis[n].coord);
                                   //   SDL_BlitSurface(enemis->Animation_D[2],NULL, ecran, &enemis[n].coord)
       // }else if (enemis[n].coord.y=400) 
        //{
                   
               // enemis[n].coord.x = game->xvoies[enemis[n].voie];
              //  enemis[n].coord.y = HAUTEUR_FENETRE - (enemis[n].y - car->y);
                // SDL_Flip(ecran);
                      //SDL_BlitSurface(enemis->Animation_D[2],NULL, ecran, &enemis[n].coord);
//                  SDL_BlitSurface(enemis->Animation_D[3],NULL, ecran, &enemis[n].coord);


    
  //      }
      }

        }
       /* i++ ;
        if (i==1)
        {


           //         SDL_BlitSurface(enemis->Animation_D[3],NULL, ecran, &enemis[n].coord);
       } else if (i==2)
       {
              SDL_BlitSurface(enemis->Animation_D[i],NULL, ecran, &enemis[n].coord);
               //SDL_BlitSurface(enemis->Animation_D[1],NULL, ecran, &enemis[n].coord);
                                  // SDL_BlitSurface(enemis->Animation_D[3],NULL, ecran, &enemis[n].coord);

       }else 
       { 
       i++ ; 
             SDL_BlitSurface(enemis->Animation_D[i],NULL, ecran, &enemis[n].coord);
               i==0 ; 
       } 
       
       }
       
       }*/
           /*else if (i==2)
     {
            SDL_BlitSurface(enemis->Animation_D[2],NULL, ecran, &enemis[n].coord);
      }else 
      {
            SDL_BlitSurface(enemis->Animation_D[3],NULL, ecran, &enemis[n].coord); 
           }*/
    
   SDL_Flip(screen);
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

/*void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}*/
