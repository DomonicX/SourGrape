#include "ViewPort.h"

 ViewPort::ViewPort(float X,float Y,float H,float W,Camera &Camera, Map &SelectedMap,SDL_Renderer &selectedRend) : currentCamera(Camera), currentMap(SelectedMap), Rend(selectedRend)
        {
viewportpos.X = X;
viewportpos.Y = Y;
viewportpos.W = W;
viewportpos.H = H ;
           }

ViewPort::~ViewPort()
{
    //dtor
}


void ViewPort::display()
{
 float    screenX = viewportpos.X - currentCamera.Pos.X;
 float    screenY = viewportpos.Y - currentCamera.Pos.Y;

currentMap.Display(&Rend,screenX,screenY);
 //std::cout << screenY;
//            for(int i = 0; i<GameObjects.size(); i++)
    //        {
              //  if(isInsideViewport(*GameObjects[i]))
     //           GameObjects[i]->renderImage(Rend,screenX,screenY);
    //        }
}

        void ViewPort::displaySingleObject()
        {

 float    screenX = viewportpos.X - currentCamera.Pos.X;
 float    screenY = viewportpos.Y - currentCamera.Pos.Y;
    this->currentMap.tileObjects[currentLayer]->renderImage(&Rend,screenX,screenY);
        }
/**/

SDL_Rect ViewPort::selectRect(int x,int y)
{

    int h = viewportpos.H + this->currentCamera.Pos.H;
    int w = viewportpos.W + this->currentCamera.Pos.W;


if(x>=viewportpos.X && y>=viewportpos.Y && x<=h && y<=w)
    {
    int nx = (x-viewportpos.X)/TILE_SIZE;
    int ny = (y-viewportpos.Y)/TILE_SIZE;

    x = nx*TILE_SIZE;
    y = ny*TILE_SIZE;

return SDL_Rect {x,y,TILE_SIZE,TILE_SIZE};

    }
}


void ViewPort::DeleteTileObjects()
{
for (int i = 0; i<currentMap.tileObjects.size(); i++ )
    {
    currentMap.tileObjects.clear();

    }
}
        void ViewPort::DeleteMapObjects()

        {

for (int i = 0; i<currentMap.MapObjects.size(); i++ )
    {
  //  currentMap.MapObjects[i]->animation->Srect.clear();
     currentMap.MapObjects.clear();
    }
        }


void ViewPort::MoveLeft()
{
    this->currentCamera.MoveLeft();
}
void ViewPort::MoveRight()
{
    this->currentCamera.MoveRight();
}


void ViewPort::MoveUp()
{
    this->currentCamera.MoveUp();
}
void ViewPort::MoveDown()
{
    this->currentCamera.MoveDown();
}
void ViewPort::init()
{

}

void ViewPort::DrawGrid(int rows,int colums,int BoxSize)
{
    if(isGrid==true){
    SDL_Rect BorderRect = {viewportpos.X,viewportpos.Y,BoxSize,BoxSize};
SDL_SetRenderDrawColor( &Rend, 0, 0, 255, 255  );
int x = viewportpos.X;
int y = viewportpos.Y;
    for(int i = 0; i<rows; i++)
    {
        y= viewportpos.Y;
        for (int t = 0; t<colums; t++)
        {

            BorderRect.x = x;
            BorderRect.y = y;
            SDL_RenderDrawRect(&Rend,&BorderRect);
                 y+=BoxSize;
        }
        x+=BoxSize;
    }
}
}

        void ViewPort::Add(TileObject& selectedObject)
        {
 float    screenX = viewportpos.X - currentCamera.Pos.X;
 float    screenY = viewportpos.Y - currentCamera.Pos.Y;
 selectedObject.pos.X += screenX;
 selectedObject.pos.Y += screenY;

//            GameObjects.push_back(Objects);
            currentMap.Add(selectedObject);

        }

        void ViewPort::Add(GameObject& selectedObject)
        {
 float    screenX = viewportpos.X - currentCamera.Pos.X;
 float    screenY = viewportpos.Y - currentCamera.Pos.Y;
 selectedObject.pos.X += screenX;
 selectedObject.pos.Y += screenY;

//            GameObjects.push_back(Objects);
            currentMap.Add(selectedObject);

        }

        bool ViewPort::isInsideViewport(float xMouse ,float yMouse)
        {
//std::cout << "current cammera pos X/Y/H/W " << viewportpos.X << "/" <<viewportpos.Y  <<"/"
          //  << this->viewportpos.H << "/" <<viewportpos.W << std::endl;

                if(xMouse>=viewportpos.X && yMouse>=viewportpos.Y &&
                   xMouse<=viewportpos.H  && yMouse<=viewportpos.W)
                   {
                //       std::cout << "\n return true \n";
                       return true;
                   }
                   else return false;
        }


