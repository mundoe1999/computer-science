/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 5, 2018
Modified on: September 26, 2019
Assignment: Lab 2B
Purpose:
  Program that asks the user to input two integers (lower_bound and 
  upper_bound) and prints out all values within the range.
******************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int lower_bound, upper_bound;

  //Asking for Inputs
	cout << "Please enter lower bound: ";
	cin >> lower_bound;

	cout << "Please enter upper bound: ";
	cin >> upper_bound;

	//Prints out the range of the number between L to U
  while(lower_bound < upper_bound){
    cout << lower_bound++ << " ";
  }
  
	return 0;
}
