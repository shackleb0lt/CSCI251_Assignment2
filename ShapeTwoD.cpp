#include "ShapeTwoD.h"
string ShapeTwoD::getName()const{return name;}
bool ShapeTwoD::getContainsWarpSpace()const{return containsWarpSpace;}
int ShapeTwoD::getShapeId()const{return shapeId;}
double ShapeTwoD::getArea()const{return area;}

void ShapeTwoD::setContainsWarpSpace(bool contains_WarpSpace){containsWarpSpace=contains_WarpSpace;}
void ShapeTwoD::setName(string n){name = n;}
void ShapeTwoD::setShapeID(int ID){shapeId=ID;}
void ShapeTwoD::setArea(double a){area = a;}

