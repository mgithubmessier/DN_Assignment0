#include <List.h>

List::List() {
  current = -1;
  count = 0;
}
List::~List() {
}
void first() {
  
}
void last() {
}
void makecurrent(int position) {
  current = position;
}
void prev() {
  if(current > 0)
    current--;
  else if(count > 0)
    current = count - 1;
}
void next() {
  if(current < count - 1)
    current++;
  else 
    current = 0;
}
Item examine() {
}
void insertBefore(Item item) {
}
void insertAfter(Item item) {
}
void remove() {
}
void replace(Item item) {
}
bool empty() {
  return (count <= 0);
}
