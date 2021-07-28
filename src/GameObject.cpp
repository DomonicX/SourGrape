#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{

    SDL_FreeSurface(Stexture);
    SDL_DestroyTexture(Texture);
}


GameObject *GameObject::Clone()
{
 return this;
}

void GameObject::CreateobjectTexture(SDL_Renderer* Rend,SDL_Surface *Mastersprite)
{

this->Texture= SDL_CreateTextureFromSurface( Rend, Mastersprite );
if(Texture==NULL)
{
    std::cout << "Not enough HEAP ";
}
SDL_SetColorKey( Mastersprite, SDL_TRUE, SDL_MapRGB( Mastersprite->format, 0, 0xFF, 0xFF ) );
//Texture = SDL_CreateTextureFromSurface(Rend,Mastersprite);
}
void GameObject::renderImage(SDL_Renderer* Rend,float cameraOffSetX,float cameraOffSetY)
{
    this->DestR.x = pos.X - cameraOffSetX;
    this->DestR.y = pos.Y - cameraOffSetY;
    if(isVisable)
    SDL_RenderCopyEx(Rend,this->Texture,&this->animation->Srect[animation->currentFrame],&this->DestR,angle,NULL,flip);
}
int GameObject::getX(){ return pos.X; }
int GameObject::getY(){ return pos.Y; }
void GameObject::setX(int i){ pos.X = i;}
void GameObject::setY(int i){ pos.Y = i;}

void GameObject::updatecollision(GameObject *gameobject)
{

/*
    if(this->x+16 >= gameobject->DestR.x && this->x <= gameobject->DestR.x+gameobject->DestR.w-16
        && this->y == gameobject->getY())
    {
        if(gameobject->type == "water")
        {
            spawnPoint(16*12,16*28);
            std::cout << "water collision decteted\n";

        }
        if(gameobject->type == "log")
        {
                   switch(gameobject->Movement)
    {
    case UP:
        break;

    case RIGHT:
            this->x += gameobject->speed;
        break;

    case LEFT:
            this->x -= gameobject->speed;
        break;

    case DOWN:
        break;
    }
        }*/
}
void GameObject::updateMovement()
{
    switch(Movement)
    {
    case UP:
        break;
    case RIGHT:
//        pos.X+= speed;
    if(this->pos.X >= 224*2+16)
        this->pos.X = -16*9;
        break;
    case LEFT:
//          pos.X-= speed;
    if(this->pos.X <= -16*9)
        this->pos.X = 224*2+16;
        break;
    case DOWN:
        break;

    }
}




void GameObject::flipDirectionHorizontal(bool isFlipped)
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


void GameObject::UpdateSpeed(bool increaseSpeed)
{
    if(increaseSpeed)
    {
//    this->speed++;
    }
    else
    {
//        this->speed--;
//        if(this->speed == 0)
        {
//            speed = 0;
        }
    }
}

void GameObject::spawnPoint(int x,int y)
{
        this->pos.X = x;
        this->pos.X = y;
}


void GameObject::swapVisable()
{
    if(this->isVisable)
    this->isVisable = false;
    else this->isVisable = true;
}






