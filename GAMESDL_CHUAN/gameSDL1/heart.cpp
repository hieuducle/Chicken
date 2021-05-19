#include "heart.h"

Heart::Heart()
{

}

Heart::~Heart()
{

}

void Heart::Addpos(const int& xpos)
{
	pos_list_.push_back(xpos);
}


void Heart::Render(SDL_Surface* des)
{
	if(number_ == pos_list_.size())
	{
	   for(int i = 0; i < pos_list_.size(); i++)
	   {
		   // lấy vị trí size
		   rect_.x = pos_list_.at(i);
		   Show(des);
	   }
	}
}
void Heart::Init()
{
	LoadImg("timden.png");
	number_ = 3;
	if(pos_list_.size() > 0)
	{
		pos_list_.clear();
	}
	Addpos(20);
	Addpos(60);
	Addpos(100);

}
void Heart::Decrease()
{
	number_ --;
	pos_list_.pop_back();

}
