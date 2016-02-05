#include <Node.h>
#include <iostream>
Node::Node() {
  next = NULL;
  previous = NULL;
  position = -1;
}
Node::~Node() {
  //delete this -> next;
  //delete this -> previous;
}

