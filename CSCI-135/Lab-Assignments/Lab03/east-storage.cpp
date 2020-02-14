/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 13, 2018
Modified on: February 14, 2020
Assignment: Lab 3A
Purpose:
   Prints out East Storage levels based on inputted Date
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
  // Opening TSV file
  ifstream fin("Current_Reservoir_Levels.tsv");

  // Exit if file was not opened
  if(fin.fail()){
    cerr << "File cannot be opened for reading.\n";
    exit(1);
  }

  // Remove First line of file
  string junk;
  getline(fin, junk);

  //Initializing relevant variables
  string date, inDate;
  double eastSt, eastEl, westSt, westEl;

  cout << "Enter Date (MM/DD/YYYY): ";
  cin >> inDate;

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    if(date == inDate){
      cout << "East basin Storage: " << eastSt << " billion gallons" << endl;
    }
  }

  fin.close();
  return 0;

}