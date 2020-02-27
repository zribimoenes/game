#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
 #include <SDL/SDL_ttf.h>
int main(int argc, char *argv[])
 
{int i=1;
int b=1;
int j=0;
int bk2=0;
int bk3=0;
int play=1;
    int x=0,y=0,v=1, continuer=1;
    SDL_Surface *back = NULL;
    SDL_Surface *ecran = NULL;
    SDL_Surface *play1 = NULL;
    SDL_Surface *play2 = NULL;
    SDL_Surface *help1 = NULL;
    SDL_Surface *help2 = NULL;
    SDL_Surface *settings1 = NULL;
    SDL_Surface *settings2 = NULL;
    SDL_Surface *quit1 = NULL;
    SDL_Surface *quit2 = NULL;
    SDL_Surface *texte = NULL;
   SDL_Surface *prev=NULL ;
SDL_Surface *ss=NULL ;
SDL_Surface *ss1=NULL ;
SDL_Surface *ss2=NULL ;
SDL_Surface *mus=NULL;
SDL_Surface *mus1=NULL;
SDL_Surface *mus2=NULL;
SDL_Surface *mus3=NULL;  

SDL_Surface *soundon=NULL;
   SDL_Surface *soundoff=NULL;
 SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
Mix_Music *musique;    
Mix_Music *musique2;
Mix_Music *musique3;
SDL_Rect positionback, positionplay, positionhelp, positionsettings, positionquit,position ;
SDL_Rect positionsound; 
SDL_Rect positionmus;
SDL_Rect positionmus1;
SDL_Rect positionmus2;
SDL_Rect positionmus3;
SDL_Rect positionprev;
SDL_Rect positionss;
SDL_Rect positionss1;
SDL_Rect positionss2;

    positionback.x=0;
    positionback.y=0;
    positionplay.x=220;
    positionplay.y=50;
    positionhelp.x=220;
    positionhelp.y=150;
    positionsettings.x=220;
    positionsettings.y=250;
    positionquit.x=220;
    positionquit.y=350;

positionmus.x=600;
positionmus.y=60;
positionmus1.x=600;
positionmus1.y=150;
positionmus2.x=600;
positionmus2.y=240;
positionmus3.x=600;
positionmus3.y=330;
positionprev.x=200;
positionprev.y=500;
positionsound.x=200;
positionsound.y=60;
positionss.x=400;
positionss.y=60;
positionss1.x=400;
positionss1.y=150;
positionss2.x=400;
positionss2.y=240;

    SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO );
    TTF_Init();
    
    SDL_WM_SetIcon(IMG_Load("icone.jpg"), NULL);
    ecran = SDL_SetVideoMode( 800,600, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE );
    SDL_WM_SetCaption("VIDEOGAME", NULL);
    
    back = IMG_Load("back.jpg");
    play1 = IMG_Load("play1.png");
    play2 = IMG_Load("play2.png");
    help1 = IMG_Load("help1.png");
    help2 = IMG_Load("help2.png");
    settings1 = IMG_Load("settings1.png");
    settings2= IMG_Load ("settings2.png");
    quit1 = IMG_Load("quit1.png");
    quit2 = IMG_Load("quit2.png");
ss=IMG_Load("full.png");
ss1=IMG_Load("ss1.png");
ss2=IMG_Load("ss2.png");
soundon=IMG_Load("SON.png");
soundoff=IMG_Load("SOFF.png");
prev=IMG_Load("prev.png");
 mus=IMG_Load("mus.png"); 
