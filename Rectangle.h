#ifndef RECT_H
#define RECT_H

#include<iostream>
#include<algorithm>
#include<string.h>
#include<iomanip>
#include<sstream>
#include<cmath>


#include "ShapeTwoD.h"
#include "Point.h"


using namespace std;
class Rectangle:public ShapeTwoD
{
    public:

    Point lleft,uright;
    Rectangle(bool cWS=false,int Id=-1,Point a=Point(-1,0,0),Point b=Point(-1,0,0));
    
    double computeArea();
    string toString();
    bool isPointInShape(int x,int y);
    bool isPointOnShape(int x,int y);


};

#endif