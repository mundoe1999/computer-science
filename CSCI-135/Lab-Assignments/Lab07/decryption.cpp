/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: March 13, 2018
Modified on: December 05, 2020
Assignment: Lab 7D
Purpose: 
	Taking the encryption from labs 7B and 7C, the strings are decrypted to the
	original value.
******************************************************************************/
#include <iostream>
using namespace std;

// Helper function for shifting string to the right
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

// Helper function for shifting string to the left
char shiftCharLeft(char c, int lshift){
	// Uppercase shift
	if(c >= 65 && c <= 90){
		return (char)(65 + ((c-65) - lshift+26)%26);
	}
	// Lowercase shift
	else if(c >= 97 && c <= 122){
		return (char)(97 + ((c-97) - lshift+26)%26);
	}
	
	return c ;
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

//Checks for Decryption
string decryptVigenere(string plaintext, string keyword){
	string decryptText = "";
	int key_value = 0;
	
	for(int i = 0; i < plaintext.length(); i++){
		char c = plaintext[i];
		//To make sure the variables are within the string range
		decryptText += shiftCharLeft(c, keyword[key_value] - 97);
		//Adds if the value is Alpha-numeric 
		if(isalpha(plaintext[i])){
			key_value++;
			key_value = key_value % keyword.length();
		}

	}
	
	return decryptText;

}
//Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift){
	string encryptText = "";
	
	for(int i = 0; i < plaintext.length(); i++){
		char c = plaintext[i];
		encryptText += shiftChar(c, rshift);
	}
	
	return encryptText;

}

string decryptCaesar(string plaintext, int rshift){
	string decryptText = "";
	
	for(int i = 0; i < plaintext.length(); i++){
		char c = plaintext[i];
		decryptText += shiftCharLeft(c, rshift);
	}
	
	return decryptText;

}

// Main Function Testing
int main(){
	string s;
	string keyword;
	int num;

	//strings for cypehred text
	string caesar;
	string vigerene;
	
	// Asking for User plaintext
	cout << "Enter plaintext: ";
	getline(cin,s);		
	
	
	/* Caesar Shift */
	cout << "= Caesar =\nEnter Shift: ";
	cin >> num;
	caesar = encryptCaesar(s, num);
	
	// Result
	cout << "Ciphertext: " << caesar << endl;
	cout << "Decrypted: " << decryptCaesar(caesar,num) << endl;
		
		
	/* Vigenere Shift */
	cout << "\n= Vigenere = \nEnter keyword: ";
	cin >> keyword;
	vigerene = encryptVigenere(s, keyword);

	// Result
	cout << "Ciphertext: " << vigerene << endl;
	cout << "Decrypted: " << decryptVigenere(vigerene,keyword) << endl;
	
	return 0;
}
