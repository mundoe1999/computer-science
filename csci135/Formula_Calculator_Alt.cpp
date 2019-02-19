/*
Name: Esteban Mundo
Class: CSCI 135
Task D: Calculating Multiple Formulas, with exponents

Calculates the value of the formulas, also includes exponents
*/
#include <iostream>



int main(){
  int number;
  int sum = 0;
  char op;
  bool isAdding;

  //Gets First Number
  std::cin >> number;
  sum = number;
  isAdding = true;


	while(std::cin >>  op) {
    //Reverse the 
    if('^' == op){
      if(isAdding){sum = sum - number + number*number;}
      else{sum = sum + number - number*number;}
    }
    else{
      std::cin >> number;

      if('+' == op){
        sum += number;
        isAdding = true;
      }
      else if('-' == op){
        sum -= number;
        isAdding = false;
      }
      else{
        std::cout << sum << std::endl;
        sum = number;
        isAdding = true;
      }
    }
	}

	return 0;
}
