/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: May 3, 2018
Modified on: December 11, 2020
Assignment: Lab 12A-F
Purpose: 
	Various recursion Questions
******************************************************************************/

#include <iostream>
using namespace std;

//Task A

//Prints the range of values
void printRange(int left, int right){
	if(left <= right){
		cout << left << " ";
		printRange(left+1, right);
	}

}

//Task B

//Adds the sum of a range
int sumRange(int left, int right){
	if(left > right){
		return 0;
	} else{
		return (left + sumRange(left + 1, right));
	}
}

//Task C

//Helper function for adding within an array
int sumArrayInRange(int *arr, int left, int right){
	if(left > right){
		return 0;
	} else{
		return arr[left] + sumArrayInRange(arr, left+1, right);
	}

}

//summing an array
int sumArray(int *arr, int size){
	return sumArrayInRange(arr, 0, size-1);
}

//Task D

//Checking if the string is alphanumeric
bool isAlphanumeric(string s){
	if(s == ""){
		return true;
	}else{
		//Checks between A-Z or a-z
		if((s[0] >= 65 && s[0] <= 90) || (s[0] >= 97 && s[0] <= 122) || (s[0] >= 48 && s[0] <= 57)){
			return isAlphanumeric(s.substr(1, s.length()-1));
		}else{
			return false;
		}
	}
}

//Task E
bool nestedParens(string s){
	if(s == ""){
		return true;
	} else if(s[0] == 40 && s[s.length() - 1] == 41){
		//Removes the first and last characters
		return nestedParens(s.substr(1,s.length()-2));
	} else{
		return false;
	}
}

//Task F
bool Solvable(int *prices, int pos, int size, int left, int right){
	if(pos != size){
	//Checks for left and right until there is at least one that is true
		if(Solvable(prices, pos+1, size, left - prices[pos], right) || Solvable(prices, pos+1, size, left, right - prices[pos])){
			return true;
		}
	return false;
		
	
	} else if(left == 0 && right == 0){
		return true;
	} else{
		return false;
	}
}

//Main function
bool divisible(int *prices, int size){
	if(sumArray(prices, size) % 2 == 1){
		return false;
	}
	else{
		return Solvable(prices, 0, size, sumArray(prices, size)/2,  sumArray(prices, size)/2);
	}

}
//This is where the testing occurs
int main(){

	return 0;

}
