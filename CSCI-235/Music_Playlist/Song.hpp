/*
Name: Esteban Mundo
Date: September 19, 2018
Course: CSCI 235 - Software Analysis and Design 2

This is the header file for the "Song" class
*/

#ifndef SONG_HPP_
#define SONG_HPP_
#include <string>

class Song{
	public:
		//Constructor Functions
		Song();
		Song(const std::string& title, const std::string& author = "", const std::string& album = "");


		//Functions for setting a value for the Private Variables
		void setTitle(std::string title);
		void setAuthor(std::string author);
		void setAlbum(std::string album);

		//Functions for getting Private Variables
		std::string getTitle() const;
		std::string getAuthor() const;
		std::string getAlbum() const;

		// == Operator to check if two Song types are the same
		friend bool operator==(const Song& lhs, const Song& rhs);

	private:
		std::string title_;
		std::string author_;
		std::string album_;

};

#endif //song.hpp
