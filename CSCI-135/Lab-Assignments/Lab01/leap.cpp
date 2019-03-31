/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Modified on: March 29, 2019
Assignment: Lab 1C
Purpose:
   This program calculates whether the given year is a leap year or a common
   Year.

******************************************************************************/

#include <iostream>
using namespace std;


int main(){
  //Setting up user-inputted variable
  int year;

  //Asking for user input
  cout << "Enter year: ";
  cin >> year;

  //Calculate whether leap year or not
  if(year % 4 != 0){
    cout << "Common Year" << endl;
  }
  else if(year % 100 != 0){
    cout << "Leap Year" << endl;
  }
  else if(year % 400 != 0){
    cout << "Common Year" << endl;
  }
  else{
    cout << "Leap Year" << endl;
  }

  return 0;
}
