#include "textobject.h"

TextObject::TextObject()
{
	//rect_.x = 500;
	//rect_.y = 500;
   ;
}

TextObject::~TextObject()
{

}

void TextObject::SetColor(const int & type)
{
	if(type == RED_TEXT)
	{
		SDL_Color color = {255,0,0};
		text_color = color;
	}
	else if(type == WHITE_TEXT)
	{
		SDL_Color color = {255,255,255};
		text_color = color;
	}
	else 
	{
		SDL_Color color = {0,0,0};
		text_color = color;
	}
}

void TextObject::CreateText(TTF_Font* font, SDL_Surface*des)
{
	p_object_ = TTF_RenderText_Solid(font,str_val.c_str(),text_color);
	Show(des);
}