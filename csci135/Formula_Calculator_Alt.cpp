/*
Name: Esteban Mundo
Task D: Calculating Multiple Formulas, with exponents
This program is able to take in formulas from a plain text file
and then print out the result of those formulas.

For Example:
10 + 7 - 2^;
10^;
//End of line
//This will print out:
13
100

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
	    std::cin >> number; //Get Next Number
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
    } //End While
    return 0;
}
