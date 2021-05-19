#include "MainObject.h"
#include "BaseObject.h"
MainObject::MainObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;	   
	rect_.h = HEIGTHT_MAIN_OBJECT;	  
	x_val_ = 0;
	y_val_ =0;

}

MainObject::~MainObject()
{
	
}
 void MainObject::HandleInputAction_1(SDL_Event events, Mix_Chunk* sound_bullet)

{


  if(events.type == SDL_KEYDOWN)
  {
	  switch (events.key.keysym.sym)
	  {
	  case SDLK_UP:
		  y_val_ -=  HEIGTHT_MAIN_OBJECT/4; 

		  break;
	  case SDLK_DOWN:
			y_val_ += HEIGTHT_MAIN_OBJECT/4;
		  break;
	  case SDLK_RIGHT:
			x_val_ += WIDTH_MAIN_OBJECT/4;
		  break;
	  case SDLK_LEFT:
			x_val_ -= WIDTH_MAIN_OBJECT/4;
		  break;
	  default:
		  break;
	  }  
  }
  // nhả phím
  else if(events.type == SDL_KEYUP)
  {
  switch (events.key.keysym.sym)
  {
  case SDLK_UP: y_val_ += HEIGTHT_MAIN_OBJECT/4;break;
  case SDLK_DOWN: y_val_  -= HEIGTHT_MAIN_OBJECT/4;break;
  case SDLK_RIGHT: x_val_ -=  WIDTH_MAIN_OBJECT/4;break;
  case SDLK_LEFT: x_val_ += WIDTH_MAIN_OBJECT/4;break;

  }	  
  }

  else if(events.type == SDL_MOUSEBUTTONDOWN)
  {

	  AmoObject* p_amo = new AmoObject();

	  if(events.button.button == SDL_BUTTON_LEFT)
	  {
		  p_amo->SetWidthHeight(WIDTH_AMO_DAN_DO,HEIGHT_AMO_DAN_DO);
			p_amo ->LoadImg("dando.png");
			p_amo ->set_type(AmoObject::MAN_FIRTS);
			//int ret =  Mix_PlayChannel(-1,sound_bullet,0);
			Mix_PlayChannel(-1,sound_bullet,0);

		
			p_amo->SetRect(this->rect_.x + 20, this ->rect_.y - 22);
			p_amo ->set_is_move(true);

		
			p_amo_list_.push_back(p_amo);
			
		
		
	  }
  }
 }


 void MainObject::HandleInputAction_2(SDL_Event events, Mix_Chunk* sound_bullet)
	 //void MainObject::HandleInputAction(SDL_Event events, Mix_Chunk* sound_bullet)
 {
	 if(events.type == SDL_KEYDOWN)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP:
			 y_val_ -=  HEIGTHT_MAIN_OBJECT/4; 

			 break;
		 case SDLK_DOWN:
			 y_val_ += HEIGTHT_MAIN_OBJECT/4;
			 break;
		 case SDLK_RIGHT:
			 x_val_ += WIDTH_MAIN_OBJECT/4;
			 break;
		 case SDLK_LEFT:
			 x_val_ -= WIDTH_MAIN_OBJECT/4;
			 break;
		 default:
			 break;
		 }  
	 }
	 else if(events.type == SDL_KEYUP)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP: y_val_ += HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_DOWN: y_val_  -= HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_RIGHT: x_val_ -=  WIDTH_MAIN_OBJECT/4;break;
		 case SDLK_LEFT: x_val_ += WIDTH_MAIN_OBJECT/4;break;

		 }	  
	 }
	 else if(events.type == SDL_MOUSEBUTTONDOWN)
	 {
		 AmoObject* p_amo = new AmoObject();
		 if(events.button.button == SDL_BUTTON_LEFT)
		 {
			 p_amo->SetWidthHeight(WIDTH_AMO_2_TIA_DEN,HEIGHT_AMO_2_TIA_DEN);
			 p_amo ->LoadImg("2tiaden.png");
			 p_amo ->set_type(AmoObject::MAN_SECOND);
			 //int ret =  Mix_PlayChannel(-1,sound_bullet,0);
			 Mix_PlayChannel(-1,sound_bullet,0);


			 p_amo->SetRect(this->rect_.x + 20, this ->rect_.y - 22);
			 p_amo ->set_is_move(true);

			 p_amo_list_.push_back(p_amo);

		 }  

	 }
 }

 void MainObject::HandleInputAction_3(SDL_Event events, Mix_Chunk* sound_bullet)
	 //void MainObject::HandleInputAction(SDL_Event events, Mix_Chunk* sound_bullet)
 {
	 if(events.type == SDL_KEYDOWN)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP:
			 y_val_ -=  HEIGTHT_MAIN_OBJECT/4; 

			 break;
		 case SDLK_DOWN:
			 y_val_ += HEIGTHT_MAIN_OBJECT/4;
			 break;
		 case SDLK_RIGHT:
			 x_val_ += WIDTH_MAIN_OBJECT/4;
			 break;
		 case SDLK_LEFT:
			 x_val_ -= WIDTH_MAIN_OBJECT/4;
			 break;
		 default:
			 break;
		 }  
	 }
	 else if(events.type == SDL_KEYUP)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP: y_val_ += HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_DOWN: y_val_  -= HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_RIGHT: x_val_ -=  WIDTH_MAIN_OBJECT/4;break;
		 case SDLK_LEFT: x_val_ += WIDTH_MAIN_OBJECT/4;break;

		 }	  
	 }
	 else if(events.type == SDL_MOUSEBUTTONDOWN)
	 {
		 AmoObject* p_amo = new AmoObject();
		 if(events.button.button == SDL_BUTTON_LEFT)
		 {
			 p_amo->SetWidthHeight(WIDTH_AMO_3_TIA_DEN,HEIGHT_AMO_3_TIA_DEN);
			 p_amo ->LoadImg("3tiaden.png");
			 p_amo ->set_type(AmoObject::MAN_THIRT);
			 //int ret =  Mix_PlayChannel(-1,sound_bullet,0);
			 Mix_PlayChannel(-1,sound_bullet,0);


			 p_amo->SetRect(this->rect_.x + 20, this ->rect_.y - 22);
			 p_amo ->set_is_move(true);

			 p_amo_list_.push_back(p_amo);

		 }  

	 }
	

 }
 void MainObject::HandleInputAction_4(SDL_Event events, Mix_Chunk* sound_bullet)
	 //void MainObject::HandleInputAction(SDL_Event events, Mix_Chunk* sound_bullet)
 {
	 if(events.type == SDL_KEYDOWN)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP:
			 y_val_ -=  HEIGTHT_MAIN_OBJECT/4; 

			 break;
		 case SDLK_DOWN:
			 y_val_ += HEIGTHT_MAIN_OBJECT/4;
			 break;
		 case SDLK_RIGHT:
			 x_val_ += WIDTH_MAIN_OBJECT/4;
			 break;
		 case SDLK_LEFT:
			 x_val_ -= WIDTH_MAIN_OBJECT/4;
			 break;
		 default:
			 break;
		 }  
	 }
	 else if(events.type == SDL_KEYUP)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP: y_val_ += HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_DOWN: y_val_  -= HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_RIGHT: x_val_ -=  WIDTH_MAIN_OBJECT/4;break;
		 case SDLK_LEFT: x_val_ += WIDTH_MAIN_OBJECT/4;break;

		 }	  
	 }
	 else if(events.type == SDL_MOUSEBUTTONDOWN)
	 {
		 AmoObject* p_amo = new AmoObject();
		 if(events.button.button == SDL_BUTTON_LEFT)
		 {
			 p_amo->SetWidthHeight(WIDTH_AMO_4_TIA_DO_DEN,HEIGHT_AMO_4_TIA_DO_DEN);
			 p_amo ->LoadImg("4tiadoden.png");
			 p_amo ->set_type(AmoObject::MAN_FOUR);
			 //int ret =  Mix_PlayChannel(-1,sound_bullet,0);
			 Mix_PlayChannel(-1,sound_bullet,0);


			 p_amo->SetRect(this->rect_.x + 20, this ->rect_.y - 22);
			 p_amo ->set_is_move(true);

			 p_amo_list_.push_back(p_amo);

		 }  

		 

	 }
	

 }
 void MainObject::HandleInputAction_5(SDL_Event events, Mix_Chunk* sound_bullet)
	 //void MainObject::HandleInputAction(SDL_Event events, Mix_Chunk* sound_bullet)
 {
	 if(events.type == SDL_KEYDOWN)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP:
			 y_val_ -=  HEIGTHT_MAIN_OBJECT/4; 

			 break;
		 case SDLK_DOWN:
			 y_val_ += HEIGTHT_MAIN_OBJECT/4;
			 break;
		 case SDLK_RIGHT:
			 x_val_ += WIDTH_MAIN_OBJECT/4;
			 break;
		 case SDLK_LEFT:
			 x_val_ -= WIDTH_MAIN_OBJECT/4;
			 break;
		 default:
			 break;
		 }  
	 }
	 else if(events.type == SDL_KEYUP)
	 {
		 switch (events.key.keysym.sym)
		 {
		 case SDLK_UP: y_val_ += HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_DOWN: y_val_  -= HEIGTHT_MAIN_OBJECT/4;break;
		 case SDLK_RIGHT: x_val_ -=  WIDTH_MAIN_OBJECT/4;break;
		 case SDLK_LEFT: x_val_ += WIDTH_MAIN_OBJECT/4;break;

		 }	  
	 }
	 else if(events.type == SDL_MOUSEBUTTONDOWN)
	 {
		 AmoObject* p_amo = new AmoObject();
		 if(events.button.button == SDL_BUTTON_LEFT)
		 {
			 p_amo->SetWidthHeight(WIDTH_AMO_3_TIA_XANH_DEN,HEIGHT_AMO_3_TIA_XANH_DEN);
			 p_amo ->LoadImg("3tiaxanhden.png");
			 p_amo ->set_type(AmoObject::MAN_FIVE);
			 //int ret =  Mix_PlayChannel(-1,sound_bullet,0);
			 Mix_PlayChannel(-1,sound_bullet,0);


			 p_amo->SetRect(this->rect_.x + 20, this ->rect_.y - 22);
			 p_amo ->set_is_move(true);

			 p_amo_list_.push_back(p_amo);

		 } 

	 }
	

 }
 
