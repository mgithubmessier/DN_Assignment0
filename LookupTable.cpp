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
  //retrieve by row = consonants, col = vowels
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
  //get the list corresponding to the consonants
  List currentList = this -> table[numConsonants%10];
  //start from the top
  currentList.first();
  //find its place corresponding to the vowels
  //return it
  for(int i = 0; i < currentList.count; i++) {
    if(currentList.examine().vowels == numVowels)
      return currentList.examine();
    else
      currentList.next();
  }
  //else, the item was never found and an invalid item is returned
  Item wrongItem;
  wrongItem.vowels = -1;
  wrongItem.consonants = -1;
  wrongItem.count = -1;
  return wrongItem; 
}
bool LookupTable::insert(string key, Item value) {
  //insert the item at a row according to its number of consonants
  List currentList = this -> table[value.consonants%10];
  //start from the top
  cout << "The current number of items"<< currentList.count << endl;
  currentList.first();
  //insert it before an item with a larger number of vowels, or after the last item in the list
  if(value.vowels < currentList.count) {
    for(int i = 0; i < value.vowels; i++) {
      currentList.next();
    }
    currentList.insertBefore(value);
    return true;
  }
  currentList.insertAfter(value);
  return true;
}
bool LookupTable::remove(string key) {
  int numVowels = 0, numConsonants = 0;
  //find the number of vowels and consonants in the key
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
  //get the list corresponding with the number of consonants in the key
  List currentList = this -> table[numConsonants%10];
  //start from the top
  currentList.first();
  //for each, check if the number of vowels equal in a given item equal the number in the key
  //if so, remove that item and decrement the number of items in the list 
  for(int i = 0; i < currentList.count; i++) {
    if(currentList.examine().vowels == numVowels) {
      currentList.remove();
      currentList.count--;
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
  //for each item in the entire table, find the min through linear searching
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
  //for each item in the entire table, find the max through linear searching
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
