#include <Item.h>
#include <Node.h>
class List // Keeps track of the items whose keys end up at the same table position
{
  List();       // constructor
  ~List();      // destructor;
  private: Node *nCurrent; // current node in list of Nodes
  int iCurrent;  // current location (-1 if empty or invalid location)
  void first(); // reset list position to first item
  void last();  // reset list position to last item
  void makecurrent(int position); // reset list position to position
  void prev();  // reset list position to previous item
  void next();  // reset list position to next item
  Item examine(); // get item at current location
  int count; // return number of items in list
  void insertBefore(Item item); // insert item before current position
  void insertAfter(Item item); // insert item after current position
  void remove(); // remove current item, next node becomes current node (unless current node was last node in list in which case next node becomes previous node)
  void replace(Item item); // replace current item with item
  bool empty(); // true if list is empty
};
