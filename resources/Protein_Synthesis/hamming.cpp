/******************************************************************************
Author: Esteban Mundo
Created on: March 30, 2019
Modified on: March 30, 2019

Purpose:
   This is the second project of CSci 135 for Spring 2019.
   For this part, we detect the differences between two strands, and then check
   1) Total number of differences
   2) See if those changes altered the actual protein

******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

char DNAbase_to_mRNAbase(char c);
string DNA_to_mRNA(string strand);
string dictionary_read(ifstream &dict, string mRNA);
string aminoGroup(ifstream &dict, string mRNA_strand);
int Hamming(string strand_01, string strand_02);

int main(){

  string input_file;

  cout << "Enter input file name: ";
  cin >> input_file;

  ifstream fin(input_file);
  ifstream dict("codons.tsv");
  //In case file is unable to be opened
  if(fin.fail()){
    cerr << "File cannot be read, opened, or does not exist.\n";
    exit(1);
  }

  //read the entire strance
  string strand_01;
  string strand_02;
  while(getline(fin, strand_01)) {
    //Get second line
    getline(fin, strand_02);

    //Convert to mRNA
    strand_01 = DNA_to_mRNA(strand_01);
    strand_02 = DNA_to_mRNA(strand_02);

    cout << Hamming(strand_01, strand_02) << " ";

    //Convert to amino
    strand_01 = aminoGroup(dict, strand_01);
    strand_02 = aminoGroup(dict, strand_02);

    if(strand_01 != strand_02){
      cout << "yes" << endl;
    } else{
      cout << "no" << endl;
    }

  }

  fin.close();
  return 0;
}

char DNAbase_to_mRNAbase(char c){
  //Convert to uppercase
  c = toupper(c);

  if(c == 'A') return 'U';
  if(c == 'T') return 'A';
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

string dictionary_read(ifstream &dict, string mRNA) {
    string key, value;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while (dict >> key >> value) {
      if(key == mRNA){
        return value;
      }
    }
    return "ERROR";
}

string aminoGroup(ifstream &dict, string mRNA_strand){
  bool isCopying = false;
  string protein;
  string amino = "";

  for(int i = 0; i < mRNA_strand.length(); i+=3){
    protein = mRNA_strand.substr(i, 3);

    protein = dictionary_read(dict, protein);

    //Start Copying
    if(protein == "Met"){
      isCopying = true;
      amino += "Met";
    }
    //Stop Copying
    if(protein == "Stop"){
      return amino;
    }
    //Writing into String
    if(isCopying && protein != "Met"){
      amino += '-' + protein;
    }
  } //End for loop
  return amino;
}

int Hamming(string strand_01, string strand_02){
  int counter = 0;
  //Assume both strands are of same length
  for(int i = 0; i < strand_01.length(); i++){
    if(strand_01[i] != strand_02[i]){
      counter++;
    }
  }
  return counter;
}
