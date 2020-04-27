/******************************************************************************
File Name: DoublyLinkedList.hpp
Author: Esteban Mundo
Uploaded on: April 27, 2020
Purpose:
  Header File for DoublyLinkedList Class
******************************************************************************/


#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_

#include "DoubleNode.hpp"
#include <iostream>

template<class T>
class DoublyLinkedList{
public:
  DoublyLinkedList();
  DoublyLinkedList(const DoublyLinkedList<T>& original);
  ~DoublyLinkedList();

  // Mutators
  bool insert(const T& item, const int & position);
  bool remove(const int & position);

  void display() const;
  void displayBackwards() const;
  void clear();

  DoublyLinkedList<T> interleave(const DoublyLinkedList<T>* a_list);

  // Accesors
  int getSize() const;
  DoubleNode<T>* getheadPtr() const;
  DoubleNode<T>* getAtPos(const int& pos) const;
  bool isEmpty() const;

private:
  int item_count;
  DoubleNode<T>* headptr_;
  DoubleNode<T>* tailptr_;
};

#include "DoublyLinkedList.cpp"
#endif