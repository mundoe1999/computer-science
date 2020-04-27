/******************************************************************************
File Name: Phoneme_Library_Search_Alt.cpp
Author: Esteban Mundo
Uploaded on: February 27, 2019
Updated on: April 27, 2020
Purpose:
  Altenative implementation to the original Phoneme Library Search. Removes
  unecessary repetition and improves on code runtime.
******************************************************************************/


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>

char ConvertToUpper(char c);
void UpperCaseString(std::string & originalString);
void splitOnSpace(std::string s, std::string & before, std::string & after);
bool CheckIfValid(std::string word);
std::string WordPronunciation(std::string word);
void PhonemeChecker(std::string orig_word, std::string orig_pronun, std::string dic_line, std::string words[]);

int main(){
	//Variables needed for this project
	std::string word;
	std::string pronunciation;
	std::string dic_line;	    // Used to get the specified line within the Dictionary
	std::string junk;

	//Asks for a word
	std::cout << "Enter a String: ";
	getline(std::cin, word);					//Gets the whole input

  auto start_time = std::chrono::high_resolution_clock().now(); //Record Start time
	UpperCaseString(word);		                //Makes the whole word uppercase
	pronunciation = WordPronunciation(word);	//Gets the pronunciation
	std::cout << std::endl;

	//Outputs the pronunciation
	if(CheckIfValid(word) && pronunciation != "Not found"){
        std::ifstream fin("cmudict.0.7a");
        // Initialize an empty array
        /* Positions :
        *  0 -> Identical Phonemes
        *  1 -> Additional Phoneme
        *  2 -> Removed Phoneme
        *  3 -> Replaced Phoneme
        */
        std::string words[4] = {"", "", "", ""}; 

		while(fin){
            //ignore the commented lines
			while(dic_line[0] == ';'){getline(fin, dic_line);}
            getline(fin, dic_line);
            PhonemeChecker(word, pronunciation, dic_line, words);
        }

        std::cout << "Pronunciation:	  " << pronunciation << "\n\n";
        std::cout << "Identical:        " << words[0] << '\n';
        std::cout << "Add Phoneme:      " << words[1] << '\n';
        std::cout << "Remove Phoneme:   " << words[2] << '\n';
        std::cout << "Replace:          " << words[3] << "\n\n";

	} else std::cout << "Not found\n";

    auto end_time = std::chrono::high_resolution_clock().now();
    std::chrono::duration<float, std::milli> runt_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
    double runtime_sum = runt_time.count();
    std::cout << runtime_sum << std::endl; //Prints out the time it took to run the program

}


//*****************************************************************************
// FUNCTION IMPLEMENTATION
//*****************************************************************************


// Helper Functions 
char ConvertToUpper(char c){
    //Checks if the character is a letter
    if(c >= 'a' && c <= 'z'){return(c-32);}
    return(c);
}

void UpperCaseString(std::string & originalString){
    std::string UpperString = "";
    //Converts all characters to Uppercase
    for(int i = 0; i < originalString.length(); i++){
        originalString[i] = ConvertToUpper(originalString[i]);
    }
}


bool CheckIfValid(std::string word){
	std::string junk;
	splitOnSpace(word,word,junk);

	for(int i = 0; i < word.length(); i++){
    	if(!((word[i] >= 'A' && word[i] <= 'Z') || word[i] == '\'')){
			return false;
		}
	}
	return true;
}

void splitOnSpace(std::string s, std::string & before, std::string & after) {
    // reset strings
    before = "";
    after = "";
    int i = 0;

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

std::string WordPronunciation(std::string word){
	std::string dictionary_line;
	std::string dic_word;
	std::string pronun;
	//Reads the Dictionary file
	std::ifstream fin("cmudict.0.7a");

	while(fin){
		getline(fin, dictionary_line);
		splitOnSpace(dictionary_line, dic_word, pronun);
        if(dic_word == word){
            fin.close();
            return pronun;
        }
	}
	fin.close();
	return "Not found";
}

// Actual implementations

void PhonemeChecker(std::string orig_word, std::string orig_pronun, std::string dic_line,  std::string words[]){
    std::string dictionary_line;
    std::string dic_word;
    std::string pronun;

    splitOnSpace(dic_line, dic_word, pronun);
    if(CheckIfValid(dic_word) && dic_word != orig_word){
        //If Phonemes are identical, return
        if(pronun == orig_pronun){
            words[0] += " " + dic_word;
        } else{
            std::string orig_phoneme[2] = {"", orig_pronun};
            std::string dict_phoneme[2] = {"", pronun};

            do{
                splitOnSpace(orig_phoneme[1], orig_phoneme[0], orig_phoneme[1]);
                splitOnSpace(dict_phoneme[1], dict_phoneme[0], dict_phoneme[1]);
            } while(dict_phoneme[0] == orig_phoneme[0] && (orig_phoneme[1] != "" || dict_phoneme[1] != ""));

            //Checks if the Phonemes are identical after one difference
            if(dict_phoneme[1] == orig_phoneme[1] && orig_phoneme[0] != "" && dict_phoneme[0] != ""){
                words[3] += " " + dic_word;
            }
            //Same Logic if Adding or Removing Phoneme
            else{
                std::string temp_split_orig;
                std::string temp_split_dic;
                std::string previous_phoneme;

                //Add Phoneme
                splitOnSpace(dict_phoneme[1], previous_phoneme,temp_split_dic);
                if(orig_phoneme[1] == temp_split_dic && previous_phoneme == orig_phoneme[0]){
                    words[1] += " " + dic_word;
                }

                //Remove Phoneme
                splitOnSpace(orig_phoneme[1], previous_phoneme,temp_split_orig);
                if(dict_phoneme[1] == temp_split_orig && previous_phoneme == dict_phoneme[0]){
                    words[2] += " " + dic_word;
                }
            }
        }
    }
}
