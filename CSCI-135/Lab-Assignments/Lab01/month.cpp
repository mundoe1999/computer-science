/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Modified on: March 29, 2019
Assignment: Lab 1D
Purpose:
   This program calculates the amount of days in a month. Takes into account
   leap years.

******************************************************************************/

#include <iostream>
using namespace std;

bool isLeap(int year);
int calculateDays(int year, int month);

int main(){
  //Setting up user-inputted variable
  int year;
  int month;

  //Asking for user input
  cout << "Enter year: ";
  cin >> year;

  cout << "Enter month: ";
  cin >> month;

  //Print out result
  cout << calculateDays(year, month) << " days" << endl;


  return 0;
}

bool isLeap(int year){
  if(year % 4 != 0){
    return false;
  }
  else if(year % 100 != 0){
    return true;
  }
  else if(year % 400 != 0){
    return false;
  }
  return true;
}

int calculateDays(int year, int month){
  //February == 2
  if(month == 2){
    if(isLeap(year)){
      return 29;
    }
    return 28;
  }

  if((month % 2 == 1 && month < 8) || (month % 2 == 0 && month >= 8)){
    return 31;
  }

  //For all other Months
  return 30;
}
