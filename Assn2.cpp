
#include "Assn2.h"
using namespace std;

//Generic functions for comparision of shapes
template <typename T> 
bool comp_ID(T P1,T P2) 
{
    return P1->getShapeId()<P2->getShapeId();
}
template <typename T> 
bool comp_asc(T P1,T P2)
{
    return (P1->getArea()<P2->getArea());
}
template <typename T> 
bool comp_dsc(T P1,T P2)
{
    return (P1->getArea()>P2->getArea());
}
template <typename T> 
bool comp_sp(T P1,T P2)
{
    if(P1->getContainsWarpSpace() && P2->getContainsWarpSpace()) return P1->getArea()>P2->getArea();
    if(P1->getContainsWarpSpace()) return true;
    if(P2->getContainsWarpSpace()) return false;
    return P1->getArea()>P2->getArea();
}

//Definitions of class Assn
Assn2::Assn2()
{
    choice = 1;
    vector<ShapeTwoD*> V;
    old_count=0;
}

void Assn2::start()
{
    while(1){
        bool choice_flag = true;
        print_menu();
        while(choice_flag)
        {
            get_choice();
            switch(choice)
            {
                case 1:
                    read_data();
                    break;
                case 2:
                    compute_area();
                    break;
                case 3:
                    sort(V.begin(),V.end(),comp_ID<ShapeTwoD *>);
                    print_data();
                    break;
                case 4:
                    sort_data();
                    break;
                case 5:
                    cout<<"Thank You"<<endl;
                    return;
                    break;
                default:
                    cout<<"Entered choice is absent in menu!! Try again."<<endl;
                    choice_flag=false;
                    break;
            }
            choice_flag=!choice_flag;
        }
        
    }
}

void Assn2::get_choice()
{
    cout<<"Please enter your choice :";
    cin>>choice;
    cout<<endl;
    cout<<endl;
}

void Assn2::print_menu()
{
    cout<<endl;
    cout<<"1)   Input sensor data"<<endl;
    cout<<"2)   Compute area(for all records)"<<endl;
    cout<<"3)   Print shapes report"<<endl;
    cout<<"4)   Sort shapes report"<<endl;
    cout<<"5)   Exit program"<<endl;
    cout<<endl;
}

void Assn2::read_data()
{
    string shape_name="";
    string sp_type;
    bool flag;
    cout<<"[Input sensor data]"<<endl;
    cout<<"Please enter name of shape:";
    cin>>shape_name;
    cout<<endl;
    cout<<"Please enter special type:";
    cin>>sp_type;
    cout<<endl;
    transform(sp_type.begin(), sp_type.end(), sp_type.begin(), ::toupper);
    if(sp_type=="WS")flag=true;
    else flag =false;
    
    transform(shape_name.begin(), shape_name.end(), shape_name.begin(), ::toupper);
    

    if(shape_name=="CROSS"){
        vector<Point*> VP;
        int x,y;
        for(int i=0;i<12;i++)
        {
            cout<<"Please enter x-ordinate of pt. "<<i<<" :";
            cin>>x;
            cout<<"Please enter y-ordinate of pt. "<<i<<" :";
            cin>>y;
            cout<<endl;
            VP.push_back(new Point(i,x,y));
        }
        ShapeTwoD *cTemp = new Cross(flag,V.size(),VP);
        V.push_back(cTemp);
    }

    else if(shape_name=="SQUARE" ||shape_name=="RECTANGLE"){
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cout<<"Please enter x-ordinate of pt. 1 :";
        cin>>x1;
        // cout<<endl;
        cout<<"Please enter y-ordinate of pt. 1 :";
        cin>>y1;
        cout<<endl;//<<endl;

        cout<<"Please enter x-ordinate of pt. 2 :";
        cin>>x2;
        // cout<<endl;
        cout<<"Please enter y-ordinate of pt. 2 :";
        cin>>y2;
        cout<<endl;//<<endl;

        cout<<"Please enter x-ordinate of pt. 3 :";
        cin>>x3;
        // cout<<endl;
        cout<<"Please enter y-ordinate of pt. 3 :";
        cin>>y3;
        cout<<endl;//<<endl;

        cout<<"Please enter x-ordinate of pt. 4 :";
        cin>>x4;
        // cout<<endl;
        cout<<"Please enter y-ordinate of pt. 4 :";
        cin>>y4;
        cout<<endl<<endl;
        int lx=min(x1,(min(x2,min(x3,x4))));
        int ly=min(y1,(min(y2,min(y3,y4))));
        int rx=max(x1,(max(x2,min(x3,x4))));
        int ry=max(y1,(max(y2,max(y3,y4))));
        if(shape_name=="RECTANGLE"){
            ShapeTwoD * ctemp = new Rectangle(flag,V.size(),Point(-1,lx,ly),Point(-1,rx,ry));
            V.push_back(ctemp);
        }
        else if(shape_name=="SQUARE"){
            ShapeTwoD * ctemp = new Square(flag,V.size(),Point(-1,lx,ly),Point(-1,rx,ry));
            V.push_back(ctemp);
        }
        
    }

    else if(shape_name=="CIRCLE"){
        int x ,y, r;
        cout<<"Please enter x-ordinate of center :";
        cin>>x;
        cout<<"Please enter y-ordinate of center :";
        cin>>y;
        cout<<endl;
        cout<<"Please enter radius of circle :";
        cin>>r;
        cout<<endl;
        ShapeTwoD * ctemp = new Circle(flag,V.size(),x,y,r);
        V.push_back(ctemp);
    }
    else {
        cout<<"Shape not found. Going back to main menu ..."<<endl;return;
    }
    cout<<endl<<"Record successfully stored. Going back to main menu ..."<<endl;
    cout<<endl;
}

void Assn2::compute_area()
{
    new_count=V.size();
    for(int i=0;i<V.size();i++)V[i]->setArea(V[i]->computeArea());
    cout<<"Computation Completed! ( "<< new_count-old_count <<" records were updated )";
    old_count=new_count;
}

void Assn2::print_data()
{
    cout<<"Total no. of records available = "<<V.size()<<endl<<endl;
    for(int i=0;i<V.size();i++){cout<<V[i]->toString();cout<<endl;}
}

void Assn2::sort_data()
{
    char op;

    cout<<"\ta)   Sort by area (ascending)"<<endl;
    cout<<"\tb)   Sort by area (descending)"<<endl;
    cout<<"\tc)   Sort by special type and area"<<endl;

    cout<<endl;
    cout<<"\tPlease select sort option('q' to go main menu):";
    cin>>op;
    cout<<endl;
    switch(op)
    {
        case('a'):
            cout<<"Sort by area (smallest to largest) ...\n\n";
            sort(V.begin(),V.end(),comp_asc<ShapeTwoD *>);
            print_data();
            break;
        case('b'):
            cout<<"Sort by area (largest to smallest) ...\n\n";
            sort(V.begin(),V.end(),comp_dsc<ShapeTwoD *>);
            print_data();
            break;
        case('c'):
            cout<<"Sort by special type and area ...\n\n";
            sort(V.begin(),V.end(),comp_sp<ShapeTwoD *>);
            print_data();
            break;
        case('q'):
            cout<<"\nReturning to Main Menu"<<endl;
            return;
            break;
        default:
            break;
    }
}






