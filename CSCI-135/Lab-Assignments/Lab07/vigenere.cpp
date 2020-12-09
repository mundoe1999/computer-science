/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: March 13, 2018
Modified on: December 05, 2020
Assignment: Lab 7C
Purpose: 
	To implement vigenere shift encryption on strings.
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

//Vigenere Encryption
string encryptVigenere(string plaintext, string keyword){
	string encryptText = "";
	int key_value = 0;
	
	for(int i = 0; i < plaintext.length(); i++){
		char c = plaintext[i];

		encryptText += shiftChar(c, keyword[key_value] - 97);

		// updates value if a shift has occurred
		if(isalpha(plaintext[i])){
			key_value++;
			key_value = key_value % keyword.length();
		}
	}
	
	return encryptText;

}

// Main Function Testing
int main(){
	string s;
	string keyword;
	
	// Asking for User Input
	cout << "Enter plaintext: ";
	getline(cin,s);	
	
	cout << "Enter keyword	: ";
	cin >> keyword;
	
	//gives you the new shifted encryption
	cout << "Ciphertext	: " << encryptVigenere(s, keyword) << endl;


	return 0;

}
