#include "TileObject.h"

TileObject::TileObject()
{
    //ctor
}

TileObject::~TileObject()
{

    SDL_FreeSurface(Stexture);
    SDL_DestroyTexture(Texture);
}


TileObject *TileObject::Clone()
{
 return this;
}

void TileObject::CreateobjectTexture(SDL_Renderer* Rend,SDL_Surface *Mastersprite)
{

this->Texture= SDL_CreateTextureFromSurface( Rend, Mastersprite );
if(Texture==NULL)
{
    std::cout << "Not enough HEAP ";
}
SDL_SetColorKey( Mastersprite, SDL_TRUE, SDL_MapRGB( Mastersprite->format, 0, 0xFF, 0xFF ) );
//Texture = SDL_CreateTextureFromSurface(Rend,Mastersprite);
}
void TileObject::renderImage(SDL_Renderer* Rend,float cameraOffSetX,float cameraOffSetY)
{
    this->DestR.x = pos.X - cameraOffSetX;
    this->DestR.y = pos.Y - cameraOffSetY;
    if(isVisable)
    SDL_RenderCopyEx(Rend,this->Texture,&this->SrcR,&this->DestR,NULL,NULL,flip);
}
int TileObject::getX(){ return pos.X; }
int TileObject::getY(){ return pos.Y; }
void TileObject::setX(int i){ pos.X = i;}
void TileObject::setY(int i){ pos.Y = i;}


void TileObject::flipDirectionHorizontal(bool isFlipped)
{  switch (isFlipped)
{
    case SDL_FLIP_HORIZONTAL:
           flip = SDL_FLIP_NONE;
        break;
    case SDL_FLIP_NONE:
        flip = SDL_FLIP_HORIZONTAL;
    break;
}
}

void TileObject::swapVisable()
{
    if(this->isVisable)
    this->isVisable = false;
    else this->isVisable = true;
}
