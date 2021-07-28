#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
    type = "SpriteSheet";
}

SpriteSheet::~SpriteSheet()
{
   SDL_FreeSurface(Stexture);
   SDL_DestroyTexture(Texture);

}
SpriteSheet::SpriteSheet(const SpriteSheet &object)
{
    std::cout << "gameobject COPY CONSTRUCT called" << std::endl;

this->pos.X = object.pos.X;

this->pos.Y = object.pos.Y;
}

TileObject* SpriteSheet::Create(std::string type)
 {
    return  this;
 }


void SpriteSheet::Update()
{

}


void SpriteSheet::renderImage(SDL_Renderer* Rend,float cameraOffSetX,float cameraOffSetY)
{
    this->DestR.x = pos.X - cameraOffSetX;
    this->DestR.y = pos.Y - cameraOffSetY;
    if(isVisable)
    SDL_RenderCopyEx(Rend,this->Texture,&this->SrcR,&this->DestR,NULL,NULL,flip);
}
