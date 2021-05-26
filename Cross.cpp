#include "Cross.h"
using namespace std;
template <typename T> 
bool comp_Point_asc(T P1,T P2)
{
    return ((*P1)<(*P2));
}

Cross::Cross(bool cWS,int Id,vector<Point *> V)
{
    Vertices=V;
    setName("Cross");
    setShapeID(Id);
    setContainsWarpSpace(cWS);

    sort(V.begin(),V.end(),comp_Point_asc<Point *>);

 
    Slowerleft=Square(cWS,-1,Point(-1,V[0]->x,V[2]->y),Point(-1,V[3]->x,V[3]->y));
    Suppperleft=Square(cWS,-1,Point(-1,V[1]->x,V[1]->y),Point(-1,V[5]->x,V[5]->y));
    Slowerright=Square(cWS,-1,Point(-1,V[6]->x,V[6]->y),Point(-1,V[10]->x,V[10]->y));
    Supperright=Square(cWS,-1,Point(-1,V[8]->x,V[8]->y),Point(-1,V[11]->x,V[9]->y));
    R=Rectangle(cWS,-1,Point(-1,V[0]->x,V[2]->y),Point(-1,V[11]->x,V[9]->y));

}
double Cross::computeArea()
{
    R.setArea(R.computeArea());
    Slowerright.setArea(Slowerright.computeArea());
    Slowerleft.setArea(Slowerleft.computeArea());
    Suppperleft.setArea(Suppperleft.computeArea());
    Supperright.setArea(Supperright.computeArea());

    return R.getArea()-Slowerleft.getArea()-Slowerright.getArea()-Suppperleft.getArea()-Supperright.getArea();
}
bool Cross::isPointInShape(int x, int y)
{
    if(isPointOnShape(x,y))return false;
    bool inrec=R.isPointInShape(x,y);
    bool insq=Supperright.isPointInShape(x,y) || Suppperleft.isPointInShape(x,y)
            || Slowerleft.isPointInShape(x,y) || Slowerright.isPointInShape(x,y);

    if(inrec) return (!insq);
    return false;
}
bool Cross::isPointOnShape(int x, int y)
{
    bool onrec=R.isPointOnShape(x,y);
    bool onsq=Supperright.isPointOnShape(x,y) || Suppperleft.isPointOnShape(x,y)
            || Slowerleft.isPointOnShape(x,y) || Slowerright.isPointOnShape(x,y);
    return (onrec^onsq);
}
string Cross::toString()
{
    ostringstream S;
    S<<ShapeTwoD::toString();
    S<<"Vertices :"<<endl;
    for(int i=0;i<Vertices.size();i++)S<<(*Vertices[i]);

    ostringstream S1,S2;
    int count1 = 0,count2=0;
    S1<<"Points on perimeter : ";
    S2<<"Points within shape : ";

    for(int i=R.lleft.x;i<=R.uright.x;i++)
    {
        for(int j=R.lleft.y;j<=R.uright.y;j++)
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