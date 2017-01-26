#include <iostream>
#include <cstdlib>

using namespace std;

float get_input(string assignment);

float cal_grade(float first, float second, float third,
                float fourth, float midterm, float final, float section);

int main(){

  float first, second, third, fourth, midterm, final, section, grade;

  first = get_input("first");
  second = get_input("second");
  third = get_input("third");
  fourth = get_input("fourth");
  midterm = get_input("midterm");
  final = get_input("final");
  section = get_input("section");

  grade = cal_grade(first, second, third, fourth, midterm, final, section);

  cout << "The final grade is: " << grade << endl;



  return 0;
}

float get_input(string num){

  float value = 0.0;

  do {
    cout << "Enter the score for the " << num << " assignment. (-1 = quit) " << endl;

    if (value == 0){

    	cout << "Done.\n";
    	break;

    } else if (!(cin >> value)){

      cout << "A non-numeric was entered." << endl;
      cin.clear();
      cin.ignore(10000, '\n');

    } else {

      return value;
    }
  } while (value != -1);

    cout << "Done." << endl;

}

float cal_grade(float first, float second, float third,
                float fourth, float midterm, float final, float section){

  float grade;

  grade = (((first + second + third + fourth) / 4) * 0.4) 
          + (midterm * 0.15) + (final * 0.35) + (section * 0.1);

  return grade;
}

