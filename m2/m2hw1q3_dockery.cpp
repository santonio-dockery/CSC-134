 #include <iostream>
#include <iomanip>

using namespace std;

 int main() {  
 
 
 
 cout << "Question 3" << endl;
cout << endl;
 int boxes, slices, visitors, total_slices, slices_eaten, final_pieces;


cout << "How many boxes?:";
cin >> boxes;
cout << "How many slices per pizza?:";
cin >> slices;
cout << "How many people are attenging?:";
cin >> visitors;

total_slices = boxes * slices;
slices_eaten = visitors * 3;
final_pieces = total_slices - slices_eaten;

cout << "Leftover slices:" << final_pieces << endl;




 }
