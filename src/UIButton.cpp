#include "UIButton.h"

UIButton::UIButton(Type type,int PosX,int PosY,int posW,int posH,std::string buttonLabel,int TextSize)
{
switch (type)
{
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
Label = Text(buttonLabel,TextSize,pos);
    this->Title = buttonLabel;
}


UIButton::~UIButton()
{
    //dtor
}

        void UIButton::Update(){    //std::cout << "active update \n";
    switch(ButtonState)
    {
    case ACTIVE:

    if(Title=="TEST")
    {
    std::cout << "TESSSSSSSSSSSSSY\n";
    }
        break;
    case IDLE:
    std::cout << "PUSHButton is IDEL????\n";
        break;

    case TOGGLE_ON:
 if(Title=="Clone")
    {
    currentSelectedUIObject->isCloning = true;
    }
    if(Title=="SnapAxis")
    {
    currentSelectedUIObject->isSnapAxis = true;
    }
       if(Title=="TileMode")
       {
std::cout << "TileMode selected  " << std::endl;
if(currentSelectedUIObject->currentMode==UI::NA)
    {
    currentSelectedUIObject->currentMode = UI::TILE_MODE;
    }
        }
        if(Title=="FreeMode")
        {

std::cout << "FreeMode";
if(currentSelectedUIObject->currentMode==UI::NA)
    {
    currentSelectedUIObject->currentMode = UI::NO_MODE;
    }
        }

        if(Title=="ObjectMode")
        {
if(currentSelectedUIObject->currentMode==UI::NA)
    {
    currentSelectedUIObject->currentMode = UI::OBJECT_MODE;
    std::cout << "ObjectMode";
    }
        }
        break;
    case TOGGLE_OFF:

 if(Title=="Clone")
    {
    currentSelectedUIObject->isCloning = false;
    }
    if(Title=="SnapAxis")
    {
    currentSelectedUIObject->isSnapAxis = false;
    }
       if(Title=="TileMode")
       {

std::cout << "tile mode OFF " << std::endl;
        currentSelectedUIObject->currentMode = UI::NA;
       }
    if(Title=="FreeMode")
    {

std::cout << "FREE MODE OFF" << std::endl;
        currentSelectedUIObject->currentMode = UI::NA;
    }

    if(Title=="ObjectMode")
    {
std::cout << "object MODE OFF" << std::endl;
        currentSelectedUIObject->currentMode = UI::NA;
    }
        break;
        }
}
        void UIButton::setUI(UI *newSelectedUIObject)
        {
        currentSelectedUIObject = newSelectedUIObject;
        }

         // UIButtons[i]->setUI(&linkedUIObject);
