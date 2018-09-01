#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get
3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

int main(){

int X;
int Y;
int Z;
int total;


cout << "I will calculate the sum of all the multiples of  X and Y below Z: "
  << endl;
cin >> X;
cin >> Y;
cin >> Z;

  for (int i = 0; i <= Z; i++){

    if (i % X == 0 or i % Y == 0){
    
      total += i;
    }


  } 

cout << "The sum of all the multiples of " << X << " and " << Y << " below " 
  << Z << " are: " << total << endl;


return 0;
}
