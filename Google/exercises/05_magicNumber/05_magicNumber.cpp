#include <iostream>

using namespace std;

int reverseIt(int num);

int main(){
	
	int inputNumber, reversedNumber, reverseAgain, subtract, add = 0;
	
	cout << "input number: ";
		
	while (!(cin >> inputNumber)){
		
		cout << "A non-numeric was entered." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
	reversedNumber = reverseIt(inputNumber);
	
	subtract = inputNumber - reversedNumber;
	
	cout << "reverse it: " << reversedNumber << endl;
	cout << "subtract: " << inputNumber << " - " << reversedNumber << " = " << subtract << endl;
	
	reverseAgain = reverseIt(subtract);
	
	cout << "reverse it: " << reverseAgain << endl;
	
	add = reverseAgain + subtract;
	
	cout << "add: " << reverseAgain << " + " << subtract << " = " << add << endl;
		
	return 0;
}

int reverseIt(int num){
	
	int remainder, reversedNumber = 0;
	
	while(num != 0){
		
		remainder = num % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		num /= 10;
		
	}
	
	return reversedNumber;
	
}