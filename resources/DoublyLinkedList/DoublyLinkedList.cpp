/******************************************************************************
File Name: DoublyLinkedList.cpp
Author: Esteban Mundo
Uploaded on: April 27, 2020
Purpose:
  Implementation File for DoublyLinkedList Class
******************************************************************************/

#include "DoublyLinkedList.hpp"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : headptr_(nullptr), tailptr_(nullptr),
  item_count(0){}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& original) : item_count(0){
  DoubleNode<T>* trv_ptr = original.headptr_;

  while(trv_ptr != nullptr){
    insert(trv_ptr->getItem(), item_count+1);
    trv_ptr= trv_ptr->getNext();
  }
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  clear();
}


template<class T>
bool DoublyLinkedList<T>::insert(const T& item, const int& position){

  // If the position trying to be inserted is not-valid
  if(position < 1)
    return false;

  DoubleNode<T> * newNode = new DoubleNode<T>(item);

  if(headptr_ == nullptr){
    headptr_ = newNode;
    tailptr_ = newNode;

  } else {

    // If the position trying to be inserted is larger than list
    // insert at end
    if(position > item_count){
      DoubleNode<T>* temp = tailptr_;
      tailptr_->setNext(newNode);
      tailptr_ = newNode;
      tailptr_->setBack(temp);
    }

    //if inserting at first position
    else if(position == 1) {
      DoubleNode<T>* temp = headptr_;
      headptr_->setBack(newNode);
      headptr_ = newNode;
      headptr_->setNext(temp);
    }
    // inserting somewhere in the middle
    else {
      DoubleNode<T>* temp = headptr_;
      int count = 1;
      while(count != position){
        count++;
        temp = temp->getNext();
      }

        // Connect newNode with the items
        newNode->setNext(temp);
        newNode->setBack(temp->getBack());

        // Connect other nodes with node that needs to be inserted
        temp->setBack(newNode);
        newNode->getBack()->setNext(newNode);
    }
  }

  item_count++;
  return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(const int & position){

  if(position < 1 || position > item_count)
    return false;

  DoubleNode<T>* to_delete;

  // Deleting a singular item
  if(item_count == 1){
    to_delete = headptr_;

  }
  // Deleting Front
  else if(position == 1){
    to_delete = headptr_;
    headptr_ = headptr_->getNext();
    headptr_->setBack(nullptr);
  } 
  // Deleting Back
  else if(position == item_count){
    to_delete = tailptr_;
    tailptr_ = tailptr_->getBack();
    tailptr_->setNext(nullptr);
  } 
  // Deleting Middle
  else {
    to_delete = getAtPos(position);
    to_delete->getBack()->setNext(to_delete->getNext());
    to_delete->getNext()->setBack(to_delete->getBack());
  }

  // Delete Object itself
  to_delete->setNext(nullptr);
  to_delete->setBack(nullptr);

  delete to_delete;
  
  item_count--;

  if(item_count == 0){
    headptr_ = nullptr;
    tailptr_ = nullptr;
  }

  return true;
}

template<class T>
void DoublyLinkedList<T>::display() const{
  if(item_count == 0){
    std::cout << "Nothing to display.\n";
    return;
  }
  
  DoubleNode<T>* trv_ptr = headptr_;
  while(trv_ptr->getNext() != nullptr){
    std::cout << trv_ptr->getItem() << ' ';
    trv_ptr = trv_ptr->getNext();
  }
  std::cout << trv_ptr->getItem() << '\n';
}


template<class T>
void DoublyLinkedList<T>::displayBackwards() const{
    if(item_count == 0){
    std::cout << "Nothing to display.\n";
    return;
  }

  DoubleNode<T>* trv_ptr = tailptr_;
  while(trv_ptr->getBack() != nullptr){
    std::cout << trv_ptr->getItem() << ' ';
    trv_ptr = trv_ptr->getBack();
  }
  std::cout << trv_ptr->getItem() << '\n';

}

template<class T>
void DoublyLinkedList<T>::clear(){
  std::cout << item_count << '\n';
  while(item_count >= 1)
    remove(item_count);
}
  
template<class T>
DoublyLinkedList<T> DoublyLinkedList<T>::interleave(const DoublyLinkedList<T>* a_list){
  DoublyLinkedList<T> result;
  DoubleNode<T>* travel_ptr_a = a_list->headptr_;
  DoubleNode<T>* travel_ptr_b = headptr_;
  int position = 1;

  // insert both lists together
  while(travel_ptr_a != nullptr && travel_ptr_b != nullptr){
    result.insert(travel_ptr_a->getItem(), position++);
    result.insert(travel_ptr_b->getItem(), position++);
    travel_ptr_a = travel_ptr_a->getNext();
    travel_ptr_b = travel_ptr_b->getNext();  
  }

  // Assuming a_list is longer than original list
  while(travel_ptr_a != nullptr){
    result.insert(travel_ptr_a->getItem(), position++);
    travel_ptr_a = travel_ptr_a->getNext();
  }

  // Assuming original list is longer than a_list
  while(travel_ptr_b != nullptr){
    result.insert(travel_ptr_b->getItem(), position++);
    travel_ptr_b = travel_ptr_b->getNext();
  }

  return result;
}

// Accesors
template<class T>
int DoublyLinkedList<T>::getSize() const{
  return item_count;
}

template<class T>
DoubleNode<T>* DoublyLinkedList<T>::getheadPtr() const{
  return headptr_;
}

template<class T>
DoubleNode<T>* DoublyLinkedList<T>::getAtPos(const int& pos) const{
  if(pos < 1 || pos > item_count)
    return nullptr;
  
  DoubleNode<T>* trv_ptr = headptr_;

  int counter = pos;
  while(counter != 1){
    trv_ptr = trv_ptr->getNext();
    counter--;
  }
  return trv_ptr;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() const{
  if(item_count == 0)
    return true;
  return false;
}