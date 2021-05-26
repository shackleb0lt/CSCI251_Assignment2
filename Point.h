#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<algorithm>
#include<string.h>
#include<iomanip>
#include<sstream>
#include<cmath>


using namespace std;
class Point
{
    public:
    int PointID;
    int x;
    int y;
    int getId()const ;
    int getX()const;
    int getY()const ;
    

    Point(int id=-1, int a=0,int b=0);
    
    bool operator ==(Point P);
    bool operator <(Point P);
    bool operator >(Point P);
    friend ostream& operator<<(ostream& os, const Point& pt);
};
#endif
