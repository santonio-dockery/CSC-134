// M5LAB2
// Header goes here

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.
double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double legth, double width, double area);

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);

   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************
double getLength() {
    // getLength asks the user to enter a recta length and returns as a doublr

    double length;
    cout << "Rectangle length: ";
    cin >> length ;
    return length;

}
double getWidth() {

    double width;
    cout << "Rectangle width: ";
    cin >> width ;
    return width;

}
double getArea(double length, double width) {
   double area = length * width;
   return area;

}
void displayData(double length, double width, double area) {
    // displayData this function takes 3 arguments it will then display these values
    cout << "Your rectangle is: " << length << " by " << width << endl;
    cout << "Area: " << area << endl;
    

}