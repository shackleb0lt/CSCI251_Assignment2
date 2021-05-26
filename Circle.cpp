#include "Circle.h"

Circle::Circle(bool cWS,int Id,int x,int y,int r)
{
    setName("Circle");
    setShapeID(Id);
    setContainsWarpSpace(cWS);
    center = Point(0,x,y);
    radius=r;
}
double Circle::computeArea()
{
    return (double)M_PI*radius*radius;
}
bool Circle::isPointInShape(int x, int y)
{
    int dx=center.x-x;
    int dy=center.y-y;
    return( (dx*dx)+(dy*dy) )<(radius*radius);
}
bool Circle::isPointOnShape(int x, int y)
{
    int dx=center.x-x;
    int dy=center.y-y;
    return( (dx*dx)+(dy*dy) )==(radius*radius);
}
string Circle::toString()
{
    ostringstream S;
    S<<ShapeTwoD::toString();
    center.PointID=0;
    S<<"Center : "<<center;
    S<<"Radius : "<<radius<<endl;

    S<<"Points on perimeter : ";
    S<<"("<<center.x-radius<<", "<<center.y <<"), ";
    S<<"("<<center.x<<", "<<center.y-radius<<"), ";
    S<<"("<<center.x+radius<<", "<<center.y <<"), ";
    S<<"("<<center.x<<", "<<center.y+radius<<")"<<endl;
    
    S<<"Points within shape : ";
    int count = 0;
    for(int i=center.x-radius; i<=center.x+radius;i++)
    {
        for(int j=center.x-radius; j<=center.x+radius;j++)
        {
            if(isPointInShape(i,j)) {
                S<<"("<<i<<", "<<j<<"), ";
                count++;
            }
        }   
    }
    if(count ==0)S<<"None!\n";
    else S<<"\b\b \n";
    S<<endl;
    return S.str();
}
