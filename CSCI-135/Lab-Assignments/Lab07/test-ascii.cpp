/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: March 13, 2018
Modified on: December 05, 2020
Assignment: Lab 7A
Purpose: 
	To print out the ascii code from a given string
******************************************************************************/


#include <iostream>
using namespace std;

int main(){
	
	string s;
	cout << "Input: ";
	getline(cin,s);		//Important line of code if I want to include ' ' (spaces)
	

	// Prints character followed by corresponding ascii value
	for(int i = 0; i < s.length(); i++){
		cout << s[i] << " " << (int)s[i] << endl;
	}


	return 0;

}
