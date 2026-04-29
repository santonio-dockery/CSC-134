/*
M7t2
santoniod
4/29/26
Pointer. Rectangles
*/

using namespace std;
#include<iostream>
#include "Rectangle.h"

// function prototypes
string setName();
void setName(string& name);

int main () {
    //pointer practice
    // & is reference(get the address of the data)
    // * is deference(get the data from the address)
    string name = "Bob";
    string * pName = &name;  //store the address in a piinte
    //setName(name);

    cout << "name    =" << name << endl;
    cout << "pName   =" << pName << endl;
    cout << "*pName  =" << *pName << endl;

    //part 2 - rectangles
    Rectangle rl;
    double w, l;
    cout << "Enter width and length, seperated by a space: ";
    cin >>  w >> l;
    rl.setWidth(w);
    rl.setLength(l);
    cout << "Area is: " << rl.getArea() << endl;
    rl.drawRectangle();
}

//full functions

string setName() {
    string name;
    cout << "Enter name:  ";
    cin >> name;
    return name;
}

void setName(string& name) {
    cout << "Enter name:  ";
    cin >> name;
}


