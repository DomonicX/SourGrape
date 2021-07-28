#include "SpriteLoader.h"

SpriteLoader::SpriteLoader()
{
    //ctor
}

SpriteLoader::~SpriteLoader()
{
    //dtor
}


        SpriteLoader::SpriteLoader(float x, float y,int Ssize,int rows,float columns,float Width,float Height)
        {         Wigdetpos.Y = y;
            Wigdetpos.X = x;
         this->rows=rows;
        this->columns=columns;
         spritesize = Ssize;
         Wigdetpos.W = Width;
         Wigdetpos.H = Height;
        }

void SpriteLoader::createTexture(SDL_Renderer *Rend)
{

 Mastersprite= SDL_CreateTextureFromSurface( Rend, Stexture );
  SDL_SetColorKey( Stexture, SDL_TRUE, SDL_MapRGB( Stexture->format, 0, 0xFF, 0xFF ) );
this->Mastersprite = SDL_CreateTextureFromSurface(Rend,Stexture);
}
void SpriteLoader::displayspirte(SDL_Renderer *Rend)
{

   SDL_RenderCopyEx(Rend,Mastersprite,&SRect,&DestR,NULL,NULL,SDL_FLIP_NONE);

     SDL_SetRenderDrawColor( Rend, 0, 0, 255, 255 );
int x = Wigdetpos.X;
int y = Wigdetpos.Y;
    for(int i = 0; i<rows; i++)
    {
        y= Wigdetpos.Y;
        for (int t = 0; t<columns; t++)
        {

            BorderRect.x = x;
            BorderRect.y = y;
        //    SDL_RenderDrawRect(Rend,&BorderRect);
                 y+=spritesize;
        }
        x+=spritesize;
    }
//this->DestR.x = pos.X;
 //   this->DestR.y = pos.Y;
   // if(isVisable)
 //
  //

}

SDL_Rect SpriteLoader::selectRect(int x,int y)
{

}
void SpriteLoader::init()
{

    DestR = {Wigdetpos.X,Wigdetpos.Y,Wigdetpos.W,Wigdetpos.H};
    SRect = {0,0,Wigdetpos.W,Wigdetpos.H};
    BorderRect = {0,0,spritesize,spritesize};
    }

void SpriteLoader::loadSprite(std::string path)
{   Stexture = IMG_Load(path.c_str());
    if(Stexture==NULL)
    {
        std::cout << "failed to load sprite" << std::endl;
    }

}


   // int GameObject::getX(){ return pos.X; }
//int GameObject::getY(){ return pos.Y; }
//void GameObject::setX(int i){ pos.X = i;}
//void GameObject::setY(int i){ pos.Y = i;}

