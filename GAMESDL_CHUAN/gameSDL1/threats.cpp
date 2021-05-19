#include "threats.h"

ThreatObject::ThreatObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;

	x_val_ = 0;
	y_val_ = 0;
}
ThreatObject::~ThreatObject()
{
	if(p_amo_list_.size() > 0)
	{
		for(int i = 0; i  < p_amo_list_.size(); i++)
		{
			AmoObject* p_amo = p_amo_list_.at(i);
			if(p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
		p_amo_list_.clear();
	}
}

// 	khởi tạo đạn cho threat
void ThreatObject::InitAmo_boss(AmoObject* p_amo)
{
	if(p_amo)
	{
		bool ret = p_amo->LoadImg("eggchuan.png");
		if(ret)
		{
			p_amo->set_is_move(true);
			p_amo->SetWidthHeight(WIDTH_AMO_EGG_CHUAN,HEIGHT_AMO_CHUAN);
			p_amo->SetRect(rect_.x+130,rect_.y+170+ rect_.h*0.5);
			p_amo_list_.push_back(p_amo);
		}
	}
}
void ThreatObject::InitAmo(AmoObject* p_amo)
{
	if(p_amo)
	{
		bool ret = p_amo->LoadImg("eggnho.png");
		if(ret)
		{
			p_amo->set_is_move(true);
			p_amo->SetWidthHeight(WIDTH_AMO_EGG_NHO,HEIGHT_AMO_NHO);
		//	p_amo->set_type(AmoObject::SPHERE);
			p_amo->SetRect(rect_.x+50,rect_.y+50+ rect_.h*0.5);
			p_amo_list_.push_back(p_amo);
		}
	}
}


void ThreatObject::MakeAmo_man3(SDL_Surface *des, const int& x_limit, const int& y_limit)
{
	for(int i = 0;i < p_amo_list_.size(); i++)
	{
	
		AmoObject* p_amo  = p_amo_list_.at(i);
		if(p_amo)
		{

		
			if(p_amo->get_is_move())
			{

			
				p_amo->Show(des);

				
				p_amo->HandleMoveuptodown_man3();
			}
			else 
			{
				p_amo->set_is_move(true);
				p_amo->SetRect(rect_.x + 50, rect_.y+50 + rect_.h*0.5);
			}
		}
	}
}
	 void ThreatObject::MakeAmo(SDL_Surface *des, const int& x_limit, const int& y_limit)
	 {
		 for(int i = 0;i < p_amo_list_.size(); i++)
		 {
			 AmoObject* p_amo  = p_amo_list_.at(i);
			 if(p_amo)
			 {
				 if(p_amo->get_is_move())
				 {
					 p_amo->Show(des);
					 p_amo->HandleMoveuptodown();
					}
				 else 
				 {
					 p_amo->set_is_move(true);
					 p_amo->SetRect(rect_.x + 50, rect_.y+50 + rect_.h*0.5);
					}
			 }
			}
	 }
	 void ThreatObject::MakeAmo_boss(SDL_Surface *des, const int& x_limit, const int& y_limit)
	 {
		 for(int i = 0;i < p_amo_list_.size(); i++)
		 {
			 AmoObject* p_amo  = p_amo_list_.at(i);
			 if(p_amo)
			 {
				 if(p_amo->get_is_move())
				 {
					 p_amo->Show(des);
				//	 p_amo->HandleMove_boss();
					 p_amo ->HandleMoveuptodown();
				 }
				 else 
				 {
					 p_amo->set_is_move(true);
					 p_amo->SetRect(rect_.x + 130, rect_.y+170 + rect_.h*0.5);
				 }
			 }
		 }
	 }


void ThreatObject::HandleMove(const int& x_border, const int& y_border)
{
	rect_.y += y_val_;
	if(rect_.y > SCREEN_HEIGHT)
	{
	   rect_.y = 0;
	   int rand_x = rand()% SCREEN_WIDTH;
	   if(rand_x > SCREEN_WIDTH)
	   {
		   rand_x = SCREEN_WIDTH;
	   }
	   rect_.x =rand_x;
	  
	}
}
	void ThreatObject::HandleMove_for1(const int &x_border,const int& y_border)
	{
		rect_.y += y_val_;
//		rect_.x += y_val_;
		if(rect_.y >= 50)
		{
			rect_.y -= y_val_;	
		}
		
	}

void ThreatObject::HandleMove_for2(const int &x_border,const int& y_border)
{
		rect_.y += y_val_;
		if(rect_.y > 150)
		{
				rect_.y -= y_val_;
		}
}


void ThreatObject::HandleMove_for3(const int &x_border,const int& y_border)
{
	rect_.y +=  3;
	rect_.x += 3;
	if(rect_.y > SCREEN_HEIGHT)
	{
		rect_.y = 0;

	}
		if(rect_.x > SCREEN_WIDTH)
		{
			rect_.x = 0;
		}
}
  

// di chuyển threat
void ThreatObject::HandleMove_boss(const int &x_border,const int& y_border)
{
	rect_.y += 5;
	if(rect_.y > 200)
	{
		rect_.y -= 5;
		rect_.x += 5;
	}
}
void ThreatObject::HandleMove_ga5(const int &x_border,const int& y_border)
{
	rect_.y += 5;
	if(rect_.y > 100 && rect_.x < 500)
	{
		
			rect_.y -= 5;
			rect_.x += 5;	
	}
	if(rect_.x > 500)
	{
		rect_.y  -=5;
		rect_.x -= 20;
	}
}

void ThreatObject::ResetAmo(AmoObject* p_amo)
{
	p_amo->SetRect(rect_.x+80,rect_.y+50+ rect_.h*0.5);
}



void ThreatObject::Reset(const int& yborder)
{
	rect_.y = yborder;
	//rect_.x = SCREEN_WIDTH;
	//rect_.y = 0;
	int rand_x = rand()%1200;
	if(rand_x > SCREEN_HEIGHT)
	{
		rand_x = SCREEN_HEIGHT;
	}
	rect_.x =rand_x;

	for(int i = 0;i < p_amo_list_.size(); i++)
	{
		AmoObject* p_amo = p_amo_list_.at(i);
		if(p_amo)
		{
			ResetAmo(p_amo);
		}
	}
}
void ThreatObject::Reset_man1(int x, int y)
{
	 rect_.y = x;
	rect_.x = y;

	for(int i = 0;i < p_amo_list_.size(); i++)
	{
		AmoObject* p_amo = p_amo_list_.at(i);
		if(p_amo)
		{
			ResetAmo(p_amo);
		}
	}
}
