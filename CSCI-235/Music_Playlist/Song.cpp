/*
Name: Esteban Mundo
Date: September 19, 2018
Course: CSCI 235 - Software Analysis and Design 2

This is the implementation file for the "Song" class
*/

#include "Song.hpp"

//Default Initializer
Song::Song(){}

//paramaterized initializer
Song::Song(const std::string& title, const std::string& author, const std::string& album){
	title_ = title;
	author_ = author;
	album_ = album;
}


void Song::setTitle(std::string title){
	title_ = title;
}

void Song::setAuthor(std::string author){
	author_ = author;
}

void Song::setAlbum(std::string album){
	album_ = album;
}


std::string Song::getTitle() const{
	return title_;
}

std::string Song::getAuthor() const{
	return author_;
}

std::string Song::getAlbum() const{
	return album_;
}


//Overriding parameter
bool operator==(const Song& lhs, const Song& rhs){
	if(lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ && lhs.album_ == rhs.album_){
	   return true;
	}
	return false;
}