mus2=IMG_Load("mus2.png");
mus3=IMG_Load("mus3.png");
mus1=IMG_Load("mus1.png");
 
    
/* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 30);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "sorry the game will be here very soon press the mouse reight button to quit", couleurNoire);
    SDL_Flip( ecran );
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        // printf("%s", Mix_GetError());
    }
     //Création du pointeur de type Mix_Music
    //Chargement de la musique
   musique = Mix_LoadMUS("get.mp3");
musique2 = Mix_LoadMUS("get2.mp3");
musique3 = Mix_LoadMUS("get3.mp3");
 Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
Mix_Chunk *scroll = NULL;
     scroll = Mix_LoadWAV("bref.wav");
    //KEYBOARD EVENT
 SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(play1, NULL, ecran, &positionplay);
    SDL_BlitSurface(help1, NULL, ecran, &positionhelp);
    SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);
    SDL_BlitSurface(quit1, NULL, ecran, &positionquit);
while (continuer)
{    SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(play1, NULL, ecran, &positionplay);
    SDL_BlitSurface(help1, NULL, ecran, &positionhelp);
    SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);
    SDL_BlitSurface(quit1, NULL, ecran, &positionquit);
    SDL_WaitEvent(&event);
   
switch(event.type)
    { 
     case SDL_QUIT:
            continuer = 0;
            break;
     case SDL_KEYDOWN: 
       switch(event.key.keysym.sym)
{
 case SDLK_m:
        b=b+2;
        Mix_VolumeMusic(MIX_MAX_VOLUME/b);
        break;

        case SDLK_l:
         if(b!=1)
          {
            b=b-2;
            Mix_VolumeMusic(MIX_MAX_VOLUME/b);
          } 
          else
           break;
       
          break;



case SDLK_RETURN:


SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
         SDL_BlitSurface(back, NULL, ecran, &positionback);
position.x = 10;
        position.y = 300;
        
SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);

	
				
break;

 
   case SDLK_DOWN:
                switch(i)
{
 
case 1:

i=1;

						SDL_BlitSurface(play1,NULL,ecran,&positionplay);
						SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
						SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
						SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
						
						SDL_BlitSurface(play2,NULL,ecran,&positionplay);
SDL_Flip(ecran);
i++;	
 Mix_PlayChannel(-1, scroll, 0);	
break;

case 2:
						//BOUTTON2,CLAVIER
i++;						
						//initialliser ecran
						SDL_BlitSurface(play1,NULL,ecran,&positionplay);
						SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
						SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
						SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
						
						SDL_BlitSurface(help2,NULL,ecran,&positionhelp);

SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);							
						
break;
					
case 3:
						//BOUTTON2,CLAVIER
i++;						
						//initialliser ecran
		SDL_BlitSurface(play1,NULL,ecran,&positionplay);
						SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
						SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
						SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
SDL_BlitSurface(settings2, NULL, ecran, &positionsettings);

SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);							
						
break;
case 4:
						//BOUTTON4,CLAVIERdn
						
						//initialliser ecran

i=1;
						SDL_BlitSurface(play1,NULL,ecran,&positionplay);	SDL_BlitSurface(help1,NULL,ecran,&positionhelp);	
SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);	SDL_BlitSurface(quit1,NULL,ecran,&positionquit);	
SDL_BlitSurface(quit2,NULL,ecran,&positionquit);
SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);	
break;
					
		}

		break;





                case SDLK_UP:
switch(i)
{

case 1:
i=4;
SDL_BlitSurface(play1,NULL,ecran,&positionplay);
						SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
						SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
						SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
						
						SDL_BlitSurface(play2,NULL,ecran,&positionplay);
SDL_Flip(ecran);						
						
Mix_PlayChannel(-1, scroll, 0);	
break;
case 2:
i--;
SDL_BlitSurface(play1,NULL,ecran,&positionplay);
						SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
						SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
						SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
						
						SDL_BlitSurface(help2,NULL,ecran,&positionhelp);
//UP2
SDL_Flip(ecran);

Mix_PlayChannel(-1, scroll, 0);	
						
break;

case 3:
i--;													SDL_BlitSurface(play1,NULL,ecran,&positionplay);
						SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
						SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
						SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
SDL_BlitSurface(settings2, NULL, ecran, &positionsettings);

SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);	
						

break;
case 4:

i--;						
SDL_BlitSurface(play1,NULL,ecran,&positionplay);	SDL_BlitSurface(help1,NULL,ecran,&positionhelp);	SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);	SDL_BlitSurface(quit1,NULL,ecran,&positionquit);	SDL_BlitSurface(quit2,NULL,ecran,&positionquit);
SDL_Flip(ecran);				
Mix_PlayChannel(-1, scroll, 0);	
break;						

						
	



					
		}
break;
case SDLK_ESCAPE: 
        continuer = 0;
        break;
}
case SDL_MOUSEMOTION:

        x = event.motion.x;
        y = event.motion.y;
        //If the mouse is over the button
        if( (( x >= positionplay.x )&&( x <= positionplay.x +200 )) && (( y >= positionplay.y )&& ( y <= positionplay.y+95  )))
            {SDL_BlitSurface(play1,NULL,ecran,&positionplay);
	     SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
	     SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
	     SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(play2, NULL, ecran, &positionplay);        
             SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);	
/*else
{
SDL_BlitSurface(play1, NULL, ecran,&positionplay);       
 SDL_Flip(ecran);
}*/
}

