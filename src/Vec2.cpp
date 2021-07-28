#include "Vec2.h"

Vec2::Vec2()
{
  X = 0;
  Y = 0;
  W = 0;
  H = 0;
}

Vec2::~Vec2()
{
    //dtor
}
bool Vec2::operator==(const Vec2& rhs) const
{
    if(this->X == rhs.X && this->Y == rhs.Y)

    {
    return true;
    }
    else return false;
}

Vec2 Vec2::operator*(float rhs) const  //lhs +rhs
    {
    return Vec2(X *rhs,Y *rhs);
    }

Vec2& Vec2::operator*=(float rhs)
    {
    return *this = *this * rhs;
    }

Vec2& Vec2::operator+=(const Vec2& rhs)
    {
    return *this = *this+rhs;
    }

Vec2 Vec2::operator+(const Vec2& rhs) const
    {
    return Vec2(X+rhs.X,Y+rhs.Y);
    }

Vec2 Vec2::operator-(const Vec2& rhs) const
    {
    return Vec2( X - rhs.X, Y - rhs.Y);
    }

Vec2& Vec2::operator-=(const Vec2& rhs)
    {
    return *this = *this - rhs;
    }

float Vec2::GetLength() const
    {
    return sqrt(GetLengthSq());
    }

float Vec2::GetLengthSq() const
    {
    return X*X + Y*Y;
    }


   Vec2& Vec2::Normalize()
   {
        return *this = GetNormalized();
   }
   Vec2 Vec2::GetNormalized() const
   {
        const float Len = GetLength();
        if(Len != 0.0f)
        {
            return *this * (1.0f/Len);
        }
        else return *this;
   }
double Vec2::GetRatio(double x, double y)
{
    double tempx = x-X;
    double tempy = y-Y;
//Mapping for rotation is only a little bit harder.

//x' = x * cos(a) + y * sin(a)
//y' = y * cos(a) - x * sin(a)
        return (atan2(tempy,tempx)) * 180.0000/3.1416;

}


