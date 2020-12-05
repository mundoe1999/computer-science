/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 21, 2018
Modified on: December 05, 2020
Assignment: Lab 4A
Purpose: 
	Creates Box shape using user specified width and height.
******************************************************************************/

#include <iostream>
using namespace std;

int main(){

	// Variable Declaration
	int width;
	int height;
	
	// Asking user input
	cout << "Input width: ";
	cin >> width;
	
	cout << "Input height: ";
	cin >> height;
	cout << endl;
	
	// Shape Drawing
	for(int i = 0; i < height; i++){
	
		for(int j = 0; j < width; j++){
			cout << "*";
		}
		
		cout << endl;
	}
	
	return 0;

}