if( (( x >= positionhelp.x )&&( x <= positionhelp.x +200 )) && (( y >= positionhelp.y )&& ( y <= positionhelp.y+95  )))
            {SDL_BlitSurface(play1,NULL,ecran,&positionplay);
	     SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
	     SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
	     SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(help2, NULL, ecran, &positionhelp);        
             SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);	
/*else
{
SDL_BlitSurface(help1, NULL, ecran,&positionhelp);       
 SDL_Flip(ecran);
}*/
}

if( (( x >= positionsettings.x )&&( x <= positionsettings.x +200 )) && (( y >= positionsettings.y )&& ( y <= positionsettings.y+95  )))
            {SDL_BlitSurface(play1,NULL,ecran,&positionplay);
	     SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
	     SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
	     SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(settings2, NULL, ecran, &positionsettings);        
             SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);	
}
/*else
{
SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);       
 SDL_Flip(ecran);
}*/
if( (( x >= positionquit.x )&&( x <= positionquit.x +200 )) && (( y >= positionquit.y )&& ( y <= positionquit.y+95  )))
            {SDL_BlitSurface(play1,NULL,ecran,&positionplay);
	     SDL_BlitSurface(help1,NULL,ecran,&positionhelp);
	     SDL_BlitSurface(settings1,NULL,ecran,&positionsettings);
	     SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(quit2, NULL, ecran, &positionquit);        
             SDL_Flip(ecran);
Mix_PlayChannel(-1, scroll, 0);	
}
/*else
{
SDL_BlitSurface(quit1, NULL, ecran,&positionquit);       
 SDL_Flip(ecran);
}*/


break;

case SDL_MOUSEBUTTONUP:

if( (( x >= positionplay.x )&&( x <= positionplay.x +200 )) && (( y >= positionplay.y )&& ( y <= positionplay.y+95  )))

        { while (play)
        
          { SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
         SDL_BlitSurface(back, NULL, ecran, &positionback);
position.x = 10;
        position.y = 300;
        
SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);
SDL_WaitEvent(&event);

switch (event.type) 
{case SDL_MOUSEBUTTONUP:

if(event.button.button == SDL_BUTTON_RIGHT)
play=0;
}
}
 SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(play1, NULL, ecran, &positionplay);
    SDL_BlitSurface(help1, NULL, ecran, &positionhelp);
    SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);
    SDL_BlitSurface(quit1, NULL, ecran, &positionquit);
SDL_Flip(ecran);
play=1;	
}


if (((x >=positionquit.x)&&(x <=positionquit.x +200))&&((y <=positionquit.y+95)&&(y >= positionquit.y)))
{
continuer=0;}

if (((x >=positionsettings.x)&&(x <=positionsettings.x +200))&&((y <=positionsettings.y+95)&&(y >= positionsettings.y)))



{
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);

SDL_Flip(ecran);

bk2=1;
while (bk2)

