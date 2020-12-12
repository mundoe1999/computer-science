/******************************************************************************
Author: Esteban Mundo
Course: CSci 136
Uploaded on: April 11, 2018
Modified on: December 11, 2020
Assignment: Lab 13A-D
Purpose: 
	Creates a pseudo social media network using classes
******************************************************************************/


#include <iostream>
using namespace std;

class Profile {
private:
	string username;
	string displayname;

public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)    
    Profile(string usrn, string dspn);
    
    // Default Profile constructor (username="", displayname="")
    Profile();
    
    // Return username
    string getUsername();
    
    // Return name in the format: "displayname (@username)"
    string getFullName();
    
    // Change display name
    void setDisplayName(string dspn);
    
    //Change username
    void setUserName(string usrn);

};

struct Post{
    string username;
    string message;
};

class Network {
private:
	static const int MAX_USERS = 20;
	int numUsers;
	Profile profiles[MAX_USERS];
	
	//returns user ID
	//returns -1 if no username was found
	int findID(string usrn);
	
	bool following[MAX_USERS][MAX_USERS];
	
    static const int MAX_POSTS = 100;         // new
    int numPosts;                             // new
    Post posts[MAX_POSTS];                    // new
	
public:
	Network();
	
	bool addUser(string usrn, string dspn);
	
	//Follow a person
	bool follow(string usrn1, string usrn2);
	
	//Print Dot file
	void printDot();
	
	bool writePost(string usrn, string msg);  // new
    bool printTimeline(string usrn);          // new
};

//This is where the testing occurs
int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}



//====================================
//Implementation of the Class Profile
//====================================

//Profile constructor for a user
Profile::Profile(string usrn, string dspn){
	username = usrn;
	displayname = dspn;
}

//Default constructor
Profile::Profile(){
	username = "";
	displayname = "";
}

//Returns Username
string Profile::getUsername(){
	return username;
}

//Returns Full name
string Profile::getFullName(){
	return (displayname + " (@" + username + ")");
}

//Change display name
void Profile::setDisplayName(string dspn){
	displayname = dspn;
}

void Profile::setUserName(string usrn){
	username = usrn;
}

//====================================
//Implementation of the Class Network
//====================================

//Private Functions

//Searches for user id
int Network::findID(string usrn){
	for(int i = 0; i < MAX_USERS; i++){
		if(profiles[i].getUsername() == usrn){
			return i;
		}
	}
	
	return -1;	
}

//Public functions

//Default Constructor
Network::Network(){
	numUsers = 0;
	numPosts = 0;
	for(int i = 0; i < MAX_USERS; i++){
		for(int j = 0; j < MAX_USERS; j++){
			following[i][j] = false;
		}
	}
}

//Adds a username
bool Network::addUser(string usrn, string dpsn){
	//Check if Non-Empty
	if(usrn == ""){
		return false;
	}
	//Checks if alphanumeric
	for(int i = 0; i < usrn.length(); i++){
		if(!((usrn[i] >= 'A' && usrn[i] <= 'Z') || (usrn[i] >= 'a' && usrn[i] <= 'z') || (usrn[i] >= '0' && usrn[i] <= '9'))){
			return false;
		}
	}
	//Checks if username is not found
	//AND the num users is less than Max users
	if(findID(usrn) == -1 && numUsers < MAX_USERS){
		Profile prfl(usrn, dpsn);
		profiles[numUsers] = prfl;
		numUsers++;
		return true; 
	
	} else{
		return false;
	}
}

bool Network::follow(string usrn1, string usrn2){
	int UserID01 = findID(usrn1);
	int UserID02 = findID(usrn2);
	 
	if(UserID01 != -1 || UserID02 != -1){
		following[UserID01][UserID02] = true;
		return true;
	
	} else{
		return false;
	}
}

void Network::printDot(){
	cout << "digraph {" << endl;
	
	for(int i = 0; i < numUsers; i++){
		cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
	}

	for(int i = 0; i < MAX_USERS; i++){
		for(int j = 0; j < MAX_USERS; j++){
			if(following[i][j] == true){
				cout << "  \"@" << profiles[i].getUsername() << "\"";
				cout << " -> ";
				cout << "\"@" << profiles[j].getUsername() << "\"" << endl;
			}
		}
	}

	cout << "}";
}

bool Network::writePost(string usrn, string msg){
	if(numPosts < MAX_POSTS){
		posts[numPosts].username = usrn;
		posts[numPosts].message = msg;
		numPosts++;
		return true;
	}
	return false;
}

bool Network::printTimeline(string usrn){
	for(int i = (numPosts-1); i >= 0; i--){
		string UserPost = profiles[findID((posts[i].username))].getFullName();
		if(following[findID(usrn)][findID((posts[i].username))] || usrn == posts[i].username){
			cout << UserPost << ":" << posts[i].message << endl;
		}
	}

	return false;
}

