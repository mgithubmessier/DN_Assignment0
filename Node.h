#include <Item.h>
struct Node
{
  Node * next;
  Node * previous;
  int position;
  Item item;
  ~Node();
  Node();
};
