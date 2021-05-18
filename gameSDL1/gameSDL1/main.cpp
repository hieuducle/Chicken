
#include "Commonfunc.h"
#include "MainObject.h"
#include "threats.h"
#include "heart.h"
#include "textobject.h"
#include <sstream>
#include <iostream>
//#include "Amo.h"
//#include "Amo.h"
std::string IntToString (int a)
{
	std::ostringstream temp;
	temp<<a;
	return temp.str();
}

TTF_Font* g_font_text = NULL;
TTF_Font* g_font_text_note = NULL;
TTF_Font* g_font_text_note_1 = NULL;
TTF_Font* g_font_text_note_2 = NULL;

unsigned int die_da = 0;
unsigned int die_egg = 0;
unsigned int die_ga = 0;

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
	{
		return false;
	}

	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT,2,4096) == -1)return false;

	sound_bullet = Mix_LoadWAV("f1.wav");
	sound_bom = Mix_LoadWAV("bom.wav");
	if(sound_bullet == NULL || sound_bom == NULL )
	{
		return false;
	}
	

	if(TTF_Init() == -1)
	{
		return false;
	}

	g_font_text = TTF_OpenFont("Starcraft Normal.ttf",20);
	if(g_font_text == NULL)
	{
		return false;
	}

	g_font_text_note = TTF_OpenFont("Starcraft Normal.ttf",15);
	if(g_font_text_note == NULL)
	{
		return false;
	}

	// màn 1
	g_font_text_note_1 = TTF_OpenFont("Halo.ttf",100);
	if(g_font_text_note_1 == NULL)
	{
		return false;
	}
	// màn 2
	g_font_text_note_2 = TTF_OpenFont("Starcraft Normal.ttf",50);
	if(g_font_text_note_2 == NULL)
	{
		return false;
	}
	
	return true;
}

