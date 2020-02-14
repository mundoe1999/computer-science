#include "CodeWordGenerator.hpp"

std::string CodeWordGenerator::generateShortestWord(std::string pattern){
  std::regex regex_pattern(pattern);
  std::queue<std::string> words;
  std::string current_word, new_word;

  // Push empty String First
  words.push("");

  //  Will try to generate a word indefinately
  while(!words.empty()){
    current_word = words.front();
    words.pop();

    if(std::regex_match(current_word, regex_pattern))
      return current_word;
    
    for(int i = 'A'; i <= 'Z'; i++){
      new_word = current_word + char(i);
      words.push(new_word);
    }
  } // End while

  return "";
}

std::string CodeWordGenerator::generateLengthWord(std::string pattern, int length){
  std::regex regex_pattern(pattern);
  std::stack<std::string> words;
  std::string current_word, new_word;

  // Push Empty String First
  words.push("");

  // WIll stop when the length of words exceeds length
  while(!words.empty()){
    current_word = words.top();
    words.pop();

    if(std::regex_match(current_word, regex_pattern) && current_word.length() == length)
      return current_word;
      
    else if(current_word.length() < length){
      for(int i = 'A'; i <= 'Z'; i++){
        new_word = current_word + char(i);
        words.push(new_word);
      }
    } // End else if
  } // End while

  return "";
}