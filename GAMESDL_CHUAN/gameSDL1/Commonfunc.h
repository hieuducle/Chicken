#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include<SDL_ttf.h>





const int HEIGHT_BACKGROUND = 3350;		  

 const int SCREEN_WIDTH = 1200;		
 const int SCREEN_HEIGHT = 670;		
 const int SCREEN_BPP = 32;
 const int NUM_DA = 3;

 const int NUM_THREAT_BOSS_5 = 1;
 const int NUM_THREAT_5 = 20;
 const int NUM_THREAT_4 = 3;
 const int NUM_THREAT_1 = 6;
const int	NUM_THREAT_3 = 20;
const int NUM_THREAT_2 = 3;


 const int POS_RESET_X = 600;	  
 const int POS_RESET_Y = 600;
 const int SPEED_SCREEN= 1;		   

 const int MAX_MAP_1 = 0;
 const int MIN_MAP_1 = -670;
 const int MAX_MAP_2 = -670;
 const int MIN_MAP_2 = -1340;
 const int MAX_MAP_3 = -1340;
 const int MIN_MAP_3 = -2010;
 const int MAX_MAP_4 = -2010;
 const int MIN_MAP_4 = -2680;
 const int MAX_MAP_5 = -2680;
 const int MIN_MAP_5 = -3350;



static SDL_Surface *g_screen = NULL;	 
static SDL_Surface *g_bkground = NULL;
static SDL_Surface* g_menu = NULL;
static SDL_Event g_even;


static Mix_Chunk*  sound_bullet;
static Mix_Chunk*  sound_bom;			


namespace SDLCommonFunc
{
   SDL_Surface* LoadImage(std::string file_path);

   void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
   void CleanUp();
   bool CheckCollision(const SDL_Rect& object1,const SDL_Rect& object2);		 

   int ShowMenu(SDL_Surface* des, TTF_Font *font);
    int ShowMenu_win(SDL_Surface* des, TTF_Font *font);
	int ShowMenu_lost(SDL_Surface* des, TTF_Font *font);
   bool  CheckFocusWithRect(const int &x,const  int &y , SDL_Rect& rect);		  
    bool CheckFocusWithRect_exit(const int &x,const int &y , SDL_Rect& rect);
}

#endif
