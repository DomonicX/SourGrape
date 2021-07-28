#include "ObjectBuilder.h"
#include <GameObject.h>

ObjectBuilder::ObjectBuilder()
{
    //ctor
}

ObjectBuilder::~ObjectBuilder()
{
    //dtor
}

GameObject* ObjectBuilder::create(std::string type)
{


    if(type=="Block")
    {
std::cout <<"Creating Block" << std::endl;;
        block* tempobject = new block();
tempobject->objectType = GameObject::OBJECT;
//tempobject->textureNum = 0;
std::cout << "Block object selected " << std::endl;
tempobject->imageFileLocation = "Towerdefensesprite.png";
tempobject->Stexture = IMG_Load(tempobject->imageFileLocation.c_str());
tempobject->animation = NULL;
//tempobject->animation = new Animation();
//tempobject->animation->AddSrect(0,0,TILE_SIZE,TILE_SIZE);
  tempobject->SrcR.x = 0;
  tempobject->SrcR.y = 0;
  tempobject->SrcR.w = 64;
  tempobject->SrcR.h = 64;

  tempobject->DestR.x = 0;
  tempobject->DestR.y = 0;
  tempobject->DestR.w = tempobject->SrcR.w;
  tempobject->DestR.h= tempobject->SrcR.h;

  tempobject->pos.X = 0;
  tempobject->pos.Y = 0;
  tempobject->pos.W = tempobject->SrcR.w;
  tempobject->pos.H = tempobject->SrcR.h;
SDL_SetColorKey(tempobject->Stexture, SDL_TRUE, SDL_MapRGB( tempobject->Stexture->format, 237, 28, 36 ) );
//tempobject->animation->AddSrect(222,222,32,32);
tempobject->type = "Block";
//tempobject->animation->frameRate = 100;

//tempobject->animation.AddSrect(396+24,15,16,16);

//tempobject->animation.AddSrect(396+24+24,15,16,16);

    tempobject->Movement = tempobject->NONE;
                return tempobject;
    }
    }
