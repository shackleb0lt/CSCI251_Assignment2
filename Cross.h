#ifndef CROSS_H
#define CROSS_H

#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iomanip>
#include<sstream>
#include<cmath>


#include "ShapeTwoD.h"
#include "Point.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

class Cross: public ShapeTwoD
{
    public:
    Cross(bool cWS,int Id,vector<Point *>  V);
    vector<Point *>Vertices;
    Rectangle R;
    Square Slowerleft,Slowerright,Suppperleft,Supperright;
    double computeArea();
    string toString();
    bool isPointInShape(int x,int y);
    bool isPointOnShape(int x,int y);


};
#endif