void ViewPort::LoadMap(ViewPort &tileSelectionViewPort,std::ifstream &read)
{

      ObjectFactory *tempGameObjectFactory = new ObjectBuilder(); //delete tempGameObjectFactory;

        TileFactory *tempTileFactory = new TileBuilder(); // delete tempTileFactory

GameObject * tempObject = NULL;
TileObject * tempTileObject = NULL;
    int tileSize;
    int gameObjectSize;
   std::string gameObjectTitle;
    int isGameObjectFlipped;
               std::string tempstring;
std::cout << "GameObjects deleting "<< std::endl;
this->DeleteMapObjects();

std::cout << "Tiles deleting "<< std::endl;
this->DeleteTileObjects();


read.open(currentMap.mapFileName.c_str());
read >> tileSize;
read >> gameObjectSize;

std::cout << "Number of Tile_Objects" <<  tileSize << std::endl;

std::cout << "Number of Game_Objects" <<  gameObjectSize << std::endl;


            for(int i = 0; i<tileSize; i++)
            {

                tempTileObject = tempTileFactory->create("Tile");

            //read >> tempObject->imageFileLocation;
                        read>> tempTileObject->pos.X;
                        read>> tempTileObject->pos.Y;
                        read>> tempTileObject->pos.W;
                        read>> tempTileObject->pos.H;
                        read>> tempTileObject->SrcR.x;
                        read>> tempTileObject->SrcR.y;
                        read>> tempTileObject->SrcR.w;
                        read>> tempTileObject->SrcR.h;
                        read>> tempTileObject->DestR.x;
                        read>> tempTileObject->DestR.y;
                        read>> tempTileObject->DestR.w;
                        read>> tempTileObject->DestR.h;

           std::getline(read, tempstring);
           tempTileObject->imageFileLocation = tempstring;

std::cout << "New Object x,y,w,h  " << tempTileObject->pos.X
<< "/" << tempTileObject->pos.Y
<< "/" << tempTileObject->pos.W
<< "/" << tempTileObject->pos.H <<"  -------" <<   tempstring <<"\n";

        currentMap.tileObjects.push_back(tempTileObject);
          tempTileObject = NULL;
            }
for(int i = 0; i<currentMap.tileObjects.size(); i++)
{

for(int j = 0; j<tileSelectionViewPort.currentMap.tileObjects.size(); j++)
{
//std::cout << std::endl << tileSelectionViewPort.currentMap.tileObjects[j]->imageFileLocation << std::endl;
//std::cout << currentMap.tileObjects[j]->imageFileLocation << std::endl;

    if(currentMap.tileObjects[i]->imageFileLocation==tileSelectionViewPort.currentMap.tileObjects[j]->imageFileLocation)
    {
//std::cout << "\nMATCH\n" << std::endl;
currentMap.tileObjects[i]->CreateobjectTexture(&Rend,tileSelectionViewPort.currentMap.tileObjects[j]->Stexture);

  }
 }
}



            for(int i = 0; i<gameObjectSize; i++)
            {

std::cout << tempstring <<  gameObjectSize << std::endl;


        //   getline(read,tempstring);
        std::getline(read, tempObject->imageFileLocation,'\n');

std::cout << tempstring << tempObject->imageFileLocation<< std::endl;
tempObject = tempGameObjectFactory->create(tempstring.c_str());


//tempObject = tempGameObjectFactory->create("Block");
tempObject->CreateobjectTexture(&Rend,tempObject->Stexture);

                        read>> tempObject->pos.X;
                        read>> tempObject->pos.Y;
                        read>> tempObject->pos.W;
                        read>> tempObject->pos.H;
                        read>> tempObject->SrcR.x;
                        read>> tempObject->SrcR.y;
                        read>> tempObject->SrcR.w;
                        read>> tempObject->SrcR.h;
                        read>> tempObject->DestR.x;
                        read>> tempObject->DestR.y;
                        read>> tempObject->DestR.w;
                        read>> tempObject->DestR.h;

            read >> isGameObjectFlipped;
            switch(isGameObjectFlipped)
                {
                    case 1:
           tempObject->flip = SDL_FLIP_HORIZONTAL;
                    break;

                    default:
            tempObject->flip = SDL_FLIP_NONE;
                    break;

                }
   read  >> tempObject->isVisable;
                currentMap.MapObjects.push_back(tempObject);

    tempObject = NULL;



            }
 delete tempTileFactory;
delete tempGameObjectFactory;
read.close();

}
void ViewPort::SaveMap(std::ofstream &write)
{

write.open(currentMap.mapFileName.c_str());
if(currentMap.tileObjects.size()==0)
{
write << 0 << "\n";
}
else
write <<    currentMap.tileObjects.size()  << "\n";
if(currentMap.MapObjects.size()==0)
{
write << 0 << "\n";
}
else
write <<    currentMap.MapObjects.size()   << "\n";


std::cout << "Number of Tile_Objects" <<  currentMap.tileObjects.size() << std::endl;

std::cout << "Number of Game_Objects" <<  currentMap.MapObjects.size() << std::endl;


            for(int i = 0; i<currentMap.tileObjects.size(); i++)
            {

            write <<    currentMap.tileObjects[i]->pos.X                << " \n";
            write <<    currentMap.tileObjects[i]->pos.Y                << "\n";
            write <<    currentMap.tileObjects[i]->pos.W                << "\n";
            write <<    currentMap.tileObjects[i]->pos.H                << "\n";
            write <<    currentMap.tileObjects[i]->SrcR.x               << "\n";
            write <<    currentMap.tileObjects[i]->SrcR.y               << "\n";
            write <<    currentMap.tileObjects[i]->SrcR.w               << "\n";
            write <<    currentMap.tileObjects[i]->SrcR.h               << "\n";
            write <<    currentMap.tileObjects[i]->DestR.x               << "\n";
            write <<    currentMap.tileObjects[i]->DestR.y               << "\n";
            write <<    currentMap.tileObjects[i]->DestR.w               << "\n";
            write <<    currentMap.tileObjects[i]->DestR.h               << "\n";

            write <<    currentMap.tileObjects[i]->imageFileLocation;

            }
                        for(int i = 0; i<currentMap.MapObjects.size(); i++)
            {

     //       write <<    currentMap.MapObjects[i]->type                 << "\n";
            write <<    currentMap.MapObjects[i]->imageFileLocation    << "\n";
            write <<    currentMap.MapObjects[i]->pos.X                << "\n";
            write <<    currentMap.MapObjects[i]->pos.Y                << "\n";
            write <<    currentMap.MapObjects[i]->pos.W                << "\n";
            write <<    currentMap.MapObjects[i]->pos.H                << "\n";
            write <<    currentMap.MapObjects[i]->SrcR.x               << "\n";
            write <<    currentMap.MapObjects[i]->SrcR.y               << "\n";
            write <<    currentMap.MapObjects[i]->SrcR.w               << "\n";
            write <<    currentMap.MapObjects[i]->SrcR.h               << "\n";
            write <<    currentMap.MapObjects[i]->DestR.x               << "\n";
            write <<    currentMap.MapObjects[i]->DestR.y               << "\n";
            write <<    currentMap.MapObjects[i]->DestR.w               << "\n";
            write <<    currentMap.MapObjects[i]->DestR.h               << "\n";
            write <<    currentMap.MapObjects[i]->flip                   << "\n";
            write <<    currentMap.MapObjects[i]->isVisable              << "\n";
            }

/*
    //myoutfile.open("example.txt", std::ios::out | std::ios::app | std::ios::binary);
            write.open("example.txt");
            for(int i = 0; i <.size(); ++i)
            {
//            myoutfile << GameObjects[i]->textureNum << "\n";
            write<< GameObjects[i]->getX() << "\n";
                write << GameObjects[i]->getY() << "\n";
            write << GameObjects[i]->Movement  << "\n";
            write << GameObjects[i]->flip  << "\n";
//             myoutfile << GameObjects[i]->speed  << "\n";
             write << GameObjects[i]->isVisable  << "\n";
     //       myoutfile << " object compelete \n";


*/

write.flush();
write.close();

}



