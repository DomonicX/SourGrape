#include "ButtonManager.h"

ButtonManager::~ButtonManager()
{
    //dtor
}


    void ButtonManager::Init(TTF_Font &font,int FontSize)
    {
        for(int i = 0; i<gameObjectbuttons.size(); i++)
        {
            gameObjectbuttons[i]->Label.Init(FontSize,font);

            gameObjectbuttons[i]->Label.CreateTextTexture(Rend);
        }
        for(int i = 0; i<viewPortbuttons.size(); i++)
        {
            viewPortbuttons[i]->Label.Init(FontSize,font);

            viewPortbuttons[i]->Label.CreateTextTexture(Rend);
        }

        for(int i = 0; i<objectBuilderButtons.size(); i++)
        {
            objectBuilderButtons[i]->Label.Init(FontSize,font);

            objectBuilderButtons[i]->Label.CreateTextTexture(Rend);
        }

        for(int i = 0; i<tileButtons.size(); i++)
        {
            tileButtons[i]->Label.Init(FontSize,font);

            tileButtons[i]->Label.CreateTextTexture(Rend);
        }

         for(int i = 0; i<UIButtons.size(); i++)
        {
            UIButtons[i]->Label.Init(FontSize,font);

            UIButtons[i]->Label.CreateTextTexture(Rend);
        }


  }
    void ButtonManager::LinkButtons(ObjectBuilderButton &linkedGameObject)
    {

        for(int i = 0; i<objectBuilderButtons.size(); i++)
        {

   {
   // objectBuilderButtons[i]->setObjectBuilder(linkedGameObject);

            objectBuilderButtons[i]->Update();


        }

                }


                }
    void ButtonManager::LinkButtons(TileObject &linkedTileObject)
    {

        for(int i = 0; i<tileButtons.size(); i++)
        {

          tileButtons[i]->SetTileObject(linkedTileObject);

            tileButtons[i]->Update();


    }
    }
    void ButtonManager::LinkButtons(GameObject &linkedGameObject)
    {

        for(int i = 0; i<gameObjectbuttons.size(); i++)
        {

          gameObjectbuttons[i]->SetGameObject(linkedGameObject);

            gameObjectbuttons[i]->Update();

    for(int i = 0; i<objectBuilderButtons.size(); i++)
    {
    }
        }

  }
    void ButtonManager::LinkButtons(ViewPort &linkedViewPortObjectd)
    {
        for(int i = 0; i<viewPortbuttons.size(); i++)
        {

          viewPortbuttons[i]->SetViewPort(linkedViewPortObjectd);

          viewPortbuttons[i]->Update();


        }
        }
    void ButtonManager::LinkButtons(UI &linkedUIObject)
    {
   for(int i = 0; i<UIButtons.size(); i++)
        {

          UIButtons[i]->setUI(&linkedUIObject);

          UIButtons[i]->Update();


        }
   }

    void ButtonManager::Update()
{
    for(int i = 0; i<gameObjectbuttons.size(); i++)
        {
            if(gameObjectbuttons[i]->ButtonType==Button::TEXT_FIELD)
            {

            }
        }
}


std::string ButtonManager::CheckButtonsPressed(int mouseX,int mouseY)
{
    switch(UIButtons[0]->currentSelectedUIObject->currentMode)
    {
    case UI::TILE_MODE:

for(int i = 0; i<tileButtons.size(); i++)
{

    if(tileButtons[i]->isInsideButton(mouseX,mouseY))
    {
        tileButtons[i]->Pressed();

            tileButtons[i]->Update();

       std::cout<< "Button ID :"<< tileButtons[i]->Title << "Was PUSHED"<<std::endl;

    }

}
break;
    case UI::OBJECT_MODE:
        for(int i = 0; i<gameObjectbuttons.size(); i++)
{

    if(gameObjectbuttons[i]->isInsideButton(mouseX,mouseY))
    {
        gameObjectbuttons[i]->Pressed();

            gameObjectbuttons[i]->Update();

       std::cout<< "Button ID :"<< gameObjectbuttons[i]->Title << "Was PUSHED"<<std::endl;

    }

}

for(int i = 0; i<objectBuilderButtons.size(); i++)
{

    if(objectBuilderButtons[i]->isInsideButton(mouseX,mouseY))
    {
        objectBuilderButtons[i]->Pressed();
        objectBuilderButtons[i]->Update();
        return objectBuilderButtons[i]->Label.title;
       std::cout<< "Button ID :"<< objectBuilderButtons[i]->Title << "Was PUSHED"<<std::endl;

    }
}
break;
    case UI::NO_MODE:


for(int i = 0; i<viewPortbuttons.size(); i++)
{

    if(viewPortbuttons[i]->isInsideButton(mouseX,mouseY))
    {
        viewPortbuttons[i]->Pressed();

        viewPortbuttons[i]->Update();

       std::cout<< "Button ID :"<< viewPortbuttons[i]->Title << "Was PUSHED"<<std::endl;

    }
}
break;
    }




for(int i = 0; i<UIButtons.size(); i++)
{

    if(UIButtons[i]->isInsideButton(mouseX,mouseY))
    {
        UIButtons[i]->Pressed();
        UIButtons[i]->Update();
       // return UIButtons[i]->Label.title;
       std::cout<< "Button ID :"<< UIButtons[i]->Title << "Was PUSHED"<<std::endl;

    }
}


return "No_Buttons_Pressed";
}
void ButtonManager::Add(GameObjectButton &selectedbutton)
{

    std::cout << "Added to button\n";
    gameObjectbuttons.push_back(&selectedbutton);
}

void ButtonManager::Add(UIButton &selectedbutton)
{

    std::cout << "Added to button\n";
    UIButtons.push_back(&selectedbutton);
}

void ButtonManager::Add(TileButton &selectedbutton)
{

    std::cout << "Added to button\n";
    tileButtons.push_back(&selectedbutton);
}
void ButtonManager::Add(ObjectBuilderButton &selectedbutton)
{

    std::cout << "Added to button\n";
    objectBuilderButtons.push_back(&selectedbutton);
}

void ButtonManager::Add(ViewPortButton &selectedbutton, ViewPort &selectedviewport)
{

          selectedbutton.SetViewPort(selectedviewport);
    std::cout << "Added to button\n";
    viewPortbuttons.push_back(&selectedbutton);
}
void ButtonManager::DisplayButtons()
{
    switch(UIButtons[0]->currentSelectedUIObject->currentMode)
    {
    case UI::TILE_MODE:

         for(int i = 0; i<tileButtons.size(); ++i)
        {
        tileButtons[i]->Display(Rend);
        }
        break;

    case UI::OBJECT_MODE:

    for(int i = 0; i<gameObjectbuttons.size(); ++i)
        {
        gameObjectbuttons[i]->Display(Rend);

        }
    for(int i = 0; i<objectBuilderButtons.size(); ++i)
        {
        objectBuilderButtons[i]->Display(Rend);
        }


    break;

    case UI::NO_MODE:
  for(int i = 0; i<viewPortbuttons.size(); ++i)
        {
        viewPortbuttons[i]->Display(Rend);
        }
    break;



}
   for(int i = 0; i<UIButtons.size(); ++i)
        {

        UIButtons[i]->Display(Rend);
        }

}
