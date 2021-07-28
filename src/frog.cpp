#include "frog.h"

frog::frog()
{
    //ctor
    std::cout << "\n ctor frog: creating frog object" << std::endl;
}

frog::~frog()
{

   std::cout << "\n dtor frog: deleting frog object" << std::endl;
   SDL_FreeSurface(Stexture);
   SDL_DestroyTexture(Texture);

}
frog::frog(const GameObject& object)
{
    std::cout << "gameobject COPY CONSTRUCT called" << std::endl;
}
GameObject* frog::Create(std::string type)
 {
    return  this;
 }

void frog::Update()
{

}
