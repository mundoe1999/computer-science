/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 21, 2018
Modified on: December 05, 2020
Assignment: Lab 4G
Purpose: 
	Designs a 3x3 Checkerboard Pattern based on user-inputted height and width
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
			/**
			 * The best way to go about it is to think of this problem as a cycle. In order to get
			 * a 3 x 3 pattern before looping back to the original symbol, it would take a total of 6
			 * spaces. Therefore, we need to split this into "two" parts, (0,1,2) and (3,4,5), for both
			 * rows and colums.
			 */

			// Checks for rows that are (0,1,2)
			if(i % 6 < 3){
				// Checks for columns (0,1,2)
				if(j % 6 < 3){
					cout << "*";
				}
				else{
					cout << " ";
				}
			}
			
			// Checks for rows that are (3,4,5)
			else{
				// Checks for columns (3,4,5)
				if(j % 6 >= 3){
					cout << "*";
				}
				else{
					cout << " ";
				}
			}
		}
	cout << endl;
	}

	return 0;
}
