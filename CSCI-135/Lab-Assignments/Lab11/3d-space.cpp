/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: April 25, 2018
Modified on: December 11, 2020
Assignment: Lab 11A-E
Purpose: 
	Creating a 3D structure and dynamically manipulating it.
******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

//Structure for coordinate
struct Coord3D {
	double x;
	double y;
	double z;
};

double length(Coord3D *p){
	//Getting The distance
	double x = (*p).x;
	double y = (*p).y;
	double z = (*p).z;
	
	//Calculating the length
	double l = sqrt((x*x) + (y*y) + (z*z));
	
	return l;

}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
	double LengthP1 = length(p1);
	double LengthP2 = length(p2);

	//If they are further from the origin, then they length is farther away
	if(LengthP1 > LengthP2){
		return p1;
	} else{
		return p2;
	}

}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
	double Xprime = (*ppos).x + (*pvel).x * dt; 
	double Yprime = (*ppos).y + (*pvel).y * dt; 
	double Zprime = (*ppos).z + (*pvel).z * dt; 
	
	//Returns the primes of the following values
	(*ppos).x = Xprime;
	(*ppos).y = Yprime;
	(*ppos).z = Zprime;
	 
}


Coord3D * createCoord3D(double x, double y, double z){
	//Creates a coord and store the values that we have allocates
	 Coord3D *p = new Coord3D;
	 (*p).x = x;
	 (*p).y = y;
	 (*p).z = z;
	 
	return p;

}

void deleteCoord3D(Coord3D *p){
	delete p;
}


int main(){
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);

}
