/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 21, 2018
Modified on: December 05, 2020
Assignment: Lab 4F
Purpose: 
	Draws a trapezoid based on user-inputted Height and Width
******************************************************************************/

#include <iostream>
using namespace std;

int main(){

	// variable delcaration
	int width;
	int height;

	 
	// Asking for user input
	cout << "Input width: ";
	cin >> width;

	cout << "Input height: ";
	cin >> height;
	cout << endl;


	// Calculates if the width and height are valid
	if((width+1) < (height*2)){
		cout << "Impossible shape!" << endl;
		return 0;
	}
	
	// Shape Drawing
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			
			//gets all numbers between i and (width-i)
			if(j >= i && j < (width - i)){
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
