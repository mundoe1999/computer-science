/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Modified on: March 29, 2019
Assignment: Lab 1B
Purpose:
   This program grabs the smaller of the three numbers, given user input.

******************************************************************************/

#include <iostream>
using namespace std;

int smaller(int num_01, int num_02);
int smaller3(int num_01, int num_02, int num_03);

int main(){
  //Setting up user-inputted variables
  int number_01;
  int number_02;
  int number_03;

  //Asking for user input
  cout << "Enter the first number: ";
  cin >> number_01;

  cout << "Enter the second number: ";
  cin >> number_02;

  cout << "Enter the third number: ";
  cin >> number_03;

  //Outputs result
  cout << "The smaller of the three is: " << smaller3(number_01, number_02,
                                               number_03) << endl;

  return 0;
}

int smaller(int num_01, int num_02){
  if(num_01 > num_02) return num_02;
  return num_01;
}

int smaller3(int num_01, int num_02, int num_03){
  return smaller(smaller(num_01, num_02), num_03);
}
