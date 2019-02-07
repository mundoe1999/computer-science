/*
Name: Esteban Mundo
Class: CSCI 135
Task D: Calculating Multiple Formulas, with exponents

Calculates the sum of multiple formulas of a .txt file, with
added implementation to take into account Exponents.
*/

#include <iostream>
using namespace std;

int main(){
	//Reading the .txt File
	char s;

	int sum = 0;			//Used to calculate the total Sum
	int num = 0;			//Used to store the numbers
	char operation = '0';		//Checks the the operator, if it's (+) or (-)

	while(cin >>  s) {
		//Checks if the character is a valid operator (excluding exponent)
		//If not, the base value is multiplied by 10 (Since this is a Decimal-based system)
		//((s-48)%10) calculates the appropiate decimal value and adds to num
		if(s != '+' && s != '-' && s != ';'){
			if(s == '^'){num = num*num;}
			else{num = num*10 + ((s - 48)%10);}
		}

		//Sees whether the operator is (+) or (-)
		else if(s == ';'){
			if(sum == 0 && operation == '0'){
				sum += num;
			}
			else if(operation == '+'){
				sum += num;
			}
			else if(operation == '-'){
				sum -= num;
			}
			
			cout << sum << endl;
			num = 0;
			sum = 0;
			operation = '0';
		}

		else{
			if(sum == 0 && operation == '0'){
				sum += num;
			}
			else if(operation == '+'){
				sum += num;
			}
			else if(operation == '-'){
				sum -= num;
			}
			
			//Num is reset, and sets operation with new operator
			operation = s;
			num = 0;
		}
	}
	return 0;
}
