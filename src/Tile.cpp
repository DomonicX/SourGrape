#include "Tile.h"

Tile::Tile()
{
type = "Tile";
}

Tile::~Tile()
{
   SDL_FreeSurface(Stexture);
   SDL_DestroyTexture(Texture);

}

TileObject* Tile::Create(std::string type)
 {
    return  this;
 }
