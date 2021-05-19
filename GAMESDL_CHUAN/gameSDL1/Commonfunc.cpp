#include "Commonfunc.h"
#include "textobject.h"
 bool SDLCommonFunc::CheckFocusWithRect(const int &x,const int &y , SDL_Rect& rect)
 {
	 if(x >= rect.x && x <= rect.x + 400 &&
		 y >= rect.y && y <= rect.y + 50)
	 {
		 return true;
		}
	 return false;
 }
 bool SDLCommonFunc::CheckFocusWithRect_exit(const int &x,const int &y , SDL_Rect& rect) 
 {
	 if(x >= rect.x && x <= rect.x + 200 &&
		 y >= rect.y && y <= rect.y + 50)
	 {
		 return true;
	 }
	 return false;
 }

 int SDLCommonFunc::ShowMenu_win(SDL_Surface* des, TTF_Font *font)
 {
	 g_menu = LoadImage("menucuoi.png");
 if(g_menu == NULL)
 {return 1;}

 const int kmenu = 1;
 SDL_Rect pos_arr[kmenu];
 pos_arr[0].x = 500;
 pos_arr[0].y = 500;



 TextObject text_menu[kmenu];


 text_menu[0].SetText("Exit");
 text_menu[0].SetColor(TextObject::RED_TEXT);
 text_menu[0].SetRect(pos_arr[0].x , pos_arr[0].y);

bool selected[kmenu] = {0};
 int xm = 0;
 int ym= 0;
 SDL_Event m_event;
 while(true)
 {
	 SDLCommonFunc::ApplySurface(g_menu,des,0,0);
	 for(int i = 0; i < kmenu; i++)
	 {
		 text_menu[i].CreateText(font,des);
	 }

	 while(SDL_PollEvent(&m_event))
	 {
		 switch (m_event.type)
		 {
		 case SDL_QUIT:
			 return 1;
		 case SDL_MOUSEMOTION:
			 {
				 xm = m_event.motion.x;
				 ym = m_event.motion.y;

				 for(int i = 0; i < kmenu; i++)
				 {

					 if(CheckFocusWithRect(xm,ym,text_menu[i].GetRect()))
					 {
						 if(selected[i] == false)
						 {
							// selected[i] = 1;
							 text_menu[i].SetColor(TextObject::WHITE_TEXT);
						 }
					 }
					 else 
					 {
						 if(selected[i] == true)
						 {
							// selected[i] = 0;
							 text_menu[i].SetColor(TextObject::RED_TEXT);
						 }

					 }
				 }


			 }

			 break;
		 case SDL_MOUSEBUTTONDOWN:
			 {
				 xm = m_event.button.x;
				 ym = m_event.button.y;
				 for(int i = 0; i < kmenu; i++)
				 {
					 if(CheckFocusWithRect(xm,ym,text_menu[i].GetRect()))
					 {
						 return i;
					 }
				 }
			 }
			 break;
		 case SDL_KEYDOWN:
			 {
				 if(m_event.key.keysym.sym == SDLK_ESCAPE)
				 {
					 return 1;
				 }
			 }
			 break;
		 default:
			 break;
		 }
	 }
	 SDL_Flip(des);
 }

 return 1;
		}





