/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 5, 2018
Modified on: September 26, 2019
Assignment: Lab 2C
Purpose:
  Program that creates an array of 10 integers, and provides the user with 
  an interface to edit any of its elements.
******************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int myData[10];

  // Populate array
  for(int i = 0; i < 10; i++){
    myData[i] = 1;
  }
  
  int index = 0;
  int value = 1;

  // User Interface
  do {
    // Updates Value
    myData[index] = value;

    // Prints array
    for(int i = 0; i < 10; i++){
      cout << myData[i] << " ";
    }
      cout << endl;

    // Asks for input
    cout << "Input Index: ";
    cin >> index;
    cout << "Input Value: ";
    cin >> value;

  } while (0 <= index && index < 10);

  cout << "Index out of range. Exit." << endl;

	return 0;
}
