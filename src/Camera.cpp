#include "Camera.h"

#define TILE_SIZE  32

void Camera(){}
void Camera::Update()
{
    ToString();
}
Camera::~Camera()
{
    //dtor
}
void Camera::MoveLeft(){Pos.X-=TILE_SIZE; }
void Camera::MoveDown(){Pos.Y+=TILE_SIZE;}
void Camera::MoveUp(){Pos.Y-=TILE_SIZE;}
void Camera::MoveRight(){Pos.X+=TILE_SIZE;}
