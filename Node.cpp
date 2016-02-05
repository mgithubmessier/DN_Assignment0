#include <Node.h>
#include <iostream>
Node::Node() {
  next = NULL;
  previous = NULL;
  position = -1;
}
Node::~Node() {
  cout << "~Node():deleting: " << item.key << endl;
}

