/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: March 21, 2018
Modified on: December 11, 2020
Assignment: Lab 8A
Purpose: 
	Removes all leading space on a line.
******************************************************************************/

#include <iostream>
using namespace std;

string removeLeadingSpaces(string line){
	string newString = "";
	int i = 0;
	
	while(i < line.length()){
		//If it's not a space, add that to the new string
		//Also, if it is not empty, then add string
		if(!isspace(line[i]) || newString != ""){
			newString += line[i];
		}
			
		i++;
	} 
	
	return newString;
}


int main(){
	//Defining our variable
	string line;
	
	//This checks for each line
	while(getline(cin,line)){
		cout << removeLeadingSpaces(line) << endl; 
	}
	
	return 0;
}
