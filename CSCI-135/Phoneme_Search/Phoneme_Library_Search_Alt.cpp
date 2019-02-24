/*
Name: Esteban Mundo
Course: Software Analysis and Design I
Assignment brief:
This is an alternative implementation of the Phoneme Libray Search. This cleans up most, if not all,
repetition within the original version.

Runtime is significantly improved from previous version.

*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>

char ConvertToUpper(char c);
void UpperCaseString(std::string & originalString);
void splitOnSpace(std::string s, std::string & before, std::string & after);
bool CheckIfValid(std::string word);
std::string WordPronunciation(std::string word);
void PhonemeChecker(std::string orig_word, std::string orig_pronun, std::string dic_line, std::string & identical, std::string & add_phoneme,
                    std::string & remove_phoneme, std::string & replace_phoneme);

int main(){
	//Variables needed for this project
	std::string word;
	std::string pronunciation;
	std::string dic_line;	    // Used to get the specified line within the Dictionary
	std::string junk;

	//Asks for a word
	std::cout << "Enter a String: ";
	getline(std::cin, word);					//Gets the whole input

    //auto start_time = std::chrono::high_resolution_clock().now();       //Record Start time
	UpperCaseString(word);		                //Makes the whole word uppercase
	pronunciation = WordPronunciation(word);	//Gets the pronunciation
	std::cout << std::endl;

	//Outputs the pronunciation
	if(CheckIfValid(word) && pronunciation != "Not found"){
        std::ifstream fin("cmudict.0.7a");
        std::string string_identical_phoneme = "";
        std::string string_add_phoneme       = "";
        std::string string_remove_phoneme    = "";
        std::string string_replace_phoneme   = "";

		while(fin){
            //ignore the commented lines
			while(dic_line[0] == ';'){getline(fin, dic_line);}
            getline(fin, dic_line);
            PhonemeChecker(word, pronunciation, dic_line, string_identical_phoneme, string_add_phoneme, string_remove_phoneme,
                                string_replace_phoneme);
        }

        std::cout << "Pronunciation:	   " << pronunciation         << std::endl << std::endl;
        std::cout << "Identical:        " << string_identical_phoneme << std::endl;
        std::cout << "Add Phoneme:      " << string_add_phoneme       << std::endl;
        std::cout << "Remove Phoneme:   " << string_remove_phoneme    << std::endl;
        std::cout << "Replace:          " << string_replace_phoneme   << std::endl;
        std::cout << std::endl;

	} else{std::cout << "Not found" << std::endl;}

    //auto end_time = std::chrono::high_resolution_clock().now();
    //std::chrono::duration<float, std::milli> runt_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
    //double runtime_sum = runt_time.count();
    //std::cout << runtime_sum << std::endl; //Prints out the time it took to run the program

}


//=========================
//FUNCTION IMPLEMENTATION
//=========================

//HELPER FUNCTION

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

void PhonemeChecker(std::string orig_word, std::string orig_pronun, std::string dic_line, std::string & identical, std::string & add_phoneme,
                    std::string & remove_phoneme, std::string & replace_phoneme){
    std::string dictionary_line;
    std::string dic_word;
    std::string pronun;

    splitOnSpace(dic_line, dic_word, pronun);
    if(CheckIfValid(dic_word) && dic_word != orig_word){
        //If Phonemes are identical, return
        if(pronun == orig_pronun){
            identical += " " + dic_word;
        } else{
            std::string before_split_orig = "";
            std::string after_split_orig = orig_pronun;
            std::string before_split_dic = "";
            std::string after_split_dic = pronun;

            do{
                splitOnSpace(after_split_orig, before_split_orig, after_split_orig);
                splitOnSpace(after_split_dic, before_split_dic, after_split_dic);
            } while(before_split_dic == before_split_orig && (after_split_orig != "" || after_split_dic != ""));

            //Checks if the Phonemes are identical
            if(after_split_dic == after_split_orig && before_split_orig != "" && before_split_dic != ""){
                replace_phoneme += " " + dic_word;
            }
            //Same Logic if Adding or Removing Phoneme
            else{
                std::string temp_split_orig;
                std::string temp_split_dic;
                std::string previous_phoneme;

                //Add Phoneme
                splitOnSpace(after_split_dic, previous_phoneme,temp_split_dic);
                if(after_split_orig == temp_split_dic && previous_phoneme == before_split_orig){
                    add_phoneme += " " + dic_word;
                }

                //Remove Phoneme
                splitOnSpace(after_split_orig, previous_phoneme,temp_split_orig);
                if(after_split_dic == temp_split_orig && previous_phoneme == before_split_dic){
                    remove_phoneme += " " + dic_word;
                }
            }
        }
    }
}
