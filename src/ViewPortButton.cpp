#include "ViewPortButton.h"


ViewPortButton::~ViewPortButton()
{
    //dtor
}
ViewPortButton::ViewPortButton(Type type,int PosX,int PosY,int posW,int posH,std::string buttonLabel,int TextSize)
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
void ViewPortButton::SetViewPort(ViewPort& newViewPort)
{
currentViewPortSelected= &newViewPort;
}

void ViewPortButton::Update()
{
    //std::cout << "active update \n";
    switch(ButtonState)
    {
    case ACTIVE:

    if(Title=="LoadMap")
    {
//                                    currentViewPortSelected->LoadMap(*gRenderer,TileSelectionViewPort,readMapObjectFile);

    }
    if(Title=="SaveMap")
    {
//                              currentViewPortSelected->SaveMap(this-,writeMapObjectFile);


    }
       if(Title=="NEXTLAYER")
       {
if(currentViewPortSelected->maxLayer==currentViewPortSelected->currentLayer)
{
}else
{

        currentViewPortSelected->currentLayer++;
           currentViewPortSelected->mapLoadPath = currentViewPortSelected->currentMap.tileObjects[currentViewPortSelected->currentLayer]->imageFileLocation;
std::cout << currentViewPortSelected->mapLoadPath << currentViewPortSelected->currentLayer << std::endl;

}
       }
       if(Title=="BACKLAYER")
       {
           if(currentViewPortSelected->currentLayer!=0)
{
       currentViewPortSelected->currentLayer--;
           currentViewPortSelected->mapLoadPath = currentViewPortSelected->currentMap.tileObjects[currentViewPortSelected->currentLayer]->imageFileLocation;
       std::cout << currentViewPortSelected->mapLoadPath << currentViewPortSelected->currentLayer << std::endl;
       }
 else
    {

}
    }
    if(Title=="Delete Tiles")
    {
        currentViewPortSelected->DeleteTileObjects();
    std::cout << "TESSSSSSSSSSSSSY\n";
    }
    if(Title=="Delete GameObjects")
     {

        currentViewPortSelected->DeleteMapObjects();
        // gameObjectSelected->a+=10;
     }
    if(Title=="SaveAs")
    {

    std::cout << "TESSSSSSSSSSSSSY\n";
      std::string NewMapPath;
std::cin >> NewMapPath;
currentViewPortSelected->currentMap.mapFileName = NewMapPath;
    }
        break;
    case IDLE:
        if(Title=="TEST")
   // gameObjectSelected->flipDirectionHorizontal(true);
    std::cout << "PUSHButton is IDEL????\n";
        break;

    case TOGGLE_ON:


       if(Title=="NEXTLAYER")
       {
           currentViewPortSelected->currentLayer++;
       }
    if(Title=="Grid")
    {
    std::cout << "toggle_on grid equal true\n";
currentViewPortSelected->isGrid = true;
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

         if(Title=="Grid")
    {
    std::cout << "toggle_on grid equal False\n";

    currentViewPortSelected->isGrid = false;
    }
   // std::cout << "toggle is now OFF\n";
        break;
}}
