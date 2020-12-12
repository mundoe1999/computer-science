/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: April 11, 2018
Modified on: December 11, 2020
Assignment: Lab 10A-E
Purpose: 
	To practice structures by creating structs involving movies.
******************************************************************************/

#include <iostream>
using namespace std;

enum Genre{ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};


struct Time{
	int h;
	int m;
};

struct Movie{
	string title;
	Genre genre;
	int duration;
};

struct TimeSlot {
	Movie movie;
	Time startTime;
};

//Returns the time that has passed since Midnight
int minutesSinceMidnight(Time time);

//Returns the minutes needed until the second time specified
int minutesUntil(Time earlier, Time later);

//Adds minutes to a certain time
Time addMinutes(Time time0, int min);

//Prints out the movie details
void printMovie(Movie mv);

//Prints out all the details regarding the movie
void printTimeSlot(TimeSlot ts);

//Gives you the timeslot of the next film
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

//Checks if two timeslots overlap
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);

//-----------------------------------------------------------------------------
// Function Implementation
//-----------------------------------------------------------------------------

// Prints time of struct
void printTime(Time t){
	cout << t.h << ":" << t.m;
}


// Give you time until midnight
int minutesSinceMidnight(Time time){
	int minutes = 0;
	minutes = time.h*60+time.m;
	
	return minutes;
}

// Gives the difference between two times
int minutesUntil(Time earlier, Time later){
	int minutes;
	int earlierTime = minutesSinceMidnight(earlier);
	int laterTime = minutesSinceMidnight(later);
	
	minutes = laterTime - earlierTime;
	return minutes;

}

Time addMinutes(Time time0, int min){
	//Setting up variables
	int NewHour;
	int NewMin;	
	NewHour = time0.h;
	NewMin = time0.m + min;
	
	//Because 60 minutes = 1 hour, we want minutes to be between 0 - 59
	while(NewMin >= 60){
		NewHour++;
		NewMin -= 60;
	}
	
	//To make sure if it goes to another day, it will go back to 0
	NewHour = NewHour % 24;
	
	time0 = {NewHour, NewMin};
	return time0;

}

void printMovie(Movie mv){
	string g;
	
	switch (mv.genre){
		case ACTION		: g = "ACTION"; break;
		case COMEDY		: g = "COMEDY"; break;
		case DRAMA		: g = "DRAMA"; 	break;
		case ROMANCE	: g = "ROMANCE"; break;
		case THRILLER	: g = "THRILLER"; break;
	
	}
	cout << mv.title << " " << g << " (" << mv.duration << " min)";

}

void printTimeSlot(TimeSlot ts){

	//Used to define the endtime
	Time endTime;
	endTime = addMinutes(ts.startTime, ts.movie.duration);
	
	//Prints out the entire line
	printMovie(ts.movie);		//Film, genre and duration
	cout << " [starts at "; 
	printTime(ts.startTime);	//Prints the film's start time
	cout << ", ends by ";
	printTime(endTime);			//Prints out the end tim
	cout << "]" << endl;
	
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
	
	//Sets the start time of the next film
	Time nextTime;
	nextTime = addMinutes(ts.startTime, ts.movie.duration);
	ts.startTime = nextTime;
	
	//Replace with the next movie film
	ts.movie = nextMovie;
	
	return ts;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
	//S = Start
	//E = End

	//Movie A
	int AS = minutesSinceMidnight(ts1.startTime);
	int AE = minutesSinceMidnight(addMinutes(ts1.startTime,ts1.movie.duration));
	
	//Movie B
	int BS = minutesSinceMidnight(ts2.startTime);
	int BE = minutesSinceMidnight(addMinutes(ts2.startTime,ts2.movie.duration));
	
	//If one film starts within the length of another film
	 if((AS >= BS && AS <= BE) || (BS >= AS && BS <= AE)){
	 	return true;	
	}
	//If one film is before the other film but ends sometime after the beginning of the other 
	else if((AS < BS && AE > BS) || (BS < AS && BE > AS)){
		return true;
	}
	return false;	

}

int main(){
	
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
	Movie movie3 = {"Persepolis", COMEDY, 96};
	Movie movie4 = {"CSCI 135 Final", DRAMA, 108};

	TimeSlot morning = {movie1, {9, 15}};
	TimeSlot daytime = {movie2, {12, 15}};
	TimeSlot evening = {movie2, {16, 45}};
	TimeSlot afternoon = {movie3, {14,30}};
	TimeSlot night = {movie4, {18, 0}};

	

	 bool doesit =timeOverlap({{"The Wolf of Wall Street", COMEDY, 180}, {10, 30}}, {{"5 Centimeters Per Second", DRAMA, 63}, {12, 50}});
	 
	 cout << doesit << endl;
	 
	/*
	//LAB10A AND 10B
	Time firstTime;
	Time secondTime;
	
	cout << "Enter the first time:   ";
	cin >> firstTime.h >> firstTime.m;
	
	cout << "Enter the second time:  ";
	cin >> secondTime.h >> secondTime.m;
	

	//Tests the output
	cout << minutesSinceMidnight(firstTime) << endl;
	cout << minutesSinceMidnight(secondTime) << endl;
	cout << minutesUntil(firstTime,secondTime) << endl;
	cout << addMinutes(firstTime,75).h << " " << addMinutes(firstTime,75).m << endl;
	*/
	return 0;

}
