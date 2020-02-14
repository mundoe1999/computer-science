/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 13, 2018
Modified on: February 14, 2020
Assignment: Lab 3B
Purpose:
   Finds the minimum and maximum East storage in given TSV file
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
  double minimum, maximum;
  double eastStorageArray[366]; // The TSV file that was given was a leap year

  int counter = 0;

  // Adds all East Storage values to array
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    eastStorageArray[counter] = eastSt;
    counter++;
  }

  minimum = eastStorageArray[0];
  maximum = eastStorageArray[0];

  for(int i = 0; i < 366; i++){
    int value = eastStorageArray[i];


    if(minimum > value)
      minimum = value;

    if(maximum < value)
      maximum = value;
  }

  fin.close();
  return 0;

}