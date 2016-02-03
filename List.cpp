#include <List.h>
#include <iostream>
using namespace std;
List::List() {
  iCurrent = -1;
  count = 0;
}

List::~List() {
  first();
  Node * nextNode;
  for(int i = 0; i < count - 1; i++) {
    nextNode = this -> nCurrent -> next;
    delete (this -> nCurrent);
    this -> nCurrent = nextNode;
  }
}
void List::first() {
  //iterate backward to the first element
  for(int i = this -> iCurrent; i > 1; i--) {
    this -> nCurrent = this -> nCurrent -> previous;
  }
  this -> iCurrent = 0;
}
void List::last() {
  //iterate forward to the last element
  for(int i = this -> iCurrent; i < count - 1; i++) {
    this -> nCurrent = this -> nCurrent -> next;
  }
  this -> iCurrent = count - 1;
}
//have yet to realize a use for this function
void List::makecurrent(int position) {
  this -> iCurrent = position;
}
void List::prev() {
  //move back to the previous item
  //not cyclical, stop the iterator if at beginning of the linked list
  if(this -> iCurrent > 0) {
    this -> iCurrent--;
    this -> nCurrent = this -> nCurrent -> previous;
  }
}
void List::next() {
  //move forward to the next item
  //not cyclical, stop the iterator if at the end of the linked list
  if(this -> iCurrent < count - 1) {
    this -> iCurrent++;
    this -> nCurrent = this -> nCurrent -> next;
  }
}

Item List::examine() {
  return this -> nCurrent -> item;
}
void List::insertBefore(Item item) {
  Node * prevNode = this -> nCurrent -> previous;
  Node * newNode;
  Node holdingCurrent = *(this -> nCurrent);
  //check if it already exists
  first();
  for(int i = 0; i < count; i++) {
    if(this -> nCurrent -> item.vowels == item.vowels) {
      this -> nCurrent -> item.count++;
      return;      
    }
    next();
  }
  newNode -> position = this -> iCurrent;
  newNode -> next = this -> nCurrent;
  newNode -> item = item;
  if(this -> iCurrent > 0) {
    newNode -> previous = prevNode;
    prevNode -> next = newNode;
  }
  this -> nCurrent -> previous = newNode;  
  this -> nCurrent -> position = this -> iCurrent+1;
  count++;
}
void List::insertAfter(Item item) {
  Node * nextNode = this -> nCurrent -> next;
  Node * newNode;
  newNode -> position = this -> iCurrent + 1;
  newNode -> next = this -> nCurrent;
  newNode -> item = item;
  if(this -> iCurrent < count - 1) {
    newNode -> next = nextNode;
    nextNode -> previous = newNode;
  }
  this -> nCurrent -> next = newNode;
  count++;
}
void List::remove() {
  //set the previous node's next position to the current node's next position
  this -> nCurrent -> previous -> next = this -> nCurrent -> next;
  //set the next node's previous position to the current node's previous position;
  this -> nCurrent -> next -> previous = this -> nCurrent -> previous;
  //set the current node equal to its next node
  this -> nCurrent = this -> nCurrent -> next;
  Node * iterator = this -> nCurrent;
  while(iterator -> next -> position != -1) {
    iterator -> position--;
    iterator = iterator -> next;
  }
  count--;
}
void List::replace(Item item) {
  this -> nCurrent -> item = item;
}
bool List::empty() {
  return (count == 0);
}

