#ifndef  AMO_H_
#define  AMO_H_


#include "Commonfunc.h"
#include "BaseObject.h"
#define WIDTH_AMO_DAN_DO 100
#define HEIGHT_AMO_DAN_DO 301

#define WIDTH_AMO_2_TIA_DEN 40
#define HEIGHT_AMO_2_TIA_DEN 168

#define WIDTH_AMO_3_TIA_DEN 50
#define HEIGHT_AMO_3_TIA_DEN 100

#define WIDTH_AMO_4_TIA_DO_DEN 70
#define HEIGHT_AMO_4_TIA_DO_DEN 91

#define WIDTH_AMO_3_TIA_XANH_DEN 70
#define HEIGHT_AMO_3_TIA_XANH_DEN 123

#define WIDTH_AMO_EGG_CHUAN 30
#define HEIGHT_AMO_CHUAN 35

#define WIDTH_AMO_EGG_NHO 20
#define HEIGHT_AMO_NHO 22

class AmoObject : public BaseObject
{
public:
	enum AmoType
	{
		NONE = 0,
		MAN_FIRTS = 1,
		MAN_SECOND  =2,
		MAN_THIRT = 3,
		MAN_FOUR = 4,
		MAN_FIVE = 5,
	};

	AmoObject();
	~AmoObject();


	void HandleMove_amo(const int& x_border, const int& y_border);
	void HandleMoveuptodown();					
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