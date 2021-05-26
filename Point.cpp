   #include"Point.h"
   
    int Point::getId()const {return PointID;}
    int Point::getX()const {return x;}
    int Point::getY()const {return y;}
    

    Point::Point(int id, int a,int b){PointID=id;x=a;y=b;}
    
    bool Point::operator ==(Point P)
    {
        return (x==P.x && y==P.y);
    }
    bool Point::operator <(Point P)
    {
        if(x<P.x) return true;
        if(x==P.x) return (y<P.y);
        return false; 
    }
    bool Point::operator >(Point P)
    {
        return !((*this)<P);
    }
    ostream& operator<<(ostream& os, const Point& pt)
    {
        os << "Point["<<pt.getId()<<"] : (" << pt.getX()<<"," <<pt.getY()<<")\n";
        return os;
    }