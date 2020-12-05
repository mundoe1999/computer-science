/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 21, 2018
Modified on: December 05, 2020
Assignment: Lab 4C
Purpose: 
	Creates an X (cross) shape based on user specified size.
******************************************************************************/

#include <iostream>
using namespace std;

int main(){

	// variable declaration
	int size;

	// asking user input
	cout << "Input size: ";
	cin >> size;
	cout << endl;
	

	// shape drawing 
	for(int i = 0; i < size; i++){
	
		for(int j = 0; j < size; j++){
			// starts at corners, but moves across
			if(j == i || j == (size-i-1)){
				cout << "*";
			}
			else{
				cout << " ";
			}
			
		}	
		cout << endl;
	}
	
	return 0;
}
