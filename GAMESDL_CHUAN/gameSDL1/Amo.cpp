#include "Amo.h"
#include "Commonfunc.h"
AmoObject::AmoObject()
{
	rect_.x = 0;
	rect_.y = 0;
	x_val_ = 0;
	y_val_  =0;
	is_move_ = false;
	amo_type_ = NONE;
}

 AmoObject::~AmoObject()
{
	
}

 // di chuyển đạn của main
void AmoObject::HandleMove_amo(const int& x_border, const int& y_border)
{	  if(is_move_ == true)
	{
		rect_.y -= 20; 
	 if(rect_.y > y_border)
	 {
		 is_move_ = false;
	 }
}
}


void AmoObject::HandleMoveuptodown()
{
	rect_.y += 4;	 
	if(rect_.y > 670)
	{
		is_move_ = false;
	}
}
void AmoObject::HandleMoveuptodown_man3()
{
	rect_.y += 6;	 
	if(rect_.y > 670)
	{
		is_move_ = false;
	}
}
void AmoObject::HandleMove_boss()
{
	rect_.x += 6;
	if(rect_.x > SCREEN_WIDTH)
	{
		is_move_ = false;
	}
}
