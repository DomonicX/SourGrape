#include "TileBuilder.h"

TileBuilder::TileBuilder()
{
    //ctor
}

TileBuilder::~TileBuilder()
{
    //dtor
}

TileObject* TileBuilder::create(std::string type)
{
       if(type == "Tile")
    {

        Tile* tempobject = new Tile();
tempobject->objectType = TileObject::TILE;

  tempobject->SrcR.x = 0;
  tempobject->SrcR.y = 0;
  tempobject->SrcR.w = TILE_SIZE;
  tempobject->SrcR.h = TILE_SIZE;

  tempobject->DestR.x = 0;
  tempobject->DestR.y = 0;
  tempobject->DestR.w = tempobject->SrcR.w;
  tempobject->DestR.h= tempobject->SrcR.h;

  tempobject->pos.X = 0;
  tempobject->pos.Y = 0;
  tempobject->pos.W = tempobject->SrcR.w;
  tempobject->pos.H = tempobject->SrcR.h;

tempobject->type = "Tile";
//tempobject->animation.AddSrect(396+24,15,16,16);

//tempobject->animation.AddSrect(396+24+24,15,16,16);

    tempobject->Movement = tempobject->NONE;
                return tempobject;
    }
    if(type == "SpriteSheet")

    {
        SpriteSheet* tempobject = new SpriteSheet();

std::cout << "tilesheet object selected " << std::endl;
//tempobject->textureNum = 0;
tempobject->Stexture = NULL;
tempobject->type = "SpriteSheet";

  tempobject->SrcR.x = 0;
  tempobject->SrcR.y = 0;
  tempobject->SrcR.w = 315;
  tempobject->SrcR.h = 563;

tempobject->pos.X = 952;
tempobject->pos.Y = 26;
tempobject->pos.W = tempobject->SrcR.w;
tempobject->pos.H = tempobject->SrcR.h;

//  tempobject->DestR.x = 952;
  //tempobject->DestR.y = 26;
  tempobject->DestR.w = tempobject->SrcR.w;
  tempobject->DestR.h = tempobject->SrcR.h;
tempobject->type = "SpriteSheet";

//tempobject->animation.AddSrect(396+24,15,16,16);

//tempobject->animation.AddSrect(396+24+24,15,16,16);

    tempobject->Movement = tempobject->NONE;
                return tempobject;
    }

    }