void MainObject::MakeAmo(SDL_Surface* des)
{
	for(int i = 0; i < p_amo_list_.size(); i++)
	{
	
	
		AmoObject* p_amo = p_amo_list_.at(i);
		if(p_amo != NULL)
		{
			if(p_amo ->get_is_move())
			{
				p_amo ->Show(des);
				p_amo ->HandleMove_amo(SCREEN_WIDTH,SCREEN_HEIGHT);

			}else 
			{
				if(p_amo != NULL)
				{
					p_amo_list_.erase(p_amo_list_.begin()+ i);
					

					//		   SDL_FreeSurface(p_amo);
					delete p_amo;
					p_amo = NULL;
				}
			}
		}
	}
};



void MainObject::HandleMove()
{
	rect_.x += x_val_;
	if(rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH)
	{
		rect_.x -= x_val_;
	}

	rect_.y += y_val_;
	if(rect_.y < 0 || rect_.y + HEIGTHT_MAIN_OBJECT > SCREEN_HEIGHT )
	{
		rect_.y -= y_val_;
	}
}



void MainObject::RemoveAmo(const int& idx)
{
	 for (int i = 0; i < p_amo_list_.size(); i++)
    {
        if (p_amo_list_.size() > 0 && idx < p_amo_list_.size())
        {
	
            AmoObject* p_amo = p_amo_list_.at(idx);

			p_amo_list_.erase(p_amo_list_.begin() + idx);
            if(p_amo != NULL)
            {
                delete p_amo;
                p_amo = NULL;
            }
        }
    }
	 
	  
}