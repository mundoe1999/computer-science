/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 21, 2018
Modified on: December 05, 2020
Assignment: Lab 4D
Purpose: 
	Creates a right triangle based on user specified size
******************************************************************************/

#include <iostream>
using namespace std;

int main(){

	//variable declaration
	int size;

	// asking user input
	cout << "Input side length: ";
	cin >> size;
	cout << endl;
	

	// shape drawing
	for(int i = 0; i < size; i++){
		//Make j dependent on the value of i.
		for(int j = 0; j < (i+1); j++){
			cout << "*";
		}	
		cout << endl;
	}
	
	return 0;
}
