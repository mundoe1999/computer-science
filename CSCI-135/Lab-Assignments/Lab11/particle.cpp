/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: April 25, 2018
Modified on: December 11, 2020
Assignment: Lab 11F
Purpose: 
	Dynamically creating particle objects and necessary methods
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

//Structure for particles
struct Particle{
	Coord3D position;
	Coord3D velocity;
};

// get its current position
Coord3D getPosition(Particle *p){
	return (*p).position;
}


//================================
// Functions Relating to Particle
//================================

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
	Particle *p = new Particle;
	
	//Setting Positions
	p -> position.x = x;
	p -> position.y = y;
	p -> position.z = z;
	
	//Setting Velocities
	p -> velocity.x = vx;
	p -> velocity.y = vy;
	p -> velocity.z = vz;
	
	return p;
}


// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
	//Setting Velocities
	p -> velocity.x = vx;
	p -> velocity.y = vy;
	p -> velocity.z = vz;	

}

// update particle's position after elapsed time dt
void move(Particle *p, double dt){

	double Xprime = ((*p).position).x + ((*p).velocity).x * dt; 
	double Yprime = ((*p).position).y + ((*p).velocity).y * dt; 
	double Zprime = ((*p).position).z + ((*p).velocity).z * dt; 
	//Returns the primes of the following values
	((*p).position).x = Xprime;
	((*p).position).y = Yprime;
	((*p).position).z = Zprime;	
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
	delete p;
}

//===============================
// Testing Region
//===============================

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}

