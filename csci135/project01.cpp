/*
Name: Esteban Mundo
Class: CSCI 135
Task D: Calculating Multiple Formulas, with exponents

Calculates the value of the formulas, also includes exponents
*/
#include <iostream>

using namespace std;


int main(){
	//Reading the .txt File
	char s;

	int sum = 0;			//Used to calculate the total Sum
	int Value = 0;			//Used to store the numbers
	char operation = '0';	//Checks the the operator, if it's (+) or (-)
	char exponent = '0';

	while(cin >>  s) {

		//What this does is that it checks if it is an operator
		//If not, the base value is multiplied by 10 (since we are reading left to right)
		//((s-48)%11) calculates whether the char is either 0-9, and adds it into the Value
		if(s != '+' && s != '-' && s != ';'){
			if(s == '^'){
				Value = Value*Value;
			}
			else{
				Value = Value*10 + ((s - 48)%11);
			}

		}

		//Sees whether the operator is (+) or (-)
		else if(s == ';'){
			if(sum == 0 && operation == '0'){
				sum+=Value;
			}
			else if(operation == '+'){
				sum+= Value;
			}
			else if(operation == '-'){
				sum-= Value;
			}

			cout << sum << endl;
			Value = 0;
			sum = 0;
			operation = '0';
		}

		else{

			if(sum == 0 && operation == '0'){
				sum+=Value;
			}
			else if(operation == '+'){
				sum+= Value;
			}
			else if(operation == '-'){
				sum-= Value;
			}

			operation = s;
			
			//Reset the String to store the next sum of numbers
			Value= 0;
		}
	}

	return 0;
}
