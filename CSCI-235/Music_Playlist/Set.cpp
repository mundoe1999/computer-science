/*
Name: Esteban Mundo
Date: September 19, 2018
Course: CSCI 235 - Software Analysis and Design 2

This is the implementation file for the "Set" class template
*/
#include "Set.hpp"

//Initializer
template<class ItemType>
Set<ItemType>::Set(): item_count_(0), max_items_(DEFAULT_SET_SIZE){}

template<class ItemType>
int Set<ItemType>::getCurrentSize() const{
	return item_count_;
}

template<class ItemType>
bool Set<ItemType>::isEmpty() const{
	return item_count_ == 0;
}

template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry){
	bool can_add_room = (item_count_ < max_items_);

	if(can_add_room && ! Set<ItemType>::contains(newEntry)){
		items_[item_count_] = newEntry;
		item_count_++;
		return 1;
	}
return 0;

}

//Replaces the removed entry with the last entry

template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry){
	for(int i = 0; i < item_count_; i++){
		if(items_[i] == anEntry){
			items_[i] = items_[item_count_-1];
			item_count_--;
			return 1;
		}
	}
	return 0;
}

//Note: Does not DELETE
//Rather, gives it permission to overwrite current songs
template<class ItemType>
void Set<ItemType>::clear(){
	item_count_ = 0;
}

template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const{
	for(int i = 0; i < item_count_; i++){
		if(anEntry == items_[i]){
			return 1;
		}
	}
	return 0;
}

//Convers the Set array into a vector
//USEFUL FOR READING THE CONTENTS OF THE ARRAY
template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const{
	std::vector<ItemType> new_vector;
	for(int i = 0; i < item_count_; i++){
		new_vector.push_back (items_[i]);
	}
	return new_vector;
}

template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const{
	//Goes through the entire list
	for(int i = 0 ; i < item_count_; i++){
		if(target == items_[i]){
			return i;
		}
	}
	//Our Set cannot have a number at
	//-1 position
	return -1;
}
