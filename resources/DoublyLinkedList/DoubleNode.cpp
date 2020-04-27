/******************************************************************************
File Name: DoubleNode.cpp
Author: Esteban Mundo
Uploaded on: April 27, 2020
Purpose:
  Implementation File for DoubleNode Class
******************************************************************************/

#include "DoubleNode.hpp"

template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : next_(nullptr), back_(nullptr){}


template<class ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType item, DoubleNode<ItemType>* next, DoubleNode<ItemType>* back) : 
item_(item), next_(nullptr), back_(nullptr){}


template<class ItemType>
ItemType DoubleNode<ItemType>::getItem(){
  return item_;
}
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext(){
  return next_;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getBack(){
  return back_;
}

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* node){
  next_ = node;
}

template<class ItemType>
void DoubleNode<ItemType>::setBack(DoubleNode<ItemType>* node){
  back_ = node;
}


