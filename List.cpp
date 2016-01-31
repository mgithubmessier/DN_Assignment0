#include <List.h>

List::List() {
  iCurrent = -1;
  count = 0;
}

List::~List() {
  first();
  Node * nextNode;
  for(int i = 0; i < count - 1; i++) {
    nextNode = this -> nCurrent -> next;
    delete this -> nCurrent;
    this -> nCurrent = nextNode;
  }
}
void List::first() {
  for(int i = this -> iCurrent; i > 1; i--) {
    this -> nCurrent = this -> nCurrent -> previous;
  }
  this -> iCurrent = 0;
}
void List::last() {
  for(int i = this -> iCurrent; i < count - 1; i++) {
    this -> nCurrent = this -> nCurrent -> next;
  }
  this -> iCurrent = count - 1;
}
void List::makecurrent(int position) {
  this -> iCurrent = position;
}
void List::prev() {
  if(this -> iCurrent > 0) {
    this -> iCurrent--;
    this -> nCurrent = this -> nCurrent -> previous;
  }
}
void List::next() {
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
  delete nCurrent;
  count--;
}
void List::replace(Item item) {
  this -> nCurrent -> item = item;
}
bool List::empty() {
  return (count <= 0);
}

