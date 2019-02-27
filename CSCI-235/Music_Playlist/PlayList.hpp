/*
Name: Esteban Mundo
Date: September 19, 2018
Course: CSCI 235 - Software Analysis and Design 2

This is the header file for the "PlayList" class
*/

#ifndef PLAYLIST_HPP_
#define PLAYLIST_HPP_


#include "Song.hpp"
#include "Set.hpp"
#include <iostream>
class PlayList{
	public:

		//Default Constructor
		PlayList();

		//Parametized Constructor
		PlayList(const Song& a_song);

		/**
		 @return the number of Song(s) in Playlist*/
		int getNumberOfSongs() const;

		/**
		 @return TRUE if PlayList is empty*/
		bool isEmpty() const;

		/**
		 @Post If successful, adds Song into the Playlist
		 @Param new_song	the Song that to add into the Playlist
		 @return TRUE if song is successfully added*/
		bool addSong(const Song& new_song);

		/**
		 @Post If successful, removes song from Playlist
		 @param a_song	The Song that is to be removed
		 @return TRUE if song is successfully removed*/
		bool removeSong(const Song& a_song);

		/**
		 @Post Clears current playlist */
		void clearPlayList();
		/**
		 @Post Lists all the songs in playlist*/
		void displayPlayList();

	private:
		Set<Song> playlist_;


};

#endif //Playlist.hpp
