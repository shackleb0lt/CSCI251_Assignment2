
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iomanip>
#include<sstream>
#include<cmath>

#ifndef ASSN_H
#define ASSN_H

#include "ShapeTwoD.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Cross.h"


using namespace std;
// Header file for the menu class describing all the methods and variables.
class Assn2
{
    
    private:
    //Attributes
    int choice;                     //Attribute to store the choice entered by user
    int old_count, new_count;       //Attribute to update number of shapes
    
    //Methods
    
    void print_menu();              //Method to print out the menu and get the choice
    void get_choice();               //Method to get choice for the menu
    void read_data();               //Method to read data from user
    void compute_area();            //Methos to update area of all shapes
    void print_data();              //Method to view all shapes data
    void sort_data();             //Method to sort and print data according to preference

    public:
    vector<ShapeTwoD *>  V; 
    Assn2();
    void start();              
};
#endif