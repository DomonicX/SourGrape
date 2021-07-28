#include "Button.h"

Button::Button()
{

    //ctor
}

Button::~Button()
{
    //dtor
}

bool Button::isInsideButton(int mouseX, int mouseY)
{
    if(mouseX > pos.X && mouseX < pos.X+pos.W && mouseY > pos.Y && mouseY < pos.Y+pos.H)
       {

        return true;
       }
    else return false;
}
void Button::Pressed()
{
    switch(ButtonType)
    {
        case PUSHBUTTON:
    switch(ButtonState)
    {
        case IDLE:
            std::cout << "PUSHButton is now ON\n";
            ButtonState=ACTIVE;
            break;
    }
        case TOGGLE:
    switch(ButtonState)
    {
        case TOGGLE_OFF:
   std::cout << "TOGGLEBUTTON is now ON\n";
            ButtonState=TOGGLE_ON;
            break;

        case TOGGLE_ON:
   std::cout << "TOGGLEBUTTON is now OFF\n";
            ButtonState=TOGGLE_OFF;
            break;
    }
            break;
    }

}

void Button::Display(SDL_Renderer &Rend)
{
if(isActive)
{

    SDL_Rect rec = {pos.X,pos.Y,pos.W,pos.H};

switch(ButtonType)
{
        case PUSHBUTTON:
            switch(ButtonState)
            {
            case ACTIVE:

    SDL_SetRenderDrawColor( &Rend, 171, 178, 185,0);
ButtonState=IDLE;

            std::cout << "PUSHButton is now OFF\n";
                break;
            case IDLE:


    SDL_SetRenderDrawColor( &Rend,244, 246, 247,0 );
                break;
            }

        case TOGGLE:
   switch(ButtonState)
            {
         case TOGGLE_ON :

    SDL_SetRenderDrawColor( &Rend, 171, 178, 185,0 );
            break;

         case TOGGLE_OFF :

    SDL_SetRenderDrawColor( &Rend, 244, 246, 247,0 );
            break;
            }

            break;
            }



SDL_RenderFillRect(&Rend,&rec);
    Label.display(Rend);
//    this->Label.display();


}
}
