#include <iostream>

using namespace std;

float chirps2temp(int chirps);

int main (){

  int input_var = 0;

  do {
    cout << "Number of chirps: (-1 = quit) ";

    if (!(cin >> input_var)){

      cout << "A non-numeric was entered." << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    
    } else if (input_var != -1){
      cout << "The temperature is: " << chirps2temp(input_var) << endl;
    }

    } while (input_var != -1);
    
    cout << "Done." << endl;

  return 0;
}


float chirps2temp(int chirps){

  float temp;

  temp = (chirps + 40) / 4;

  return temp;
}
