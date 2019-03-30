/******************************************************************************
Author: Esteban Mundo
Created on: March 29, 2019
Modified on: March 30, 2019

Purpose:
   This is the second project of CSci 135 for Spring 2019. The programs reads
   in a file that contains only DNA, and converts the DNA to mRNA

******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

char DNAbase_to_mRNAbase(char c);
string DNA_to_mRNA(string strand);

int main(){

  string input_file;

  cout << "Enter input file name: ";
  cin >> input_file;

  ifstream fin(input_file);

  //In case file is unable to be opened
  if(fin.fail()){
    cerr << "File cannot be read, opened, or does not exist.\n";
    exit(1);
  }

  //read the entire strance
  string strand;
  while(getline(fin, strand)) {
      strand = DNA_to_mRNA(strand);
      cout << strand << endl;
  }

  fin.close();
  return 0;
}

char DNAbase_to_mRNAbase(char c){
  //Convert to uppercase
  c = toupper(c);

  if(c == 'A') return 'U';
  if(c == 'T') return 'T';
  if(c == 'C') return 'G';
  if(c == 'G') return 'C';
  //For case if not part of DNA
  return c;

}
string DNA_to_mRNA(string strand){
  for(int i = 0; i < strand.length(); i++){
    strand[i] = DNAbase_to_mRNAbase(strand[i]);
  }
  return strand;
}
