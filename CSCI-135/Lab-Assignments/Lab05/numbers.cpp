/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 27, 2018
Modified on: December 08, 2020
Assignment: Lab 5A-E
Purpose: 
	This is an assortment of tasks ranging that culminate in assessing 
	prime numbers and calculating the next available prime number.
******************************************************************************/

#include <iostream>
using namespace std;

// Function for checking divisibility between two values (Lab 5A)
bool isDivisibleBy(int n, int d){
	// Checks if denominator is 0, as dividing by 0 is unoperable.
	if(d != 0){
		if(n % d == 0){
			return true;
		}
		else{
			return false;
		}
	}
	return false;

}

// Checks if a value is a prime number (Lab 5B)
bool isPrime(int n){

	//0 or 1 cannot be prime numbers, and neither can negative values
	if(n < 2){
		return false;
	}

	// Check if n is divisible from 2 ... n-1
	for(int i = 2; i < n; i++){
		if(isDivisibleBy(n,i)){
			return false;
		}
	}
	return true;
}

// Calculates next Prime Number from given value (Lab 5C)
int nextPrime(int n){
	// Continue until next prime number is found
	while(isPrime(n+1)){
		n++;
	}
	return (n+1);
}

// Counts the prime numbers within a range of numbers (Lab 5D)
int countPrimes(int a, int b){
	int counter = 0;
	
	//This checks the numbers between a <= i <= b
	for(int i = a; i <= b; i++){
		if(isPrime(i)){
			counter++;
		}
	}
	//Returns the counter value
	return counter;
}

// Checks if the number is a twin prime number (Lab 5E)
bool isTwinPrime(int n){

	//checks if the initial value is a prime number
	if(isPrime(n)){
		//checks if either adjacent value is prime
		if(isPrime(n+2) || isPrime(n-2)){
			return true;
		}
	}
	
	return false;
}

//Checks for the next twin number (Lab 5F)
int nextTwinPrime(int n){
	//adding 1 to not include n.
	n++;
	
	//!isTwinPrime(n) what it does is return true if n is NOT a twin prime number
	while(!isTwinPrime(n)){
		n++;
	}
	
	return n;
	
}

//Checks for the largest twin prime number within the range (Lab 5G)
int largestTwinPrime(int a, int b){
	int twinPrime = -1;
	
	// Start at largest value to reduce computation needed
	for(int i = b; i >= a; i--){
		if(isTwinPrime(i)){
			return i;
		}
	}
	return -1;
}


// Main Testing function
int main(){
	//defining the variables
	int numberA, numberB;

	cout << "Enter a number: ";
	cin >> numberA;
	
	cout << "Enter another number: ";
	cin >> numberB;
	

		
	//checks if it is a twin prime number
	cout << "The largest prime number in here is " << largestTwinPrime(numberA,numberB) << endl;
	return 0;

}