int main(int arc, char *argv[])
{
	bool check_run_screen = true;
	bool is_quit = false;
	if (Init() == false)
		return 0;


	g_bkground = SDLCommonFunc::LoadImage("bkgmap.png");
	if (g_bkground == NULL)
	{
		return 0;
	}
	// make heart
	  Heart player;
	  player.Init();

	  // Text

	  TextObject mark_game;
	  mark_game.SetColor(TextObject::RED_TEXT);
		// time
	  TextObject time_;
	  time_.SetColor(TextObject::WHITE_TEXT);
		 // report
	  TextObject report_;
	  report_.SetColor(TextObject::RED_TEXT);

	// make main object
	 MainObject human_object;
	 human_object.SetRect(300,420);
	 bool ret = human_object.LoadImg("hahaa.png");
	 if(!ret)return 0;

	 // make threats


	//// QUÀ
	// ThreatObject* gifts = new ThreatObject[2];
	// // int x_temppp = 220;
	// for(int iq5 = 0; iq5 < 2; iq5++)
	// {
	//	 if(gifts)
	//	 {
	//		 ThreatObject* gift = (gifts+iq5);
	//		 ret  = gift->LoadImg("quadoden.png");

	//		 if(ret == false)return 0;
	//		 //	 boss_5->SetRect(x_temppp, 0 - i5*400);
	//		 // x_temppp+= 100;
	//		 gift->set_y_val(7);	   // toc do ga
	//		// AmoObject* p_amo =new AmoObject();
	//		// gift->InitAmo(p_amo);
	//		 bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),gift->GetRect());
	//		 if(is_coll == true)
	//		 {
	//			 human_object.HandleInputAction_gift(g_even,sound_bullet);

	//			 }
	//		 }

	//	 }
	// 



	// //END QUÀ
	 // BOSS MÀN 5 ==================================


	 ThreatObject* boss_s5 = new ThreatObject[1];
	// int x_temppp = 220;
	 for(int i5 = 0; i5 < 1; i5++)
	 {
		 if(boss_s5)
		 {
			 ThreatObject* boss_5 = (boss_s5+i5);
			 ret  = boss_5->LoadImg("bossman5.png");

			 if(ret == false)return 0;
			 boss_5->SetRect(400, 0 );
			// x_temppp+= 100;
			// boss_5->set_y_val(7);	   // toc do ga
			 AmoObject* p_amo =new AmoObject();
			 boss_5->InitAmo_boss(p_amo);
			/* bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_amo->GetRect());
			 if(is_coll == true)
			 {
				 if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
				 {
					 delete [] boss_5;
					 SDLCommonFunc::CleanUp();
					 SDL_Quit();
					 return 1;

				 }
			 }*/

		 }
	 }




	 // gà màn 5

	 ThreatObject* g_5_s = new ThreatObject[NUM_MÀN_3];
	 int xx_tempp = -120;																		//	 p_threats_1 = g_hang_ngang
	 int yx_tempp =0;																						//	g_hang_ngang_s
	 for(int in = 0; in < NUM_MÀN_3; in++)
	 {
		 if(g_5_s)
		 {
			 ThreatObject* g_5 = (g_5_s+in);
			 ret  = g_5->LoadImg("ga1chieu.png");
			 if(ret == false)return 0;
			 g_5->SetRect( xx_tempp, yx_tempp);
			 yx_tempp -= 100;
			 xx_tempp+= 10;
			 g_5->set_y_val(20);	   // toc do ga
			 AmoObject* p_amo =new AmoObject();
			 g_5->InitAmo(p_amo);
			/* bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_amo->GetRect());
			 if(is_coll == true)
			 {
				 if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
				 {
					 delete [] g_5_s;
					 SDLCommonFunc::CleanUp();
					 SDL_Quit();
					 return 1;

				 }
			 }*/

		 }
	 }



	 // END  MÀN 5 ====================================


	  // BOSS MÀN 4
	 ThreatObject* boss_s4 = new ThreatObject[NUM_THREAT];
	 for(int b = 0; b < NUM_THREAT; b++)									//p_threats = boss_s
																			//p_threat = boss
	 {
		 if(boss_s4)
		 {
			 ThreatObject* boss = (boss_s4 + b);
			 ret = boss->LoadImg("ga4.png");
			 if(ret == false)return 0;

			 int rand_y = rand()%400;
			 if(rand_y > SCREEN_HEIGHT)
			 {
				 rand_y = SCREEN_HEIGHT;
			 }
			 boss->SetRect(rand_y, 0 - b*400);
			 boss->set_y_val(3);	   // toc do ga
			 AmoObject* p_amo =new AmoObject();
			 boss->InitAmo_boss(p_amo);
			/* bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_amo->GetRect());
			 if(is_coll == true)
			 {
				 if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
				 {
					 delete [] boss;
					 SDLCommonFunc::CleanUp();
					 SDL_Quit();
					 return 1;

				 }
			 }*/

		 }


	 }
	 // END BOSS MÀN 4

	 // GÀ màn 3
	 ThreatObject* g_hang_ngang_s = new ThreatObject[NUM_MÀN_3];
	 int x_tempp = -120;																		//	 p_threats_1 = g_hang_ngang
	int y_tempp = 100;																						//	g_hang_ngang_s
	 for(int in = 0; in < NUM_MÀN_3; in++)
	 {
		 if(g_hang_ngang_s)
		 {
			 ThreatObject* g_hang_ngang = (g_hang_ngang_s+in);
			 ret  = g_hang_ngang->LoadImg("ga1chieu.png");
			 if(ret == false)return 0;
			 g_hang_ngang->SetRect( x_tempp, y_tempp);
			 y_tempp -= 100;
			 x_tempp+= 10;
			g_hang_ngang->set_y_val(20);	   // toc do ga
			 AmoObject* p_amo =new AmoObject();
			 g_hang_ngang->InitAmo(p_amo);
			 /*bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_amo->GetRect());
			 if(is_coll == true)
			 {
				 if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
				 {
					 delete [] g_hang_ngang_s;
					 SDLCommonFunc::CleanUp();
					 SDL_Quit();
					 return 1;

				 }
			 }*/

		 }
	 }
	 // END GÀ màn 3
	 // ===========================================================tao Da ========

	   int temp = 0;
	  ThreatObject* p_threats_3 = new ThreatObject[NUM_DA];
	// int xx_temp = 0;
	 for(int iid = 0; iid < NUM_DA; iid++)
	 {
	 if(p_threats_3)
	 {
		 ThreatObject* p_threat_3 = (p_threats_3+iid);
		 ret  = p_threat_3->LoadImg("dachuan2.png");
		 if(ret == false)return 0;  
		 p_threat_3->SetRect(temp, iid*400 );
		 temp+= 100;
		 p_threat_3->set_y_val(1);	   // toc do ga
		/* bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_threat_3->GetRect());
		 if(is_coll == true)
		 {
			 if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
			 {
				 delete [] p_threats_3;
				 SDLCommonFunc::CleanUp();
				 SDL_Quit();
				 return 1;

			 }
		 }*/

	 }
	 }
	 // =========================================================	het tao DA ============

	  // -----------------------------------------------------------QUÁI MÀN 1 HÀNG 1  ++++++++++++++++++++++++++++
	 // cai tien threat
	 ThreatObject* p_threats_1 = new ThreatObject[NUM_MÀN_3];
	 int x_temp = 220;
	 for(int ii = 0; ii < NUM_MÀN_3; ii++)
	 {
	 if(p_threats_1)
	 {
		 ThreatObject* p_threat_1 = (p_threats_1+ii);
		 ret  = p_threat_1->LoadImg("gahongden.png");
		 
		 if(ret == false)return 0;
		 p_threat_1->SetRect(x_temp, 0 - ii*400);
		 x_temp+= 100;
		 p_threat_1->set_y_val(7);	   // toc do ga
		 AmoObject* p_amo =new AmoObject();
		 p_threat_1->InitAmo(p_amo);
		/* bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_amo->GetRect());
		 if(is_coll == true)
		 {
			 if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
			 {
				 delete [] p_threats_1;
				 SDLCommonFunc::CleanUp();
				 SDL_Quit();
				 return 1;

			 }
		 }*/

	 }
	 }

	 	 //		   END HÀNG 1 MÀN 1
	 	 //---------------------------------------------------------


	 //=++++++++++++++++++++++++++++ QUÁI MÀN 1 HÀNG 2+++++++++++++++++++++==
	   ThreatObject* p_threats_2 = new ThreatObject[NUM_THREAT_TINH_6];
	 int x2_temp = 220;
	 for(int ii2 = 0; ii2 < NUM_THREAT_TINH_6; ii2++)
	 {
	 if(p_threats_2)
	 {
		 ThreatObject* p_threat_2 = (p_threats_2+ii2);
		 ret  = p_threat_2->LoadImg("gahongden.png");
		 if(ret == false)return 0;
		 /*int rand_y = rand()%400;
		 if(rand_y > SCREEN_HEIGHT)
		 {
			 rand_y = SCREEN_HEIGHT;
		 }*/
		  
		 p_threat_2->SetRect(x2_temp, 0 - ii2*400);
		 x2_temp+= 100;
		 p_threat_2->set_y_val(8);	   // toc do ga
		 AmoObject* p_amo =new AmoObject();
		 p_threat_2->InitAmo(p_amo);
		 /*bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_amo->GetRect());
		 if(is_coll == true)
		 {
			 if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
			 {
				 delete [] p_threats_2;
				 SDLCommonFunc::CleanUp();
				 SDL_Quit();
				 return 1;

			 }
		 }*/

	 }
	 }

	 //=++++++++++++++++++++++++++++ QUÁI MÀN 1 HÀNG 2 END	+++++++++++++++++++++==

	 // QUÁI BAY XUỐNG
	 ThreatObject* p_threats = new ThreatObject[NUM_THREAT];
	for(int i = 0; i < NUM_THREAT; i++)
	{
		if(p_threats)
		{
			ThreatObject* p_threat = (p_threats + i);
			ret = p_threat->LoadImg("gasaoden.png");
			if(ret == false)return 0;

			int rand_x = rand()%400;
			if(rand_x > SCREEN_HEIGHT)
			{
				rand_x = SCREEN_HEIGHT;
			}
			 p_threat->SetRect(rand_x, 0 - i*400);
	
			p_threat->set_y_val(3);	   // toc do ga
			AmoObject* p_amo =new AmoObject();
			p_threat->InitAmo(p_amo);
			/*bool is_coll = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_amo->GetRect());
			if(is_coll == true)
			{
			if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
			{
			delete [] p_threats;
			SDLCommonFunc::CleanUp();
			SDL_Quit();
			return 1;

			}
			}*/

		}
	

	}

 // END QUÁI BAY XUỐNG

	  
	int bground_y = 0;
	bool is_run_screen  = true;
	

	
	 int count_shot = 0;
	  unsigned int mark = 0;

	  // menu
	  int rett_menu = SDLCommonFunc::ShowMenu(g_screen,g_font_text_note_2);
	  if(rett_menu == 1)
	  {
		  is_quit =  true;
	  }


	 /* int ret_menu = SDLCommonFunc::ShowMenu(g_screen,g_font_text_note_2);
	  if(ret_menu == 1)
	  {
		  is_quit =  true;
		}*/


	  ////time
	  //std::string str_time = "Time: ";
	  //Uint32 time_val = SDL_GetTicks()/1000;
	  //std::string str_val = std::to_string(time_val);
	  //str_time += str_val;
	  //time_.SetText(str_time);
	  //time_.SetRect(SCREEN_WIDTH-150,30);
	  //time_.CreateText(g_font_text,g_screen);
	  //if(time_val > 60)
	  //{


		 // if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
		 // {
			//  //delete [] p_threats_3;
			//  SDLCommonFunc::CleanUp();
			//  SDL_Quit();
			//  return 1;

		 // }
	  //}



	
		while (!is_quit) 
	{
	
	while (SDL_PollEvent(&g_even)) 
	{
		if (g_even.type == SDL_QUIT)
		{
			is_quit = true;
			break;
		}
		if(bground_y <= 0 && bground_y > -670 )
		{
		  human_object.HandleInputAction_1(g_even,sound_bullet);
		  
		//  human_object.HandleInputAction_1(g_even,sound_bullet);
		}else if (bground_y <= -670 && bground_y > -1340)
		{
			human_object.HandleInputAction_2(g_even,sound_bullet);
		}
		else if (bground_y <= -1340 && bground_y > -2010)
		{
			human_object.HandleInputAction_3(g_even,sound_bullet);
		}
		else if (bground_y <= -2010 && bground_y > -2680)
		{
			human_object.HandleInputAction_4(g_even,sound_bullet);
		}
		else if (bground_y <= -2680 && bground_y > -3350)
		{
			human_object.HandleInputAction_5(g_even,sound_bullet);
		}
		
	}
	
	
	if (is_run_screen == true) // Background 
	{
		bground_y -= SPEED_SCREEN;
		if (bground_y <= -(HEIGHT_BACKGROUND - SCREEN_HEIGHT) )

		{
			is_run_screen = false;
		}
		else if(bground_y <= -2010 && bground_y > -2680  )
		{
			//MÀN 4
			// boss
			SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, bground_y);
			for(int bb = 0; bb < NUM_THREAT; bb++)
			{ 
				ThreatObject * boss =(boss_s4 + bb);
				if(boss)
				{	 

					boss->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
					boss->Show(g_screen);

					boss->MakeAmo(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);


				   // main và gà
					bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),boss->GetRect());
					if(is_col == true)
					{
						die_ga++;
						if(die_ga <= 2)
						{
							SDL_Delay(1000);
							human_object.SetRect(POS_RESET_X,POS_RESET_Y);
							player.Decrease();
							player.Render(g_screen);

							if(SDL_Flip(g_screen) == -1)
							{
								delete [] boss_s4;
								SDLCommonFunc::CleanUp();
								SDL_Quit();
								return 0;
							}
						}
						else 
						{
							int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
							if(ret_menu == 0)
							{
								is_quit =  true;
							}
						}
					}

					// dan may bay va ga

					std::vector<AmoObject*> amo_list = human_object.GetAmoList();

					for(int im4 = 0; im4 < amo_list.size(); im4++)
					{
						AmoObject* p_amo = amo_list.at(im4);
						if(p_amo != NULL)
						{
							bool ret_colll = SDLCommonFunc::CheckCollision(p_amo->GetRect(),boss->GetRect());
							if(ret_colll)
							{
							mark++;
								boss->Reset(0 - bb*400);

								human_object.RemoveAmo(im4);
							}
						}
					}




				}

				// va chạm máy bay và trứng
				std::vector<AmoObject*> amo_list_threat = boss->GetAmoList();
				for (unsigned int tm4 = 0; tm4 < amo_list_threat.size(); tm4++)
				{
					AmoObject* p_amo = amo_list_threat.at(tm4);
					if (p_amo)
					{
						bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), human_object.GetRect());
						if (ret_collis == true)
						{

							die_egg++;
							if(die_egg <= 2)
							{
								SDL_Delay(1000);
								human_object.SetRect(POS_RESET_X,POS_RESET_Y);
								player.Decrease();
								player.Render(g_screen);

								if(SDL_Flip(g_screen) == -1)
								{
									delete [] boss_s4;
									SDLCommonFunc::CleanUp();
									SDL_Quit();
									return 0;
								}
							}
							else 
							{
								int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
								if(ret_menu == 0)
								{
									is_quit =  true;
								}
							}
						}

					}
				}
				
				// boss	
			}


	

			
		} else if(bground_y <= -1340 && bground_y > -2010)
	{
			 // MÀN 3
			SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, bground_y);
			for(int jn = 0; jn  < NUM_MÀN_3; jn ++)
			{
				ThreatObject * ga_hang_ngang =(g_hang_ngang_s+jn ) ;
				if(ga_hang_ngang)
				{	 

					ga_hang_ngang->HandleMove_boss(SCREEN_WIDTH,SCREEN_HEIGHT);
					ga_hang_ngang->Show(g_screen);

					ga_hang_ngang->MakeAmo_man3(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);




					 // va chạm main và gà
					bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),ga_hang_ngang->GetRect());
					if(is_col == true)
					{

						die_ga++;
						if(die_ga <= 2)
						{
							SDL_Delay(1000);
							human_object.SetRect(POS_RESET_X,POS_RESET_Y);
							player.Decrease();
							player.Render(g_screen);

							if(SDL_Flip(g_screen) == -1)
							{
								delete [] g_hang_ngang_s;
								SDLCommonFunc::CleanUp();
								SDL_Quit();
								return 0;
							}
						}
						else 
						{
							int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
							if(ret_menu == 0)
							{
								is_quit =  true;
							}
						}
					}


					// va chạm 	 đạn máy bay và gà

					std::vector<AmoObject*> amo_list = human_object.GetAmoList();

					for(int i3 = 0; i3< amo_list.size(); i3++)
					{
						AmoObject* p_amo = amo_list.at(i3);
						if(p_amo != NULL)
						{
							bool ret_colll = SDLCommonFunc::CheckCollision(p_amo->GetRect(),ga_hang_ngang->GetRect());
							if(ret_colll)
							{
								mark++;
								//size_1--;
								//	delete[] p_threat_1[i1];
								ga_hang_ngang->Reset_man1(1500,0);
								//	p_threat_1->clear();
								//	  	delete [] p_threats_1;
								human_object.RemoveAmo(i3);

							}
						}
					}



				}

				// cha chạm người và trứng

				std::vector<AmoObject*> amo_list_threat = ga_hang_ngang->GetAmoList();
				for (unsigned int tm3 = 0; tm3< amo_list_threat.size(); tm3++)
				{
					AmoObject* p_amo = amo_list_threat.at(tm3);
					if (p_amo)
					{
						bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), human_object.GetRect());
						if (ret_collis == true)
						{

							die_egg++;
							if(die_egg <= 2)
							{
								SDL_Delay(1000);
								human_object.SetRect(POS_RESET_X,POS_RESET_Y);
								player.Decrease();
								player.Render(g_screen);

								if(SDL_Flip(g_screen) == -1)
								{
									delete [] g_hang_ngang_s;
									SDLCommonFunc::CleanUp();
									SDL_Quit();
									return 0;
								}
							}
							else 
							{
								int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
								if(ret_menu == 0)
								{
									is_quit =  true;
								}
							}
						}

					}
				}
			}
			
			}
		
		
		// MÀN 2===============================================
		else if(bground_y <= -670 && bground_y > -1340)
		{
			SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, bground_y);
			for(int j = 0; j < NUM_THREAT; j++)
			{ 
				ThreatObject * p_threat =(p_threats + j);
				if(p_threat)
				{	 

					p_threat->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
					p_threat->Show(g_screen);

					p_threat->MakeAmo(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);


					
					// check va cham  gà và người

					bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_threat->GetRect());
					if(is_col == true)
					{
						die_ga++;
						if(die_ga <= 2)
						{
							SDL_Delay(1000);
							human_object.SetRect(POS_RESET_X,POS_RESET_Y);
							player.Decrease();
							player.Render(g_screen);

							if(SDL_Flip(g_screen) == -1)
							{
								delete [] p_threats;
								SDLCommonFunc::CleanUp();
								SDL_Quit();
								return 0;
							}
						}
							else 
							{
								int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
								if(ret_menu == 0)
								{
									is_quit =  true;
								}
							}
						}
						
					

					// dan may bay va ga

					std::vector<AmoObject*> amo_list = human_object.GetAmoList();

					for(int im = 0; im < amo_list.size(); im++)
					{
						AmoObject* p_amo = amo_list.at(im);
						if(p_amo != NULL)
						{
							bool ret_colll = SDLCommonFunc::CheckCollision(p_amo->GetRect(),p_threat->GetRect());
							if(ret_colll)
							{
									mark++;
								p_threat->Reset(0 - j*400);

								human_object.RemoveAmo(im);
							}
						}
					}




				}

				// va chạm máy bay và trứng
				std::vector<AmoObject*> amo_list_threat = p_threat->GetAmoList();
				for (unsigned int tm = 0; tm < amo_list_threat.size(); tm++)
				{
					AmoObject* p_amo = amo_list_threat.at(tm);
					if (p_amo)
					{
						bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), human_object.GetRect());
						if (ret_collis == true)
						{

							die_egg++;
							if(die_egg <= 2)
							{
								SDL_Delay(1000);
								human_object.SetRect(POS_RESET_X,POS_RESET_Y);
								player.Decrease();
								player.Render(g_screen);

								if(SDL_Flip(g_screen) == -1)
								{
									delete [] p_threat;
									SDLCommonFunc::CleanUp();
									SDL_Quit();
									return 0;
								}
							}
							else 
							{
								int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
								if(ret_menu == 0)
								{
									is_quit =  true;
								}
							}
						}

					}
				}

			}
		} 
		// MÀN 1 =================================================================================
		else if(bground_y <= 0 && bground_y > -670)

		{
			// GÀ HÀNG 1
			SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, bground_y);
			
			int size_1 = NUM_THREAT_TINH_6;
			for(int jj = 0; jj < size_1; jj++)
			{
				ThreatObject * p_threat_1 =(p_threats_1+jj) ;
				if(p_threat_1)
				{	 

					p_threat_1->HandleMove_for1(SCREEN_WIDTH,SCREEN_HEIGHT);
					p_threat_1->Show(g_screen);

					p_threat_1->MakeAmo(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);


					// va chạm gà và người
					bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_threat_1->GetRect());
					if(is_col == true)
					{
						die_ga++;
						if(die_ga <= 2)
						{
							SDL_Delay(1000);
							human_object.SetRect(POS_RESET_X,POS_RESET_Y);
							player.Decrease();
							player.Render(g_screen);

							if(SDL_Flip(g_screen) == -1)
							{
								delete [] p_threats_1;
								SDLCommonFunc::CleanUp();
								SDL_Quit();
								return 0;
							}
						}
						else 
						{
							int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
							if(ret_menu == 0)
							{
								is_quit =  true;
							}
						}

						
					}


					// va chạm 	 đạn máy bay và gà

					std::vector<AmoObject*> amo_list = human_object.GetAmoList();

					for(int i1 = 0; i1< amo_list.size(); i1++)
					{
						AmoObject* p_amo = amo_list.at(i1);
						if(p_amo != NULL)
						{
							bool ret_colll = SDLCommonFunc::CheckCollision(p_amo->GetRect(),p_threat_1->GetRect());
							if(ret_colll)
							{
								mark++;
								//size_1--;
							//	delete[] p_threat_1[i1];
								p_threat_1->Reset_man1(1500,0);
							//	p_threat_1->clear();
							//	  	delete [] p_threats_1;
								human_object.RemoveAmo(i1);
								Mix_PlayChannel(-1,sound_bom,0);


							}
						}
					}



				}

				// Show mark
				//std

				

		


				// cha chạm người và trứng

				std::vector<AmoObject*> amo_list_threat = p_threat_1->GetAmoList();
				for (unsigned int tm = 0; tm < amo_list_threat.size(); tm++)
				{
					AmoObject* p_amo = amo_list_threat.at(tm);
					if (p_amo)
					{
						bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), human_object.GetRect());
						if (ret_collis == true)
						{
							die_egg++;
							if(die_egg <= 2)
							{
									SDL_Delay(1000);
								  human_object.SetRect(POS_RESET_X,POS_RESET_Y);
								  player.Decrease();
								  player.Render(g_screen);

								  if(SDL_Flip(g_screen) == -1)
								  {
									  delete [] p_threats_1;
									  SDLCommonFunc::CleanUp();
									  SDL_Quit();
									  return 0;
								  }

							}
							else 
							{
								
								int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
								if(ret_menu == 0)
								{
									is_quit =  true;
								}
							}

							
						}

					}
				}
			}
			// GÀ HÀNG 2 =============================================================
			for(int jj2 = 0; jj2 < NUM_THREAT_TINH_6; jj2++)
			{
				ThreatObject * p_threat_2 =(p_threats_2+jj2) ;
				if(p_threat_2)
				{	 

					p_threat_2->HandleMove_for2(SCREEN_WIDTH,SCREEN_HEIGHT);
					p_threat_2->Show(g_screen);

					p_threat_2->MakeAmo(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);



					// ga và người
					bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),p_threat_2->GetRect());
					if(is_col == true)
					{
						die_ga ++;
						if(die_ga <= 2)
						{
							SDL_Delay(1000);
							human_object.SetRect(POS_RESET_X,POS_RESET_Y);
							player.Decrease();
							player.Render(g_screen);

							if(SDL_Flip(g_screen) == -1)
							{
								delete [] p_threats_1;
								SDLCommonFunc::CleanUp();
								SDL_Quit();
								return 0;
							}
						}
							else 
							{
								int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
								if(ret_menu == 0)
								{
									is_quit =  true;
								}
							}
						}
						
					
			


					// va chạm 	 đạn máy bay và gà

					std::vector<AmoObject*> amo_list = human_object.GetAmoList();

					for(int i2 = 0; i2< amo_list.size(); i2++)
					{
						AmoObject* p_amo = amo_list.at(i2);
						if(p_amo != NULL)
						{
							bool ret_colll = SDLCommonFunc::CheckCollision(p_amo->GetRect(),p_threat_2->GetRect());
							if(ret_colll)
							{
									mark++;
								//size_1--;
								//	delete[] p_threat_1[i1];
								p_threat_2->Reset_man1(1500,0);
								//	p_threat_1->clear();
								//	  	delete [] p_threats_1;
								human_object.RemoveAmo(i2);

							}
						}
					}



				}

				// cha chạm người và trứng

				std::vector<AmoObject*> amo_list_threat = p_threat_2->GetAmoList();
				for (unsigned int tm2 = 0; tm2 < amo_list_threat.size(); tm2++)
				{
					AmoObject* p_amo = amo_list_threat.at(tm2);
					if (p_amo)
					{
						bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), human_object.GetRect());
						if (ret_collis == true)
						{
							  die_egg++;
							  if(die_egg <= 2)
							  {
								  SDL_Delay(1000);
								  human_object.SetRect(POS_RESET_X,POS_RESET_Y);
								  player.Decrease();
								  player.Render(g_screen);

								  if(SDL_Flip(g_screen) == -1)
								  {
									  delete [] p_threats_2;
									  SDLCommonFunc::CleanUp();
									  SDL_Quit();
									  return 0;
								  }
								  else 
								  {
									  int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
									  if(ret_menu == 0)
									  {
										  is_quit =  true;
									  }
								  }
							  }
							
						}

					}
				}

				}
			
		}
	}
	
	else 
	{
		// MÀN CUỐI
		SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, bground_y);
		//SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, bground_y);
		// gà 5

		for(int j5 = 0; j5  < NUM_MÀN_3; j5 ++)
		{
			ThreatObject * ga_5 =(g_5_s+j5 ) ;
			if(ga_5)
			{	 

				ga_5->HandleMove_boss(SCREEN_WIDTH,SCREEN_HEIGHT);
				ga_5->Show(g_screen);

				ga_5->MakeAmo_man3(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);




				// va chạm main và gà
				bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),ga_5->GetRect());
				if(is_col == true)
				{

					die_ga++;
					if(die_ga <= 2)
					{
						SDL_Delay(1000);
						human_object.SetRect(POS_RESET_X,POS_RESET_Y);
						player.Decrease();
						player.Render(g_screen);

						if(SDL_Flip(g_screen) == -1)
						{
							delete [] g_5_s;
							SDLCommonFunc::CleanUp();
							SDL_Quit();
							return 0;
						}
					}
					else 
					{
						int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
						if(ret_menu == 0)
						{
							is_quit =  true;
						}
					}
				}


				// va chạm 	 đạn máy bay và gà

				std::vector<AmoObject*> amo_list = human_object.GetAmoList();

				for(int i3 = 0; i3< amo_list.size(); i3++)
				{
					AmoObject* p_amo = amo_list.at(i3);
					if(p_amo != NULL)
					{
						bool ret_colll = SDLCommonFunc::CheckCollision(p_amo->GetRect(),ga_5->GetRect());
						if(ret_colll)
						{
							mark++;
							//size_1--;
							//	delete[] p_threat_1[i1];
							ga_5->Reset_man1(1500,0);
							//	p_threat_1->clear();
							//	  	delete [] p_threats_1;
							human_object.RemoveAmo(i3);

						}
					}
				}



			}

			// cha chạm người và trứng

			std::vector<AmoObject*> amo_list_threat = ga_5->GetAmoList();
			for (unsigned int tm3 = 0; tm3< amo_list_threat.size(); tm3++)
			{
				AmoObject* p_amo = amo_list_threat.at(tm3);
				if (p_amo)
				{
					bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), human_object.GetRect());
					if (ret_collis == true)
					{

						die_egg++;
						if(die_egg <= 2)
						{
							SDL_Delay(1000);
							human_object.SetRect(POS_RESET_X,POS_RESET_Y);
							player.Decrease();
							player.Render(g_screen);

							if(SDL_Flip(g_screen) == -1)
							{
								delete [] g_5_s;
								SDLCommonFunc::CleanUp();
								SDL_Quit();
								return 0;
							}
						}
						else 
						{
							int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
							if(ret_menu == 0)
							{
								is_quit =  true;
							}
						}
					}

				}
			}
		}




		// 00000000000000



		for(int b5 = 0; b5  < 1; b5 ++)
		{ 
			ThreatObject * boss_5 =(boss_s5 + b5 );
			if(boss_5)
			{	
				//boss_5->HandleMove_ga5(SCREEN_WIDTH,SCREEN_HEIGHT);
				boss_5->Show(g_screen);

				boss_5->MakeAmo_boss(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);


				bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),boss_5->GetRect());
				if(is_col == true)
				{
					die_ga ++;
					if(die_ga <= 2)
					{
						SDL_Delay(1000);
						human_object.SetRect(POS_RESET_X,POS_RESET_Y);
						player.Decrease();
						player.Render(g_screen);

						if(SDL_Flip(g_screen) == -1)
						{
							delete [] boss_s5;
							SDLCommonFunc::CleanUp();
							SDL_Quit();
							return 0;
						}
					}
						else 
						{
							int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
							if(ret_menu == 0)
							{
								is_quit =  true;
							}
							
						}
					
			}

				



				

				//	 +++++++++++++++++++++++++++++++++++++
			
				std::vector<AmoObject*> amo_list = human_object.GetAmoList();

				for (unsigned int am = 0; am < amo_list.size(); am++)
				{
					AmoObject* p_amo = amo_list.at(am);
					if (p_amo != NULL)
					{		 
						
						bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), boss_5->GetRect());
					
						if (ret_collis)
						{
							  count_shot++;
							  human_object.RemoveAmo(am);
							  if(count_shot > 10)
							  {
								  /*if(MessageBox(NULL,L"Game Over!",L"Info", MB_OK)== IDOK)
								  {
									  delete [] boss_s5;
									  SDLCommonFunc::CleanUp();
									  SDL_Quit();
									  return 1;

								  }*/

								  int ret_menu = SDLCommonFunc::ShowMenu_win(g_screen,g_font_text_note_2);
								  if(ret_menu == 0)
								  {
									  is_quit =  true;
								  }
							  }
							  else 
							  {
								 ;
							  }
							 
								 
								 //}
								 
							 
							
							
						}
					}
			
				}
				   


				// Check va chạm của boss5 and trunwgs


				std::vector<AmoObject*> amo_list_threat = boss_5->GetAmoList();
				for (unsigned int tm3 = 0; tm3< amo_list_threat.size(); tm3++)
				{
					AmoObject* p_amo = amo_list_threat.at(tm3);
					if (p_amo)
					{
						bool ret_collis = SDLCommonFunc::CheckCollision(p_amo->GetRect(), human_object.GetRect());
						if (ret_collis == true)
						{

							die_egg++;
							if(die_egg <= 2)
							{
								SDL_Delay(1000);
								human_object.SetRect(POS_RESET_X,POS_RESET_Y);
								player.Decrease();
								player.Render(g_screen);

								if(SDL_Flip(g_screen) == -1)
								{
									delete [] g_5_s;
									SDLCommonFunc::CleanUp();
									SDL_Quit();
									return 0;
								}
							}
							else 
							{
								int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
								if(ret_menu == 0)
								{
									is_quit =  true;
								}
							}
						}

					}
				}






		
		
	}
		}
		}


		 // Show heart player
		 player.Render(g_screen);


	// active main object
		 human_object.HandleMove();
		human_object.Show(g_screen);
		 
		human_object.MakeAmo(g_screen);

		  //-------------------------------------------------------------------------------------------
		   // qua
			  
		// qua
		// Da=========================

		for(int jjd = 0; jjd < NUM_DA; jjd++)
		{
			ThreatObject * da =(p_threats_3+jjd) ;
			if(da)
			{	 

				da->HandleMove_for3(SCREEN_WIDTH,SCREEN_HEIGHT);
				da->Show(g_screen);

				//da->MakeAmo(g_screen,SCREEN_WIDTH,SCREEN_HEIGHT);

				bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(),da->GetRect());
				if(is_col == true)
				{
					die_da++;
					if(die_da <= 2)
					{
						SDL_Delay(1000);
						human_object.SetRect(POS_RESET_X,POS_RESET_Y);
						player.Decrease();
						player.Render(g_screen);

						if(SDL_Flip(g_screen) == -1)
						{
							delete [] p_threats_3;
							SDLCommonFunc::CleanUp();
							SDL_Quit();
							return 0;
						}
					}
						else 
						{
							int ret_menu = SDLCommonFunc::ShowMenu_lost(g_screen,g_font_text_note_2);
							if(ret_menu == 0)
							{
								is_quit =  true;
							}
						}
					}

					
				
		




				// đạn máy bay và đá

				std::vector<AmoObject*> amo_list = human_object.GetAmoList();

				for(int idd = 0; idd< amo_list.size(); idd++)
				{
					AmoObject* p_amo = amo_list.at(idd);
					if(p_amo != NULL)
					{
						bool ret_colll = SDLCommonFunc::CheckCollision(p_amo->GetRect(),da->GetRect());
						if(ret_colll)
						{
							
							da->Reset(0-idd*400);
							human_object.RemoveAmo(idd);

						}
					}
				}
			}
		}

		std::string val_str_mark = std::to_string(mark);
		//std::string val_str_mark = IntToString(mark_game);
		std::string strMark("Mark: ");
	
		strMark += val_str_mark;

		mark_game.SetText(strMark);
		mark_game.SetRect(500,10);
		mark_game.CreateText(g_font_text,g_screen);


		std::string note("Cannot allow a user under 18 to play more than 180 minutes per day.");
		mark_game.SetText(note);
		mark_game.SetRect(170,30);
		mark_game.CreateText(g_font_text_note,g_screen);

		//time
		std::string str_time = "Time: ";
		Uint32 time_val = SDL_GetTicks()/1000;
		std::string str_val = std::to_string(time_val);
		str_time += str_val;

		if(time_val< 6)
		{
			// màn 1
			std::string report_1("Challenge 1.");
			mark_game.SetText(report_1);
			mark_game.SetRect(250,250);
			mark_game.CreateText(g_font_text_note_1,g_screen);
		}else if(time_val >= 13 && time_val < 17)
		{
			std::string report_2("Challenge 2.");
			mark_game.SetText(report_2);
			mark_game.SetRect(250,250);
			mark_game.CreateText(g_font_text_note_1,g_screen);
		}else if(time_val >= 20 && time_val < 24)
		{
			std::string report_3("Challenge 3.");
			mark_game.SetText(report_3);
			mark_game.SetRect(250,250);
			mark_game.CreateText(g_font_text_note_1,g_screen);
		}else if(time_val >= 26 && time_val < 30)
		{
			std::string report_4("Challenge 4.");
			mark_game.SetText(report_4);
			mark_game.SetRect(250,250);
			mark_game.CreateText(g_font_text_note_1,g_screen);
		}else if(time_val >= 38 && time_val < 42)
		{
			std::string report_5("BOSS!.");
			mark_game.SetText(report_5);
			mark_game.SetRect(350,300);
			mark_game.CreateText(g_font_text_note_1,g_screen);
		}


		time_.SetText(str_time);
		time_.SetRect(SCREEN_WIDTH-150,30);
		time_.CreateText(g_font_text,g_screen);
		
		
		
		



		
			

			  // time

				

				
				
		

				
				
				
		// Da====================
		   //--------------------------------------------------------------------------------------------------------------------------------
		   // update screen
		    if(SDL_Flip(g_screen) == -1)
			   return 0;
		
	}
	delete[] p_threats;
	SDLCommonFunc::CleanUp();
	SDL_Quit();
	return 1;
}
//
//	
//}