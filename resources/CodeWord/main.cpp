#include <iostream>
#include "CodeWordGenerator.hpp"
using namespace std;

int main(){
  CodeWordGenerator test;
  cout << test.generateLengthWord("[A-Z]+ABA[A-Z]*",6) << '\n';
}