/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Modified on: March 29, 2019
Assignment: Lab 1A
Purpose:
   This program grabs the smaller of the two numbers, given user input.

******************************************************************************/

#include <iostream>
using namespace std;

int smaller(int num_01, int num_02);

int main(){
  //Setting up user-inputted variables
  int number_01;
  int number_02;

  //Asking for user input
  cout << "Enter the first number: ";
  cin >> number_01;

  cout << "Enter the second number: ";
  cin >> number_02;

  //Outputs result
  cout << "The smaller of the two is: " << smaller(number_01, number_02) << endl;

  return 0;
}

int smaller(int num_01, int num_02){
  if(num_01 > num_02) return num_02;
  return num_01;
}
