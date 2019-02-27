/*
Name: Esteban Mundo
Date: September 19, 2018
Course: CSCI 235 - Software Analysis and Design 2

This is the implementation file for the "PlayList" class
*/


#include "PlayList.hpp"


PlayList::PlayList(){}

//All functions call back to functions described in Set.h
//Look at the implementation for better understanding how
//these functions work

PlayList::PlayList(const Song& a_song){

	playlist_.add(a_song);
}

int PlayList::getNumberOfSongs() const{
	return playlist_.getCurrentSize();
}

bool PlayList::isEmpty() const{
	return playlist_.isEmpty();
}

bool PlayList::addSong(const Song& new_song){
	return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song& a_song){
	return playlist_.remove(a_song);
}

void PlayList::clearPlayList(){
	playlist_.clear();
}

void PlayList::displayPlayList(){
	std::vector<Song> current_playlist = playlist_.toVector();
	for(int i = 0; i < playlist_.getCurrentSize(); i++){
		//Very awkward formatting, but needed to do in the style required
		std::cout << "* Title: " << current_playlist[i].getTitle() << " ";
		std::cout << "* Author: " << current_playlist[i].getAuthor() << " ";
		std::cout << "* Album: " << current_playlist[i].getAlbum() << " *" << std::endl;
	}
	//To ensure this is end of playlist
	std::cout << "End of playlist" << std::endl;
}
