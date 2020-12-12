/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: April 11, 2018
Modified on: December 11, 2020
Assignment: Lab 9G (BONUS)
Purpose: 
	Filters the image by detecting horizontal edges and changing the color
******************************************************************************/



#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}




int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];
	int Pnum = 0;
	int lowerEdge;
	int upperEdge;
	
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			//8 base cases
			//123
			//4*5	
			//678
			
			//case 1 
			if(col == 0 && row == 0){
				Pnum = 2*img[row+1][col]+img[row+1][col+1];
			}
			//case 3
			else if(col == w-1 && row == 0){	
				Pnum = 2*img[row+1][col-1]+img[row+1][col];
			}
			//case 6
			else if(col == 0 && row == h-1){	
				Pnum = (2*img[row-1][col]+img[row-1][col+1]) * (-1);
			}						
			//case 8
			else if(col == w-1 && row == h-1){	
				Pnum = (2*img[row-1][col-1]+img[row-1][col]) * (-1);
			}		
			//case 2
			else if(row == 0){
				Pnum = img[row+1][col-1]+2*img[row+1][col]+img[row+1][col+1];
			}
			//case 4
			else if(col == 0){
				lowerEdge = 2*img[row+1][col] + img[row+1][col+1];
				upperEdge = 2*img[row-1][col] + img[row-1][col+1];
				Pnum = lowerEdge - upperEdge;
			}
			//case 6
			else if(col == w-1){
				lowerEdge = 2*img[row+1][col] + img[row+1][col-1];
				upperEdge = 2*img[row-1][col] + img[row-1][col-1];
				Pnum = lowerEdge - upperEdge;
			}
			//case 8
			else if(row == h-1){
				Pnum = (-1)*(img[row+1][col-1]+2*img[row+1][col]+img[row+1][col+1]);
			}
			//All other cases
			else{
				lowerEdge = (img[row+1][col-1]+2*img[row+1][col]+img[row+1][col+1]);
				upperEdge = (img[row-1][col-1]+2*img[row-1][col]+img[row-1][col+1]);
				Pnum = lowerEdge - upperEdge;			
			}
			//Applying this formula to the outimage
			if(Pnum <= 0){
				out[row][col] = 0;
			}
			else if( Pnum >= 255){
				out[row][col] = 255;
			}
			else{
				out[row][col] = Pnum;
			}	
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}

