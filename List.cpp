#include <List.h>
#include <iostream>
using namespace std;
List::List() {
  iCurrent = -1;
  count = 0;
  nCurrent = new Node();
}

List::~List() {
  first();
  Node * nextNode;
  //a list always is instansiated with at least one allocated Node
  if(count == 0 || count == 1) {
    if(count == 0)
      cout << "deleting the element of an empty list: " << endl;
    else 
      cout << "deleting the only element of a list: " << iCurrent << ": "<< examineKey() <<  endl;
    // this line makes equalizes the difference between a list that has been deleted empty, and a list that never received an element in the first place
    //a list with no element in the first place still needs the allocated space deleted, where a list deleted empty has nothing to delete
    nCurrent = new Node();
    delete nCurrent;
    count = 0;
    return;
  }
  cout << "deleting a list of size greater than 1" << endl;
  //cover the rest of the list if it has more than one in it
  for(int i = 0; i < count; i++) {
    //make sure we do not access a null  node at the end of the list
    nextNode = nCurrent -> next; 
    delete nCurrent;
    
    nCurrent = nextNode;
  }
  delete nextNode;
}
void List::first() {
  //iterate backward to the first element
  //cout << "List:first(): currentKey: " << iCurrent << ": " << examineKey() << endl; 
  for(int i = iCurrent; i > 0; i--) {
    prev();
    //cout << "List:first(): currentKey: " << iCurrent << ": " << examineKey() << endl; 
  }
}
void List::last() {
  //iterate forward to the last element
  for(int i = iCurrent; i < count - 1; i++) {
    next();
  }
}
//have yet to realize a use for this function
void List::makecurrent(int position) {
  iCurrent = position;
}
void List::prev() {
  //move back to the previous item
  //not cyclical, stop the iterator if at beginning of the linked list
  if(iCurrent > -1) {
    iCurrent--;
    nCurrent = nCurrent -> previous;
  }
}
void List::next() {
  //move forward to the next item
  //not cyclical, stop the iterator if at the end of the linked list
  if(iCurrent < count - 1) {
    //cout << "List:next: actually incrementing" << endl;
    iCurrent++;
    nCurrent = nCurrent -> next;
  }
}

Item List::examineItem() {
  return nCurrent -> item;
}
string List::examineKey() {
  return nCurrent -> item.key;
}
void List::insertBefore(Item item) {
  if(!empty()) {
    //check if it already exists
    first();
    for(int i = 0; i < count; i++) {
      if(nCurrent -> item.key == item.key) {
	nCurrent -> item.count++;
	return;      
      }
      next();
    }
    //if it does not already exist
    //iterate through the list until you find an item with vowels greater than or equal to the item to be inserted
    first();
    for(int i = 0; i < count; i++) {
      if(item.vowels < nCurrent -> item.vowels)
	next();
      else
	break;
    }
    Node * prevNode = nCurrent -> previous;
    Node * newNode = new Node();
    //insert the parameter item into a new node here
    newNode -> position = iCurrent;
    newNode -> next = nCurrent;
    newNode -> item = item;
    //if there is at least one item behind it, connect them
    if(iCurrent > 0) {
      newNode -> previous = prevNode;
      prevNode -> next = newNode;
    }
    //connect the new node to the one it is being inserted behind
    nCurrent -> previous = newNode;  
    nCurrent -> position = iCurrent+1;
  } else {
    //the list is empty, this is the first node
    nCurrent -> position = iCurrent = 0;
    nCurrent -> item = item;
  }
  count++;
  cout << "List:insertBefore(): list size: " << count << endl;
}
void List::insertAfter(Item item) {
  //if list is not empty
  if(!empty()) {
    //check if it already exists
    first();
    for(int i = 0; i < count; i++) {
      if(nCurrent -> item.key == item.key) {
	nCurrent -> item.count++;
	return;
      } 
      next();
    }
    //if it does not already exist
    first();
    for(int i = 0; i < count; i++) {
      if(item.vowels < nCurrent -> item.vowels)
	next();
      else 
	break;
    }
    Node * nextNode = nCurrent -> next;
    Node * newNode = new Node();
    newNode -> item = item;
    newNode -> position = iCurrent + 1;
    newNode -> previous = nCurrent;
    cout << "List:insertAfter: 1 " << nCurrent -> item.key << endl;
    if(iCurrent < count - 1) {
      cout << "List:insertAfter: 2 " << nCurrent -> item.key << endl;
      newNode -> next = nextNode;
      nextNode -> previous = newNode;
    }
    nCurrent -> next = newNode;
    cout << "List:insertAfter: 3 " << nCurrent -> item.key << endl;
  } else {
    //the list is empty, this is the first node
    nCurrent -> position = iCurrent = 0;
    nCurrent -> item = item;
  }
  count++;
  cout << "List:insertAfter(): list size: " << count << endl;
}
void List::remove() {
  Node * toDelete = nCurrent;
  //set the previous node's next position to the current node's next position
  //it cannot have a previous if it is at position 0 though
  if(iCurrent > 0)
    nCurrent -> previous -> next = nCurrent -> next;
  //set the next node's previous position to the current node's previous position;
  //it cannot have a next if it is at the last position though
  if(iCurrent < count -1) {
    nCurrent -> next -> previous = nCurrent -> previous;
    //set the current node equal to its next node
    nCurrent = nCurrent -> next;
  } else {
    delete nCurrent;
    count--;
    iCurrent--;
    return;
  }
  //reduce all following positions by 1
  Node * iterator = toDelete;

  count--;
  for(int i = iCurrent; i < count; i++) {
    iterator -> position--;
    iterator = iterator -> next;
  }
  first();
  delete toDelete;
}
void List::replace(Item item) {
  nCurrent -> item = item;
}
bool List::empty() {
  return (count == 0);
}

