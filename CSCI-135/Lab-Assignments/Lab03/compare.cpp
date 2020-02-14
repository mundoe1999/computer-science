/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 13, 2018
Modified on: February 14, 2020
Assignment: Lab 3C
Purpose:
   Compares the East and West Elevation with a given range.
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

  string dates[366];
  double eastElevationArray[366]; // The TSV file that was given was a leap year
  double westElevationArray[366];

  int counter = 0;

  // Asking for starting and ending dates
  string StartingDate, EndingDate;
	int starti, endi;


	cout << "enter starting date: ";
	cin >> StartingDate;

	cout << "Enter ending date: ";
	cin >> EndingDate;


  // Adds all East Storage values to array
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){

    if(StartingDate == date)
      starti = counter;
    
    if(EndingDate == date)
      endi = counter;

    dates[counter] = date;
    eastElevationArray[counter] = eastEl;
    westElevationArray[counter] = westEl;
    counter++;
  }


  // Compares the two dates
  for(int i = starti; i <= endi; i++){
    if(eastElevationArray[i] > westElevationArray[i])
      cout << dates[i] << " East\n";
    else if(eastElevationArray[i] < westElevationArray[i])
      cout << dates[i] << " West\n";
    else 
      cout << dates[i] << " Equal\n";
  }

  fin.close();
  return 0;

}