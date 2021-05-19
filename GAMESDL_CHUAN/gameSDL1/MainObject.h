#ifndef MAIN_OBJECT_H_
#define  MAIN_OBJECT_H_

#include "Commonfunc.h"
#include "BaseObject.h"
#include <vector>
#include "Amo.h"

#define WIDTH_MAIN_OBJECT 70
#define HEIGTHT_MAIN_OBJECT 70

class MainObject : public BaseObject	 
{
public:
	MainObject();
	~MainObject();

	void HandleInputAction_1(SDL_Event events, Mix_Chunk* sound_bullet);
	 void HandleInputAction_2(SDL_Event events, Mix_Chunk* sound_bullet);
	void HandleInputAction_3(SDL_Event events, Mix_Chunk* sound_bullet);
	 void HandleInputAction_4(SDL_Event events, Mix_Chunk* sound_bullet);
	void HandleInputAction_5(SDL_Event events, Mix_Chunk* sound_bullet);
	
	void HandleMove();
	void SetAmoList(std::vector<AmoObject*> amo_list) {p_amo_list_ = amo_list;}
	std::vector<AmoObject*> GetAmoList() const {return p_amo_list_;}
	void MakeAmo(SDL_Surface* des);
	void RemoveAmo(const int& idx);
private:
	int x_val_;
	int y_val_;	   
	std::vector<AmoObject*> p_amo_list_;

};
#endif
