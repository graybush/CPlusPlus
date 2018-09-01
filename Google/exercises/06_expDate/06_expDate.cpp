#include <iostream>

using namespace std;

string alpha2Month(string month);

int main(){
	
	string dateCode;
	
	cout << "Enter a 4 alphabetic date code, ex ARZM: ";
		
	while (!(cin >> dateCode)){
		
		cout << "A non-alphabetic was entered." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
	if (cin > 4){

		cout << "More than four charaters." << endl;
	}

	cout << dateCode[0] << endl;
	
	
	return 0;
}

string alpha2Month(string month){




}
