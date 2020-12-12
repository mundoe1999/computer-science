/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: March 21, 2018
Modified on: December 11, 2020
Assignment: Lab 8B
Purpose: 
	Formats code to follow proper identation.
******************************************************************************/


#include <iostream>
using namespace std;

string removeLeadingSpaces(string line){
	string newString = "";
	int i = 0;
	
	while(i < line.length()){
		//If it's not a space, add that to new string
		//Also, if it is not empty, then add string
		if(!isspace(line[i]) || newString != ""){
			newString += line[i];
		}
			
		i++;
	} 
	
	return newString;
}

int countChar(string line, char c){
	int counter = 0;
	
	for(int i = 0; i < line.length(); i++){
		if(line[i] == c){
			counter++;
		}
	}
	return counter;
}

int main(){
	//Defining our variable
	string line;
	int spaces = 0;
	int LeftCurly = 0;
	int RightCurly = 0;
	
	// Getting each line
	while(getline(cin,line)){
		line = removeLeadingSpaces(line);		
 		LeftCurly = countChar(line, '{');
 		RightCurly = countChar(line, '}');
		
		if(spaces == 0){
			//Prints out the line			
			cout << line << endl;
			spaces += LeftCurly - RightCurly;
		} else{
		
			if(line[0] == '}'){
				for(int i = 0; i < spaces-1; i++){
				 cout << "\t";
				}
			} else{
				for(int i = 0; i < spaces; i++){
				 cout << "\t";
				}
			}
			//Prints out the line			
			cout << line << endl;

			spaces += LeftCurly - RightCurly;

		}
		

	
		
	}
	
	return 0;
}
