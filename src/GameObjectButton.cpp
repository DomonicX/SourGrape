#include "GameObjectButton.h"

GameObjectButton::GameObjectButton(Type type,int PosX,int PosY,int posW,int posH,std::string buttonLabel,int TextSize)
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
Label = Text(buttonLabel,TextSize,pos);
    this->Title = buttonLabel;
}
void GameObjectButton::SetGameObject(GameObject& NewGameObject)
{
gameObjectSelected = &NewGameObject;
}

GameObjectButton::~GameObjectButton()
{
    //dtor
}

void GameObjectButton::Update()
{
    //std::cout << "active update \n";
    switch(ButtonState)
    {
    case ACTIVE:
    if(Title=="TEST")
    {
    gameObjectSelected->flipDirectionHorizontal(true);
    std::cout << "TESSSSSSSSSSSSSY\n";
    }
    if(Title=="plus10")
     {
        // gameObjectSelected->a+=10;
     }
    if(Title=="Neg10")
    {
        //gameObjectSelected->a-=10;
    }
        break;
    case IDLE:
     //   if(Title=="TEST")
   // gameObjectSelected->flipDirectionHorizontal(true);
    std::cout << "PUSHButton is IDEL????\n";
        break;

    case TOGGLE_ON:
    if(Title=="FLIP")
    {
    std::cout << "toggle_on flip equal true\n";

    gameObjectSelected->flipDirectionHorizontal(false);
    }
    if(Title=="Plus10")
     {
         //gameObjectSelected->a+=10;
     }
    if(Title=="Neg10")
    {
//        gameObjectSelected->a=10;
    }
   // std::cout << "toggle is now ON\n";
        break;
    case TOGGLE_OFF:
         if(Title=="FLIP")
    {
    std::cout << "toggle_on flip equal False\n";
    gameObjectSelected->flipDirectionHorizontal(true);
    }
   // std::cout << "toggle is now OFF\n";
        break;
}}
