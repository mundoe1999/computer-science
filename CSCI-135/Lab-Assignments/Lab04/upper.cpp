/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 21, 2018
Modified on: December 05, 2020
Assignment: Lab 4E
Purpose: 
	Creates an upside down right triangle based on user specified size
******************************************************************************/

#include <iostream>
using namespace std;

int main(){

	// Variable Declaration
	int size;

	// Asking user Input
	cout << "Input side length: ";
	cin >> size;
	cout << endl;
	

	// Shape Drawing
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(j < i){
				cout << " ";
			}
			else{
				cout << "*";
			}
		}	
		cout << endl;
	}
	
	return 0;
}
