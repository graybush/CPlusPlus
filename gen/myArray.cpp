#include <cstdio>
#include <iostream>
#include <stdexcept>

void populateArray(double min, double max, int num);

void printArray();

double* myArray;
double min;
double max;
int num;

int main(){

	min = 10;
	max = 100;
	num = 50;

	std::cout << "Hello World!" << std::endl;

	populateArray(min, max, num);

	printArray();



	return 0;
}

void populateArray(double min, double max, int num){

	myArray = NULL;

	if (num <= 0){
		throw std::invalid_argument("Number for array array caonnot be less than 0.\n");
	}

	if ( min > max){
		throw std::invalid_argument("Min cannot be greater than max.\n");
	}

	myArray = new double[num];

	if (num == 1){
		myArray[0] = min;
	} else {
		double delta = (max - min) / ((double) num - 1.0);
		for (int i = 0; i < num; i++){
			myArray[i] = min + delta * (i);
		}
	}
}

void printArray(){

	printf("myArray (min max n) = (%f %f %d) \n", min, max, num);

	for (int i = 0; i < num; i++){
		printf("%f\n", myArray[i]);
	}

}