int SDLCommonFunc::ShowMenu_lost(SDL_Surface* des, TTF_Font *font)
{
			g_menu = LoadImage("lost.png");
			if(g_menu == NULL)
			{return 1;}

			const int kmenu = 1;
			SDL_Rect pos_arr[kmenu];
			pos_arr[0].x = 500;
			pos_arr[0].y = 500;



			TextObject text_menu[kmenu];


			text_menu[0].SetText("Exit");
			text_menu[0].SetColor(TextObject::RED_TEXT);
			text_menu[0].SetRect(pos_arr[0].x , pos_arr[0].y);

			bool selected[kmenu] = {0};
			int xm = 0;
			int ym= 0;
			SDL_Event m_event;
			while(true)
			{
				SDLCommonFunc::ApplySurface(g_menu,des,0,0);
				for(int i = 0; i < kmenu; i++)
				{
					text_menu[i].CreateText(font,des);
				}

				while(SDL_PollEvent(&m_event))
				{
					switch (m_event.type)
					{
					case SDL_QUIT:
						return 1;
					case SDL_MOUSEMOTION:
						{
							xm = m_event.motion.x;
							ym = m_event.motion.y;

							for(int i = 0; i < kmenu; i++)
							{

								if(CheckFocusWithRect(xm,ym,text_menu[i].GetRect()))
								{
									if(selected[i] == false)
									{
										selected[i] = 1;
										text_menu[i].SetColor(TextObject::WHITE_TEXT);
									}
								}
								else 
								{
									if(selected[i] == true)
									{
										selected[i] = 0;
										text_menu[i].SetColor(TextObject::RED_TEXT);
									}

								}
							}


						}

						break;
					case SDL_MOUSEBUTTONDOWN:
						{
							xm = m_event.button.x;
							ym = m_event.button.y;
							for(int i = 0; i < kmenu; i++)
							{
								if(CheckFocusWithRect(xm,ym,text_menu[i].GetRect()))
								{
									return i;
								}
							}
						}
						break;
					case SDL_KEYDOWN:
						{
							if(m_event.key.keysym.sym == SDLK_ESCAPE)
							{
								return 1;
							}
						}
						break;
					default:
						break;
					}
				}
				SDL_Flip(des);
			}

			return 1;
		}
 int SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font *font)
 {
	 g_menu = LoadImage("menugame.png");
	 if(g_menu == NULL)
	 {return 1;}

	 const int kmenu = 2;
	 SDL_Rect pos_arr[kmenu];
	 pos_arr[0].x = 400;
	pos_arr[0].y = 400;

	pos_arr[1].x = 500;
	pos_arr[1].y = 500;

	TextObject text_menu[kmenu];

	text_menu[0].SetText("Play Game");
	text_menu[0].SetColor(TextObject::RED_TEXT);
	text_menu[0].SetRect(pos_arr[0].x , pos_arr[0].y);
				  
	text_menu[1].SetText("Exit");
	text_menu[1].SetColor(TextObject::RED_TEXT);
	text_menu[1].SetRect(pos_arr[1].x , pos_arr[1].y);

	//bool selected[kmenu] = {0,0};
	int xm = 0;
	int ym= 0;
	SDL_Event m_event;
	while(true)
	{
		SDLCommonFunc::ApplySurface(g_menu,des,0,0);
		for(int i = 0; i < kmenu; i++)
		{
		   text_menu[i].CreateText(font,des);
		}

		while(SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
				return 1;
			case SDL_MOUSEMOTION:
				{
					xm = m_event.motion.x;
					ym = m_event.motion.y;

					for(int i = 0; i < kmenu; i++)
					{
						
							if(CheckFocusWithRect(xm,ym,text_menu[i].GetRect()))
							{
								//if(selected[i] == false)
								//{
								//	selected[i] = 1;
									text_menu[i].SetColor(TextObject::WHITE_TEXT);
								//}
							}
							else 
							{
								//if(selected[i] == true)
								//{
								//	selected[i] = 0;
									text_menu[i].SetColor(TextObject::RED_TEXT);
								//}

						}
					}
						 
						
					}
				
				break;
			case SDL_MOUSEBUTTONDOWN:
				{
					xm = m_event.button.x;
					ym = m_event.button.y;
					for(int i = 0; i < kmenu; i++)
					{
					if(CheckFocusWithRect(xm,ym,text_menu[i].GetRect()))
					{
						return i;
					}
				}
			}
				break;
			case SDL_KEYDOWN:
				{
				   if(m_event.key.keysym.sym == SDLK_ESCAPE)
				   {
					   return 1;
				   }
				}
				break;
			default:
				break;
			}
		}
		SDL_Flip(des);
	}
	 
	return 1;
 }

SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface *optimize_image = NULL;

	load_image = IMG_Load(file_path.c_str());
	if(load_image != NULL)
	{
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);   // giải phóng
	}
	if (optimize_image != NULL) 
	{
	UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0, 0);

	SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
	}
	return optimize_image;
}

void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);	  // đẩy dữ liệu từ src vào des
	//return offset;
}


void SDLCommonFunc::CleanUp()
{
	// giải phóng dữ liệu
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}

bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1,const SDL_Rect& object2)
{

	int left_a = object1.x;
	int right_a = object1.x + object1.w;
	int top_a = object1.y;
	int bottom_a = object1.y + object1.h;

	int left_b = object2.x;
	int right_b = object2.x + object2.w;
	int top_b = object2.y;
	int bottom_b = object2.y + object2.h;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}