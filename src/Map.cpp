#include "Map.h"

Map::Map(){}
Map::Map(Vec2 mapSize,std::string mapFileAddress)
{
    mapFileName = mapFileAddress;
    MapSize=mapSize;
    MapRect = {mapSize.X,mapSize.Y,mapSize.W,mapSize.H};
}
Map::~Map()
{
    //dtor
}
void Map::Update()
{
    ToString();
}

void Map::Add(TileObject& selectedObject)
{
    tileObjects.push_back(&selectedObject);
}

void Map::Add(GameObject& selectedObject)
{

    if(selectedObject.type=="SpriteSheet")
    {
        std::cout << "\n SPRIDDDTESHEET Added\n";
        MapObjects.push_back(&selectedObject);
    }
    if(selectedObject.type=="Block")
    {
            std::cout << "\n Block Added\n";
        MapObjects.push_back(&selectedObject);

    }

}
Camera* Map::LoadMap(std::string mapLoadPath)
{
//    return new Camera();
}
void Map::Display(SDL_Renderer* Rend, float camoffsetX = 0 ,float camoffsetY = 0)
{
     for(int i = 0; i<tileObjects.size(); i++)
            {
                tileObjects[i]->renderImage(Rend,camoffsetX,camoffsetY);
            }

            for(int i = 0; i<MapObjects.size(); i++)
            {
                MapObjects[i]->renderImage(Rend,camoffsetX,camoffsetY);
            }

    SDL_RenderDrawRect(Rend,&MapRect);
}
/*

void Map::Displaylayer(SDL_Renderer* Rend, float camoffsetX = 0 ,float camoffsetY = 0,float currentlayer)
{

            for(int i = 0; i<TileObjects.size(); i++)
            {
                TileObjects[i]->renderImage(Rend,camoffsetX,camoffsetY);
            }
            for(int i = 0; i<MapObjects.size(); i++)
            {
                MapObjects[i]->renderImage(Rend,camoffsetX,camoffsetY);
            }

    SDL_RenderDrawRect(Rend,&MapRect);
}
*/
