/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: March 13, 2018
Modified on: December 05, 2020
Assignment: Lab 7B
Purpose: 
	To implement Ceasar Shift encryption on text
******************************************************************************/

#include <iostream>
using namespace std;

// Helper function for shifting string
char shiftChar(char c, int rshift){
	// Uppercase shift
	if(c >= 65 && c <= 90){
		return (char)(65 + ((c-65) + rshift)%26);
	}
	// Lowercase shift
	else if(c >= 97 && c <= 122){
		return (char)(97 + ((c-97) + rshift)%26);
	}
	
	return c;
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift){
	string encryptText= "";
	
	for(int i = 0; i < plaintext.length(); i++){
		char c = plaintext[i];
		encryptText += shiftChar(c, rshift);
	}
	
	return encryptText;

}


int main(){
	// initialize variables
	string s;
	int shift;
	
	// Ask for plaintext and how much shifting it requires
	cout << "Enter plaintext: ";
	getline(cin,s);		//Important line of code if I want to include ' ' (spaces)
	
	cout << "Enter shift	: ";
	cin >> shift;
	
	//gives you the newly shifted encryption
	cout << "Ciphertext	: " << encryptCaesar(s, shift) << endl;


	return 0;

}
