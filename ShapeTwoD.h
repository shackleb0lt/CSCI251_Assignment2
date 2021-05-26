#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iomanip>
#include<sstream>
#include<cmath>


using namespace std;


class ShapeTwoD
{
    
    private:
    //Attributes
    string name;
    bool containsWarpSpace;
    int shapeId;
    double area;

    public:
    //Methods
    ShapeTwoD(){}               //Constructor
    virtual ~ShapeTwoD(){}      //Destructor
    string getName() const ;    //returns the name of shape 
    bool getContainsWarpSpace()const; //return whether the shape is warp space or normal space
    int getShapeId()const;          //returns the shapeID 

    double getArea() const;         //returns the area of the shape

    virtual double computeArea()=0; //Computes and returns the area of the shape 
    virtual bool isPointInShape(int x, int y)=0; //returns whether a point is inside or outside a shape
    virtual bool isPointOnShape(int x, int y)=0; //returns whether a point is on the perimeter of a shape


    virtual void setArea(double a); //assigns the  area of shape
    void setName(string n);         //assigns shape name 
    void setContainsWarpSpace(bool contains_WarpSpace); //assigns whether warp space or normal space
    void setShapeID(int ID);           // assigns shapeID based on number of shapes entered

    virtual string toString()            //outputs the shape data
    {
        ostringstream S;
        S<<"Shape["<<getShapeId()<<"]"<<endl;
        S<<"Name  : "<<getName()<<endl;
        S<<"Special Type :";
        if(getContainsWarpSpace())S<<"WS"<<endl;
        else S<< "NS"<<endl;
        S<<"Area "<<getArea()<<" units square"<<endl;
        return S.str();
    }

};
#endif