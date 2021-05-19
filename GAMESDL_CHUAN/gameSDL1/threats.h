#ifndef THREAT_OBJECT_H_
#define THREAT_OBJECT_H_
#include "Commonfunc.h"
#include "BaseObject.h"
#include "Amo.h"
#include <vector>


#define  WIDTH_THREAT 90
#define  HEIGHT_THREAT 60

class ThreatObject : public BaseObject
{
public:
	ThreatObject();
	~ThreatObject();

	void HandleMove(const int& x_border, const int& y_border);
	void HandleMove_for1(const int&x_border,const int& y_border);
	void HandleMove_for2(const int &x_border,const int& y_border);
	void HandleMove_for3(const int &x_border,const int& y_border);
	void HandleMove_boss(const int &x_border,const int& y_border);
	void HandleMove_ga5(const int &x_border,const int& y_border);

	void set_x_val(const int& val){x_val_ =val;}
	void set_y_val(const int& val){y_val_ = val;}
	int get_x_val()const {return x_val_;}
	int get_y_val()const {return y_val_;}

	void SetAmoList(std::vector<AmoObject*> amo_list) {p_amo_list_ = amo_list;}
	std::vector<AmoObject*> GetAmoList() const {return p_amo_list_;}


	 void InitAmo(AmoObject* p_amo);
	 void InitAmo_boss(AmoObject* p_amo);


	 void MakeAmo(SDL_Surface *des, const int& x_limit, const int& y_limit)	;
	  void MakeAmo_boss(SDL_Surface *des, const int& x_limit, const int& y_limit);
	  void MakeAmo_man3(SDL_Surface *des, const int& x_limit, const int& y_limit);
	 

	  void Reset(const int& xborder);
	 void Reset_man1(int x, int y);
	 void ResetAmo(AmoObject* p_amo);
	 
private:
	int x_val_;
	int y_val_;

	std::vector<AmoObject*> p_amo_list_;
};

#endif
