#include "Animation.h"

Animation::Animation()
{
    //ctor
}

Animation::~Animation()
{
}
void  Animation::AddSrect(int x,int y,int h, int w)
{
    SDL_Rect temp;
    temp.x = x ;
    temp.y = y;
    temp.h = h;
    temp.w = w;

    Srect.push_back(temp);
    maxFrame++;
}

  void Animation::UpdateAnimation()
  {
if(oldTime + frameRate < SDL_GetTicks())
     {   currentFrame++;
        oldTime = SDL_GetTicks();
       }
        if(currentFrame == maxFrame)
        {
            currentFrame = 0;
        }
  }
