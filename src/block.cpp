#include "block.h"

block::block()
{
type = "Block";
}

block::~block()
{
   SDL_FreeSurface(Stexture);
   SDL_DestroyTexture(Texture);

}
block::block(const block &object)
{
}

GameObject* block::Create(std::string type)
 {
    return  this;
 }


void block::Update()
{
}


void block::renderImage(SDL_Renderer* Rend,float cameraOffSetX,float cameraOffSetY)
{
    this->DestR.x = pos.X - cameraOffSetX;
    this->DestR.y = pos.Y - cameraOffSetY;
    if(isVisable)
    SDL_RenderCopyEx(Rend,this->Texture,&this->SrcR,&this->DestR,angle,NULL,flip);
}
