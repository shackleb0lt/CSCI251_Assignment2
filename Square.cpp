#include "Square.h"


Square::Square(bool cWS,int Id,Point a,Point b)
{
    ShapeTwoD::setName("Square");
    ShapeTwoD::setShapeID(Id);
    ShapeTwoD::setContainsWarpSpace(cWS);
    lleft=a;
    uright=b;
}
double Square::computeArea()
{
    return (lleft.x-uright.x)*(lleft.x-uright.x);
}
bool Square::isPointInShape(int x, int y)
{
    if(x>lleft.x && x<uright.x && y>lleft.y && y<uright.y ) return true;
    return false;
}
bool Square::isPointOnShape(int x, int y)
{
    if (isPointInShape(x,y))return false;
    if(x==lleft.x || x== uright.x) return (y<uright.y && y>lleft.y);
    if(y==lleft.y || y== uright.y) return (x<uright.x && x>lleft.x);
    // if(x<lleft.x || x>uright.x || y<lleft.y || y>uright.y ) return false;
    return false;

}
string Square::toString()
{
    ostringstream S;
    S<<ShapeTwoD::toString();
    S<<"Vertices :"<<endl;
    S<<Point(0,lleft.x,lleft.y);
    S<<Point(1,lleft.x,uright.y);
    S<<Point(2,uright.x,uright.y);
    S<<Point(3,uright.x,lleft.y);

    ostringstream S1,S2;
    int count1 = 0,count2=0;
    S1<<"Points on perimeter : ";
    S2<<"Points within shape : ";
    for(int i=lleft.x;i<=uright.x;i++)
    {
        for(int j=lleft.y;j<=uright.y;j++)
        {
            if(isPointOnShape(i,j)){S1<<"("<<i<<", "<<j<<"), ";count1++;}
            if(isPointInShape(i,j)){S2<<"("<<i<<", "<<j<<"), ";count2++;}
        }
    }
    if(count1 ==0)S1<<"None!\n";
    else S1<<"\b\b \n";
    if(count2 ==0)S2<<"None!\n";
    else S2<<"\b\b \n";

    S<<endl;
    S<<S1.str();
    S<<endl;
    S<<S2.str();
    S<<endl;
    return S.str();
}