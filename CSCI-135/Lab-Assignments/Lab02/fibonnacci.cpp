/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: February 5, 2018
Modified on: February 14, 2020
Assignment: Lab 2D
Purpose:
   Simple program that lists the first 60 entries of the fibonacci sequence
******************************************************************************/

#include <iostream>

int main(){
  int fib[60];

  // Setting the first two fibonacci terms
  fib[0] = 0;
  fib[1] = 1;

  // Populate the rest of elements in array
  for(int i = 2; i < 60; i++)
    fib[i] = fib[i-1] + fib[i-2];
  
  // Prints all values
  for(int i = 0; i < 60; i++)
    std::cout << fib[i] << '\n';
  
  return 0;
}