{ SDL_WaitEvent(&event);


switch (event.type) 				
{case SDL_MOUSEBUTTONUP:
if (((event.button.x >=positionsound.x)&&(event.button.x <=positionsound.x+183))&&((event.button.y <=positionsound.y+60 )&&(event.button.y >= positionsound.y)))
{switch (j)
{ case 0:

j++;
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundoff,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);

SDL_Flip(ecran);

Mix_PauseMusic();
 break;

case 1:

j--;

if((Mix_PausedMusic() == 1))

{

Mix_ResumeMusic();

SDL_BlitSurface(back,NULL,ecran,&positionback);

SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);


SDL_Flip(ecran);}

break;}

}
if (((event.button.x >=positionss.x)&&(event.button.x <=positionss.x+183))&&((event.button.y <=positionss.y+60 )&&(event.button.y >= positionss.y)))

{SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(ss1,NULL,ecran,&positionss1);
SDL_BlitSurface(ss2,NULL,ecran,&positionss2);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);


SDL_Flip(ecran);

}
if (((event.button.x >=400)&&(event.button.x <=580))&&((event.button.y <= 200)&&(event.button.y >= 150)))

{
ecran=SDL_SetVideoMode(800,600 , 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_FULLSCREEN);
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);

SDL_Flip(ecran);

}
if (((event.button.x >=400)&&(event.button.x <=580))&&((event.button.y <= 290)&&(event.button.y >= 240)))

{
ecran=SDL_SetVideoMode(800, 667 , 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);
SDL_Flip(ecran);

}
if (((event.button.x >=600)&&(event.button.x <=780))&&((event.button.y <= 110)&&(event.button.y >= 60)))

{

SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);
SDL_BlitSurface(mus1,NULL,ecran,&positionmus1);
SDL_BlitSurface(mus2,NULL,ecran,&positionmus2);
SDL_BlitSurface(mus3,NULL,ecran,&positionmus3);

SDL_Flip(ecran);

}
if (((event.button.x >=600)&&(event.button.x <=780))&&((event.button.y <= 200)&&(event.button.y >= 150)))

{
Mix_PauseMusic();
Mix_RewindMusic(); 
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);
SDL_BlitSurface(mus1,NULL,ecran,&positionmus1);
SDL_BlitSurface(mus2,NULL,ecran,&positionmus2);
SDL_BlitSurface(mus3,NULL,ecran,&positionmus3);

SDL_Flip(ecran);
Mix_PlayMusic(musique, -1);
}
if (((event.button.x >=600)&&(event.button.x <=780))&&((event.button.y <= 290)&&(event.button.y >= 240)))

{Mix_PauseMusic(); 
Mix_RewindMusic();
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);
SDL_BlitSurface(mus1,NULL,ecran,&positionmus1);
SDL_BlitSurface(mus2,NULL,ecran,&positionmus2);
SDL_BlitSurface(mus3,NULL,ecran,&positionmus3);

SDL_Flip(ecran);
Mix_PlayMusic(musique2, -1);
}

if (((event.button.x >=600)&&(event.button.x <=780))&&((event.button.y <= 380)&&(event.button.y >= 330)))

{Mix_PauseMusic(); 
Mix_RewindMusic();
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(soundon,NULL,ecran,&positionsound);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(ss,NULL,ecran,&positionss);
SDL_BlitSurface(mus,NULL,ecran,&positionmus);
SDL_BlitSurface(mus1,NULL,ecran,&positionmus1);
SDL_BlitSurface(mus2,NULL,ecran,&positionmus2);
SDL_BlitSurface(mus3,NULL,ecran,&positionmus3);
SDL_Flip(ecran);
Mix_PlayMusic(musique3, -1);
}


if (((event.button.x >=200)&&(event.button.x <=380))&&((event.button.y <= 550)&&(event.button.y >= 500)))
    bk2=0;
}

}

}
break;

}

}
    //MOUSE EVENT
    
    SDL_FreeSurface(back);
    SDL_FreeSurface(play1);
    SDL_FreeSurface(help1);
    SDL_FreeSurface(settings1);
    SDL_FreeSurface(quit1);
   TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
 Mix_FreeMusic(musique); //Libération de la musique
    Mix_CloseAudio(); //Fermeture de l'API
    SDL_Quit();
return 0;
}
   
