#include <LookupTable.h>
#include <iostream>
using namespace std;
LookupTable::LookupTable() {
  table = new List[10];
}
LookupTable::~LookupTable() {
  delete [] table;
  table = NULL;
}
Item LookupTable::retrieve(string key) {
  int numConsonants = 0;
  for(int i = 0; i < key.size(); i++) {
    if(!(key.at(i) == 'a' ||
	 key.at(i) == 'e' ||
	 key.at(i) == 'i' ||
	 key.at(i) == 'o' ||
	 key.at(i) == 'u'))
      numConsonants++;
  }
  List * currentList = &table[numConsonants%10];
  //start from the top
  (*currentList).first();
  for(int i = 0; i < (*currentList).count; i++) {
    if((*currentList).examineKey() == key) {
      cout << "LookupTable:retrieve(): key: " << key << " retrieved. " <<endl;      
      return (*currentList).examineItem();
    }
    (*currentList).next();
  }
  //else, the item was never found and an invalid item is returned
  Item wrongItem;
  wrongItem.vowels = wrongItem.consonants = wrongItem.count = -1;
  return wrongItem; 
}
bool LookupTable::insert(string key, Item value) {
  //insert the item at a row according to its number of consonants
  List * currentList = &table[value.consonants%10];
  //start from the top
  cout << "LookupTable:insert(): calling first" << endl;
  (*currentList).first();
  //insert it before an item with a larger number of vowels, or after the last item in the list
  if((*currentList).count > 0) {
    (*currentList).insertAfter(value);
  } else {
    cout << "LookupTable:insert(): inserting before position " << (*currentList).iCurrent << endl;
    (*currentList).insertBefore(value);
    return true;
  }
  cout << "LookupTable:insert(): inserting at end of list" << endl;
  (*currentList).insertAfter(value);
  return true;
}
bool LookupTable::remove(string key) {
  int numConsonants = 0;
  //find the number of consonants in the key
  for(int i = 0; i < key.size(); i++) {
    if(!(key.at(i) == 'a' ||
	 key.at(i) == 'e' ||
	 key.at(i) == 'i' ||
	 key.at(i) == 'o' ||
	 key.at(i) == 'u' )) {
      numConsonants++; 
    }
  }
  //get the list corresponding with the number of consonants in the key
  List * currentList = &table[numConsonants%10];
  //start from the top
  (*currentList).first();
  //remove the item with the same key name
  for(int i = 0; i < (*currentList).count; i++) {
    cout << "LookupTable:remove(): key: " << key << endl;
    cout << "LookupTable:remove(): current item: " << (*currentList).examineKey() << endl;
    if((*currentList).examineKey() == key) {
      (*currentList).remove();
      return true;
    }
    (*currentList).next();
  }
  return false;
}
int LookupTable::numberUnused() {
  int numUnused = 0;
  for(int i = 0; i < 10; i++) {
    if(table[i].empty())
      numUnused++;
  }
  return numUnused;
}
int LookupTable::numberUsed() {
  int numUsed = 0;
  for(int i = 0; i < 10; i++) {
    if(!(table[i].empty()))
      numUsed++;
  }
  return numUsed;
}
int LookupTable::minimumCollisions() {
  //for each item in the entire table, find the min through linear searching
  List currentList = table[0];
  currentList.first();
  int currentMinimum = table[0].examineItem().count;
  
  for(int listIterator = 0; listIterator < 10; listIterator++) { 
    currentList = table[listIterator];
    currentList.first();
    for(int itemIterator = 0; itemIterator < currentList.count; itemIterator++) {
      if(currentMinimum > currentList.examineItem().count)
	currentMinimum = currentList.examineItem().count;
      currentList.next();
    }
  }
}
int LookupTable::maximumCollisions() {
  //for each item in the entire table, find the max through linear searching
  List currentList = table[0];
  currentList.first();
  int currentMaximum = table[0].examineItem().count;

  for(int listIterator = 0; listIterator < 10; listIterator++) {
    currentList= table[listIterator];
    currentList.first();
    for(int itemIterator = 0; itemIterator < currentList.count; itemIterator++) {
      if(currentMaximum < currentList.examineItem().count)
	currentMaximum= currentList.examineItem().count;
      currentList.next();
    }
  }

}
void LookupTable::display() {
  List currentList;
  for(int listIterator = 0; listIterator < 10; listIterator++) {
    currentList = table[listIterator];
    currentList.first();
    cout << "ROW[" << listIterator << "]:";
    cout << " size: "<< currentList.count << endl << " \tItem:";
    for(int itemIterator = 0; itemIterator < currentList.count; itemIterator++) {
      cout << " "<< currentList.examineKey();       
      currentList.next();
    }
    cout << endl;
  }
  cout << endl;
}
