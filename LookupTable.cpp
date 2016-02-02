#include <LookupTable.h>
#include <iostream>
using namespace std;
LookupTable::LookupTable() {
  List tempTable [10];
  this -> table = tempTable;
}
LookupTable::~LookupTable() {
}
Item LookupTable::retrieve(string key) {
  int numVowels = 0, numConsonants = 0;
  for(int i = 0; i < key.size(); i++) {
    if(key.at(i) == 'a' ||
       key.at(i) == 'e' ||
       key.at(i) == 'i' ||
       key.at(i) == 'o' ||
       key.at(i) == 'u' ) {
      numVowels++;
    }
    else {
      numConsonants++;
    }
  }
  List currentList = this -> table[numConsonants%10];
  currentList.first();
  for(int i = 0; i < currentList.count; i++) {
    if(currentList.examine().vowels == numVowels)
      return currentList.examine();
    else
      currentList.next();
  }
  Item wrongItem;
  wrongItem.vowels = -1;
  wrongItem.consonants = -1;
  wrongItem.count = -1;
  return wrongItem; 
}
bool LookupTable::insert(string key, Item value) {
  //check if the item already exists
  List currentList = this -> table[value.consonants%10];
  currentList.first();
  for(int i = 0; i < currentList.count; i++) {
    if(currentList.examine().vowels == value.vowels) {
      currentList.examine().count++;
      return false;
    }
    currentList.next();
  }
  currentList.insertAfter(value);
}
bool LookupTable::remove(string key) {
  int numVowels = 0, numConsonants = 0;
  for(int i = 0; i < key.size(); i++) {
    if(key.at(i) == 'a' ||
       key.at(i) == 'e' ||
       key.at(i) == 'i' ||
       key.at(i) == 'o' ||
       key.at(i) == 'u' ) {
      numVowels++;
    }
    else {
      numConsonants++;
    }
  }
  List currentList = this -> table[numConsonants%10];
  currentList.first();
  for(int i = 0; i < currentList.count; i++) {
    if(currentList.examine().vowels == numVowels) {
      currentList.remove();
      return true;
    }
    currentList.next();
  }
  return false;
}
int LookupTable::numberUnused() {
  int numUnused = 0;
  for(int i = 0; i < 10; i++) {
    if(this -> table[i].empty())
      numUnused++;
  }
  return numUnused;
}
int LookupTable::numberUsed() {
  int numUsed = 0;
  for(int i = 0; i < 10; i++) {
    if(!(this -> table[i].empty()))
      numUsed++;
  }
  return numUsed;
}
int LookupTable::minimumCollisions() {
  List currentList = table[0];
  currentList.first();
  int currentMinimum = table[0].examine().count;
  
  for(int listIterator = 0; listIterator < 10; listIterator++) { 
    currentList = table[listIterator];
    currentList.first();
    for(int itemIterator = 0; itemIterator < currentList.count; itemIterator++) {
      if(currentMinimum > currentList.examine().count)
	currentMinimum = currentList.examine().count;
      currentList.next();
    }
  }
}
int LookupTable::maximumCollisions() {
  List currentList = table[0];
  currentList.first();
  int currentMaximum = table[0].examine().count;

  for(int listIterator = 0; listIterator < 10; listIterator++) {
    currentList= table[listIterator];
    currentList.first();
    for(int itemIterator = 0; itemIterator < currentList.count; itemIterator++) {
      if(currentMaximum < currentList.examine().count)
	currentMaximum= currentList.examine().count;
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
    for(int itemIterator = 0; itemIterator < currentList.count; itemIterator++) {
      cout << "\tV:" << currentList.examine().vowels << " C:" << currentList.examine().consonants; 
    }
    cout << endl;
  }
}
