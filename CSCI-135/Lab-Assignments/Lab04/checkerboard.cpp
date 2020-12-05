/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 21, 2018
Modified on: December 05, 2020
Assignment: Lab 4B
Purpose: 
	Designs a Checkerboard Pattern based on user-inputted height and width
******************************************************************************/

#include <iostream>
using namespace std;

int main(){

	// Variable Declaration
	int width;
	int height;
	
	// Asking user Input
	cout << "Input width: ";
	cin >> width;
	
	cout << "Input height: ";
	cin >> height;
	cout << endl;
	
	// Shape Drawing 
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			// Using j + i to create offset for checkerboard pattern (by row)
			if((j+i) % 2 == 0){
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
