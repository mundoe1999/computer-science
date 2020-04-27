/******************************************************************************
File Name: CodeWordGenerator.hpp
Author: Esteban Mundo
Uploaded on: February 14, 2020
Purpose:
  Header File for CodeWordGenerator Class
******************************************************************************/


#ifndef CodeWordGenerator_HPP_
#define CodeWordGenerator_HPP_

#include <regex>
#include <queue>
#include <stack>
#include <string>

class CodeWordGenerator {
public:
  std::string generateShortestWord(std::string pattern);
  std::string generateLengthWord(std::string pattern, int length);

};

#endif