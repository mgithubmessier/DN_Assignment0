#include <Node.h>
#include <iostream>
Node::Node() {
  next = NULL;
  previous = NULL;
  position = -1;
}
Node::~Node() {
  //  if(position != -1)
  //cout << "~Node():deleting: " << item.key << endl;
}

