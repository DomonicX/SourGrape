#include "Text.h"


Text::Text(std::string Title,int TextSize,Vec2 Pos)
{
textFront = TTF_OpenFont("ArialCE.ttf", TextSize);
title = Title;
    //ctor


pos = Pos;
}

void Text::Init(int FontSize,TTF_Font &font)
{
    textFront = &font;
    textSize = FontSize;

}
Text::~Text()
{
     TTF_CloseFont(textFront);

 SDL_DestroyTexture(texture);
    //dtor
}
void Text::CreateTextTexture(SDL_Renderer&Rend)
{
    SDL_Color color = { 28, 40, 51 };
   surface = TTF_RenderText_Blended(textFront,title.c_str(), color);
   texture = SDL_CreateTextureFromSurface(&Rend,surface);
    SDL_FreeSurface(surface);
int textW,textH,offSetX,offSetY,offSetW,offSetH;

 SDL_QueryTexture(texture, NULL, NULL,&textW,&textH);

pos.X = pos.X+pos.W/2-(textW/2);

pos.Y= pos.Y+pos.H/2-(textH/2);
 dstrect = { pos.X, pos.Y,textW,textH};

}


void Text::Update(SDL_Renderer& Rend,TTF_Font& font)
{
 SDL_Color color = { 28, 40, 51 };
   surface = TTF_RenderText_Blended(&font,title.c_str(), color);
   texture = SDL_CreateTextureFromSurface(&Rend,surface);
    //SDL_FreeSurface(surface);
int textW,textH;
 SDL_QueryTexture(texture, NULL, NULL,&textW,&textH);

 dstrect = { 0, 0,textW,textH};
}

void Text::display(SDL_Renderer &Rend)
{
  SDL_RenderCopy(&Rend, texture, NULL, &dstrect);
}
