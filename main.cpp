#include <LookupTable.h>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Item createItem(string itemKey) {
  Item newItem;
  int numVowels = 0, numConsonants = 0;
  for(int i = 0; i < itemKey.size(); i++) {
    if(itemKey.at(i) == 'a' ||
       itemKey.at(i) == 'e' ||
       itemKey.at(i) == 'i' ||
       itemKey.at(i) == 'o' ||
       itemKey.at(i) == 'u' ) {
      numVowels++;
    }
    else {
      numConsonants++;
    }
  }
  newItem.vowels = numVowels;
  newItem.consonants = numConsonants;
  newItem.count = 0;
  newItem.key = itemKey;
  return newItem;
}
void test()
{
  LookupTable table;
  cout << "test(): inserting 'when'" << endl;
  table.insert("when", createItem("when"));        table.display();
  cout << "test(): inserting 'can'" << endl;
  table.insert("can", createItem("can"));          table.display();
  cout << "test(): inserting 'sailing'" << endl;
  table.insert("sailing", createItem("sailing"));  table.display();
  cout << "test(): inserting 'weather'" << endl;
  table.insert("weather", createItem("weather"));  table.display();

  Item i = table.retrieve("when");

  i = table.retrieve("weather");

  table.remove("when");
  table.display();
  table.remove("weather");

  i = table.retrieve("weather");

  table.display();
}

int main()
{
  //test();
  LookupTable table;
   
  // READ IN THE LIST OF KEYS HERE…
  ifstream inputFile;
  inputFile.open("input.txt");
  string line;
  
  while(getline(inputFile,line)) {
    remove(line.begin(),line.end(),' ');
    table.insert(line,createItem(line));
  }
  table.display();

  Item i = table.retrieve("when");
  cout << "count for when is: " << i.count << endl; // should be 1

  i = table.retrieve("weather");
  cout << "count for weather is: " << i.count << endl; // should be 2

  table.remove("when");
  table.remove("weather");

  i = table.retrieve("weather");
  cout << "count for weather is: " << i.count << endl; // should  be 1

  table.display();
}
