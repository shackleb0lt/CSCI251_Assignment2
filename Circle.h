#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
#include<algorithm>
#include<string.h>
#include<iomanip>
#include<cmath>



#include "ShapeTwoD.h"
#include "Point.h"

using namespace std;


class Circle: public ShapeTwoD
{
    public:

    Point center; 
    int radius;

    Circle(bool cWS=false,int Id=-1,int x=-1,int y=-1,int r=-1);

    double computeArea();
    string toString();
    bool isPointInShape(int x,int y);
    bool isPointOnShape(int x,int y);


};
#endif
