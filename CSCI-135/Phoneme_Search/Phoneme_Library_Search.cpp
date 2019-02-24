/*
Author: Esteban Mundo
Course: CSCI-135
Instructor: Alexey
Assignment: Pronounciation Project.
It does what it does
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
using namespace std;

//****************************************************
// These Functions are for setting up so that the String
// can be read for the cmudict file, as well as read the file itself
//****************************************************

//Helper function for converting a lowercase to uppercase

char ConvertToUpper(char c){
	//Checks if the string is a lowercase
	if(c >= 'a' && c <= 'z'){
		return(c-32);
	}
	//Returns back the character since it is either a number, Uppercase, or symbol
	return(c);
}

//This Function converts all characters in a string into uppercase

string UpperCaseString(string originalString){
	string UpperString = "";

	//Grabs the Original String, and converts all the characters to uppercase
	for(int i = 0; i < originalString.length(); i++){
		char c = originalString[i];
		UpperString += ConvertToUpper(c);
	}

	return UpperString;
}

//Helper function that splits a string into two After the first space

void splitOnSpace(string s, string & before, string & after) {
  // reset strings
  before = "";
  after = "";
  int i = 0;	//Apperently this works when i = 1, otherwise it will not work

  //Characters before the Space
  while(i < s.length() && !isspace(s[i])){
  	before += s[i];
  	i++;
  }

  //skips the space
  i++;
  //Characters after the space
  while(i < s.length()){
  	after += s[i];
  	i++;
  }
}


//****************************************************
// These Functions are used for the main part of the project
//****************************************************

//This function Checks if the String has anything other than A-Z or '
bool CheckIfValid(string word){
	string junk;
	splitOnSpace(word,word,junk);

	for(int i = 0; i < word.length(); i++){
		if(!((word[i] >= 'A' && word[i] <= 'Z') || word[i] == '\'')){
			return false;
		}
	}

	return true;
}

//Gives the pronuciation of the word
string WordPronun(string c){

	string lineDictionary;
	string word;
	string pronunciation;
	bool isCorrectChar = true;
	int charCounter = 0;
	//Reads the Dictionary file
	ifstream fin("cmudict.0.7a");

	while(fin){
		//Used to Reset the counter and other Variables for the next value
		getline(fin, lineDictionary);
		splitOnSpace(lineDictionary, word, pronunciation);
		charCounter = 0;
		isCorrectChar = true;

		//Checks letter by letter if it is right
		do{

			if(c[charCounter] != word[charCounter] && charCounter < c.length()){
				isCorrectChar = false;
			}

			//Adds +1 and checks for next character
			charCounter++;
		} while(isCorrectChar && charCounter < c.length());

		if(isCorrectChar){
			fin.close();
			return pronunciation;
		}
	}

	fin.close();
	return "Not found";

}

//Checks for identical pronunciations
string IdenticalPronun(string OriginalWord, string OriginalPronunciation, string word){

	//Variables
	string pronunciation;
	string trash;
	splitOnSpace(word, word, pronunciation);

	if(OriginalPronunciation == pronunciation && OriginalWord != word){
		return (" " + word);
	}

	return "";
}


string AddingPhoneme(string OriginalWord, string OriginalPronunciation, string word){
	string AP1 = OriginalPronunciation;
	string AP2 = word;
	string BP1;
	string BP2;
	string junk;

	int difference = 0;	//Counts the difference of the phonemes
	int PC1 = 0;		//Counter for first phoneme
	int PC2 = 0;		//Counter for Second Phoneme

	splitOnSpace(AP1, BP1, AP1);
	splitOnSpace(AP2, BP2, AP2);
	word = BP2;
	splitOnSpace(AP2, BP2, AP2);

	while(AP1 != "" && AP2 != ""){
		//If the Phoneme before is not equal to each other, Add +1 to difference Counter
		//And Split on the second one, as that is the different phoneme
		if(BP1 != BP2){
			PC2++;
			difference++;
			splitOnSpace(AP2, BP2, AP2);
		}
		//If they are the same, cut both phonemes out
		else if(BP1 == BP2){
			PC1++;
			PC2++;
			splitOnSpace(AP1, BP1, AP1);
			splitOnSpace(AP2, BP2, AP2);
		}
	}

	//This is to take into account for the last phoneme
	if(BP1 != BP2){difference++;}

	if(BP1 == BP2 && AP2 != "" && difference == 0){
		splitOnSpace(AP2, BP2, AP2);
		if(AP2 == ""){
			return (" " + word);
		}
	} else if(BP1 != BP2 && AP2 != "" && difference == 1){
			splitOnSpace(AP2, BP2, AP2);
			if(AP2 == "" && BP1 == BP2){
				return (" " + word);
		}
	} else if(AP1 == AP2 && BP1 == BP2 && difference == 1){
		return (" " + word);
	}
	return "";
}

string RemovingPhoneme(string OriginalWord, string OriginalPronunciation, string word){
	string AP1 = OriginalPronunciation;
	string AP2 = word;
	string BP1;
	string BP2;
	string junk;

	int difference = 0;	//Counts the difference of the phonemes
	int PC1 = 0;		//Counter for first phoneme
	int PC2 = 0;		//Counter for Second Phoneme

	splitOnSpace(AP1, BP1, AP1);
	splitOnSpace(AP2, BP2, AP2);
	word = BP2;
	splitOnSpace(AP2, BP2, AP2);

	do{
		if(BP1 != BP2){
			splitOnSpace(AP1, BP1, AP1);
			PC1++;
			difference++;
		} else{
				PC1++;
				PC2++;
				splitOnSpace(AP1, BP1, AP1);
				splitOnSpace(AP2, BP2, AP2);
		}


	}while(AP1 != "");

		if(BP1 != BP2){difference++;}
		while(BP1 != "" && BP2 == ""){
			splitOnSpace(AP1,BP1,AP1);
			PC1++;
		}
	int number = PC1 - PC2;
	if(AP1 == "" && AP2 == "" && difference == 1 && number == 1){
		return (" " + word);
	}
	return "";
}

string ReplacePhoneme(string OriginalWord, string OriginalPronunciation, string word){
	string AP1 = OriginalPronunciation;
	string AP2 = word;
	string BP1;
	string BP2;
	string junk;

	int difference = 0;	//Counts the difference of the phonemes
	int PC1 = 0;		//Counter for first phoneme
	int PC2 = 0;		//Counter for Second Phoneme

	splitOnSpace(AP1, BP1, AP1);
	splitOnSpace(AP2, BP2, AP2);
	word = BP2;
	splitOnSpace(AP2, BP2, AP2);

	do{
		if(BP1 != BP2){difference++;}
		if(BP2 == "" && BP1 != ""){ return "";}
		PC1++;
		PC2++;
		splitOnSpace(AP1, BP1, AP1);
		splitOnSpace(AP2, BP2, AP2);
	}while(BP1 != "");



	if(difference == 1 && BP2 == ""){



			return (" " + word);

	}
	return "";
}
//Testing
int main(){
	//Variables needed for this project
	string word;
	string pronunciation;
	string identical;
	string addPhoneme;		// Used to store all Added Phonemes
	string removePhoneme;	// Used to store all removed Phonemes
	string replacePhoneme;	// Used to store all replaced Phonemes

	string DictionaryLine;	// Used to get the specified line within the Dictionary
	string junk;
	string word02;

	//Asks for a word
	cout << "Enter a String: ";
	getline(cin, word);					//Gets the whole input
	word = UpperCaseString(word);		//Makes the whole word uppercase
	pronunciation = WordPronun(word);	//Gets the pronunciation
	cout << endl;
    //auto start_time = std::chrono::high_resolution_clock().now();
	//Outputs the pronunciation
	if(CheckIfValid(word) && pronunciation != "Not found"){
		cout << "Pronunciation:	   " << pronunciation << endl;
		cout << endl;
		//Checks Dictionary File
		ifstream fin("cmudict.0.7a");
		while(fin){
			while(DictionaryLine[0] == ';'){
				getline(fin, DictionaryLine);
			}

			getline(fin, DictionaryLine);
			splitOnSpace(DictionaryLine, word02, junk);
			if(CheckIfValid(word02)){
				//Adding all the words
				identical += IdenticalPronun(word, pronunciation, DictionaryLine);
				addPhoneme += AddingPhoneme(word, pronunciation, DictionaryLine);
				removePhoneme += RemovingPhoneme(word, pronunciation, DictionaryLine);
				replacePhoneme += ReplacePhoneme(word, pronunciation, DictionaryLine);
			}
		}
		fin.close();

		cout << "Identical       :" << identical << endl;
		cout << "Add Phoneme     :" << addPhoneme << endl;
		cout << "Remove Phoneme  :" << removePhoneme << endl;
		cout << "Replace Phoneme :" << replacePhoneme << endl;

	} else{
		cout << "Not found" << endl;

	}
	//auto end_time = std::chrono::high_resolution_clock().now();
    //std::chrono::duration<float, std::milli> runt_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
    //double runtime_sum = runt_time.count();
    //std::cout << runtime_sum << std::endl;
}
