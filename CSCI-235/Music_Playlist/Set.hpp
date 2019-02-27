/*
Name: Esteban Mundo
Date: September 19, 2018
Course: CSCI 235 - Software Analysis and Design 2

This is the header file for the set class. Originally,
there was a setInterface.hpp but that file is lost, or missing.
However, the implementation for this program is still functional.
*/

#ifndef SET_HPP_
#define SET_HPP_
#include <vector>

template<class ItemType>
class Set {
	private:
		static const int DEFAULT_SET_SIZE = 4;
		ItemType items_[DEFAULT_SET_SIZE];
		int item_count_;
		int max_items_;
		int getIndexOf(const ItemType& target) const;

	public:

		Set();	//Somehow needed for to Set work properly

		/** Gets the current number of entries in this set.
    	 @return The integer number of entries currently in the set. */
		int getCurrentSize() const;

	   /** Checks whether this set is empty.
		@return True if the set is empty, or false if not. */
		bool isEmpty() const;

	   /** Adds a new entry to this set.
		@post  If successful, newEntry is stored in the set and
		   the count of items in the set has increased by 1.
		@param newEntry  The object to be added as a new entry.
		@return  True if addition was successful, or false if not. */
		bool add(const ItemType& newEntry);

	   /** Removes a given entry from this set,if possible.
		@post  If successful, anEntry has been removed from the set
		   and the count of items in the set has decreased by 1.
		@param anEntry  The entry to be removed.
		@return  True if removal was successful, or false if not. */
		bool remove(const ItemType& anEntry);

	   /** Removes all entries from this set.
		@post  set contains no items, and the count of items is 0. */
		void clear();

	   /** Tests whether this set contains a given entry.
		@param anEntry  The entry to locate.
		@return  True if set contains anEntry, or false otherwise. */
		bool contains(const ItemType& anEntry) const;

	   /** Fills a vector with all entries that are in this set.
		@return  A vector containing all the entries in the set. */
		std::vector<ItemType> toVector() const;

};

#include "Set.cpp"
#endif //SET_H_
