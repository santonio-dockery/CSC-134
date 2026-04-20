/*
m6t1 - xp tracker
santoniod
4/13/26
gather xp per floor hen do stats
*/

#include <iostream>
using namespace std;

// chart function
void barChart(int xp[], int floors);


int main() {
    // set up variab;es
    const int SIZE = 5; // can only be changed at the compile time
    int xp[SIZE]; // fixed size
    double total = 0.0;
    double average;
    int max = 0;
    // input
    cout << "Dungeon XP Tracker" << endl;
    for (int i=0; i<SIZE; i++) {
    // get xp for floors 1-5
    cout << "Floor " << i+1 << " XP: ";
    cin >> xp[i];
}

// calculation 
for (int i=0; i<SIZE; i++) {
    // running total
    total += xp[i];
    if (xp[1] > max) {
        max = xp[1]; // if current is larger than max its the new max
            }
}
average = total / SIZE;
// output
cout << "Over " << SIZE << " Floors" << endl;
cout << "Total XP: " << total << endl;
cout << "Avg   XP: " << average << endl;
cout << "Best  XP: " << max << endl;
// run bar chart
barChart(xp, SIZE);
// end program
return 0;
}
void barChart(int xp[], int floors) {
    const int SCALE = 10; // 1 bar = 10 xp
    for (int i = 0; i < floors; i++) {
        cout << "F" << (i+1) << " | ";
        for (int b = 0; b < xp[i]/SCALE; b++) {
            cout << "🥹 "; // use ur emoji
        }
        
        cout << " " << xp[i] << "\n";
    }
}