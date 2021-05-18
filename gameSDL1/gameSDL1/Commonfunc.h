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
 const int NUM_THREAT = 3;	
 const int NUM_THREAT_TINH_6 = 6;
 const int NUM_DA = 3;
 const int NUM_MÀN_3 = 20;

 const int POS_RESET_X = 600;
 const int POS_RESET_Y = 600;
 const int SPEED_SCREEN= 1;

static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Surface* g_menu = NULL;
//static SDL_Surface *g_bkground_1 = NULL;
static SDL_Event g_even;


static Mix_Chunk*  sound_bullet;
static Mix_Chunk*  sound_bom;


namespace SDLCommonFunc
{
   SDL_Surface* LoadImage(std::string file_path);
 //  SDL_Rect ApplySurface_formenu(SDL_Surface* src, SDL_Surface* des, int x, int y);
   void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
   void CleanUp();
   bool CheckCollision(const SDL_Rect& object1,const SDL_Rect& object2);

   int ShowMenu(SDL_Surface* des, TTF_Font *font);
    int ShowMenu_win(SDL_Surface* des, TTF_Font *font);
	int ShowMenu_lost(SDL_Surface* des, TTF_Font *font);
   bool  CheckFocusWithRect(const int &x,const  int &y , SDL_Rect& rect);
    bool CheckFocusWithRect_exit(const int &x,const int &y , SDL_Rect& rect);
}



//SDL_Surface *g_object;
#endif
