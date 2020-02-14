/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 5, 2018
Modified on: September 26, 2019
Assignment: Lab 2A
Purpose:
   Simple program that asks the user to input an integer in the range 
   0 < n < 100. If the number is out of range. The program keeps asking until
   it is out of range.
******************************************************************************/

#include <iostream>
using namespace std;

int main(){
  int input;

  // Ask for input
  cout << "Please enter an integer: ";
  cin >> input;

  // Check if number is in range
  while(input <= 0 || input >= 100){
    cout << "Please re-enter: ";
    cin >> input;
  }

  // Square and print value
  input *= input;
  cout << "Number Squared is " << input << endl;

  return 0;
}