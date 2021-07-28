#include "TextButton.h"

TextButton::TextButton(Type type,int PosX,int PosY,int posW,int posH,std::string buttonLabel)
{
    {
switch (type)

{case TEXT_FIELD:
    break;
case PUSHBUTTON :

std::cout << "setting type to PUSHBUTTON" << std::endl;
std::cout << "setting state to IDLE" << std::endl;
                ButtonType = PUSHBUTTON;
                ButtonState= IDLE;
    break;
case TOGGLE :
std::cout << "setting type to PUSHBUTTON" << std::endl;
std::cout << "setting state to TOGGLE_OFF" << std::endl;
                ButtonType = TOGGLE;
                ButtonState = TOGGLE_OFF;
    break;
}
  pos.X = PosX;
  pos.Y = PosY;
  pos.W = posW;
 pos.H =  posH;
Label = Text(buttonLabel,0,pos);
    this->Title = buttonLabel;
}
}

TextButton::~TextButton()
{
    //dtor
}

void TextButton::SetText(int newPosition)
{
        std::stringstream stm;
  stm << newPosition;
Label.title = stm.str().c_str();

}

void TextButton::SetstringText(std::string newString)
{
        std::stringstream stm;
  stm << newString;
Label.title = stm.str().c_str();

}

void TextButton::Update(SDL_Renderer &Rend, TTF_Font & font)
{
SDL_Color color = { 0, 0, 0 };
   Label.surface = TTF_RenderText_Blended(&font,Label.title.c_str(), color);
   Label.texture = SDL_CreateTextureFromSurface(&Rend,Label.surface);
    //SDL_FreeSurface(surface);
int textW,textH;
 SDL_QueryTexture(Label.texture, NULL, NULL,&textW,&textH);

 Label.dstrect = { pos.X, pos.Y,textW,textH};
}
void TextButton::Update(){}

