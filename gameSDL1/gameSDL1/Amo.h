#ifndef  AMO_H_
#define  AMO_H_


#include "Commonfunc.h"
#include "BaseObject.h"
#define WIDTH_AMO_LASER 100
#define HEIGHT_AMO_LASER 301
#define WIDTH_AMO_SPHERE 5
#define HEIGHT_AMO_SPHERE 5

class AmoObject : public BaseObject
{
public:
	enum AmoType
	{
		NONE = 0,
		LASER = 1,
		SPHERE = 2
	};

	AmoObject();
	~AmoObject();

	void HandleInputAction(SDL_Event events);
	void HandleMove(const int& x_border, const int& y_border);
	void HandleMoveuptodown();					  // toc do trung
	void HandleMoveuptodown_man3();
	void HandleMove_boss();
	int get_type() const {return amo_type_;}
	void  set_type(const int& type){amo_type_ = type;}
	
	bool get_is_move() const{return is_move_;}
	void set_is_move(bool is_move){is_move_ = is_move;} 
	void SetWidthHeight(const int &width, const int& height) {rect_.w = width; rect_.h = height;}


private:
	int x_val_;
	int y_val_;
	bool is_move_;
	 int amo_type_;
};

 #endif	 