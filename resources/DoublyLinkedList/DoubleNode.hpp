/******************************************************************************
File Name: DoubleNode.hpp
Author: Esteban Mundo
Uploaded on: April 27, 2020
Purpose:
  Header File for DoubleNode Class
******************************************************************************/

#ifndef DOUBLENODE_HPP_
#define DOUBLENODE_HPP_

template<class ItemType>
class DoubleNode{
public:
  DoubleNode();
  DoubleNode(ItemType item, DoubleNode<ItemType>* next = nullptr, DoubleNode<ItemType>* back = nullptr);

  ItemType getItem();
  DoubleNode<ItemType>* getNext();
  DoubleNode<ItemType>* getBack();

  void setNext(DoubleNode<ItemType>* node);
  void setBack(DoubleNode<ItemType>* node); 

private:
  DoubleNode<ItemType>* next_;
  DoubleNode<ItemType>* back_;
  ItemType item_;

};

#include "DoubleNode.cpp"
#endif