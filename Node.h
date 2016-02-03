#include <Item.h>
struct Node
{
public: Node * next;
  Node * previous;
  int position;
  Item item;
  ~Node();
  Node();
};
