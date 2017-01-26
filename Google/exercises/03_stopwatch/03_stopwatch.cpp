#include <iostream>

using namespace std;

int convertTime(int secondsIn);

int main(){
	
	int hours, minutes, seconds = 0;
	
	cout << "Number of seconds: ";
		
	while (!(cin >> seconds)){
		
		cout << "A non-numeric was entered." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	
	}
	
	minutes = seconds / 60;
	hours = minutes / 60;
	
	cout << "Hours: " << hours << endl;
	cout << "Minutes: " << (minutes % 60) << endl;
	cout << "Seconds: " << (seconds % 60) << endl;
	
	return 0;
}
