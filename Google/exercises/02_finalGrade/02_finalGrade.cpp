#include <iostream>
#include <cstdlib>

using namespace std;

float get_input(string assignment);

float cal_grade(float first, float second, float third,
                float fourth, float midterm, float final, float section);

int main(){

  float fir, sed, thi, fou, mid, fin, sec, grade;
//  string "first", "second", "third", "fourth", "midterm", "final", "section";

  fir = get_input("first");
  sed = get_input("second");
  thi = get_input("third");
  fou = get_input("fourth");
  mid = get_input("midterm");
  fin = get_input("final");
  sec = get_input("section");

  grade = cal_grade(fir, sed, thi, fou, mid, fin, sec);

  cout << "The final grade is: " << grade << endl;



  return 0;
}

float get_input(string num){

  float value;

  do {  
    cout << "Enter the score for the " << num << " assignment. (-1 = quit) ";

    if (!(cin >> value)){

      cout << "A non-numeric was entered." << endl;
      cin.clear();
      cin.ignore(10000, '\n');

    } else if (value >= 0){

      return value;
    }
  } while (value != -1);

    cout << "Done." << endl;
    exit(EXIT_FAILURE);
  
}

float cal_grade(float first, float second, float third,
                float fourth, float midterm, float final, float section){

  float grade;

  grade = (((first + second + third + fourth) / 4) * 0.4) 
          + (midterm * 0.15) + (final * 0.35) + (section * 0.1);

  return grade;
}

