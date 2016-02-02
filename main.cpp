#include <LookupTable.h>
#include <iostream>

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
  return newItem;
}
void test()
{
  /*
  LookupTable table;
   
  table.insert(“when”, createItem(“when”));       table.display();
  table.insert(“can”, createItem(“can”));         table.display();
  table.insert(“sailing”, createItem(“sailing”)); table.display();
  table.insert(“weather”, createItem(“weather”)); table.display();
  table.insert(“weather”, createItem(“weather”)); table.display();

  Item i = table.retrieve(“when”);
  cout << “count for when is: “ << i.count << endl; // should be 1

  i = table.retrieve(“weather”);
  cout << “count for weather is: “ << i.count << endl; // should be 2

  table.remove(“when”);
  table.remove(“weather”);

  i = table.retrieve(“weather”);
  cout << “count for weather is: “ << i.count << endl; // should  be 1

  table.display();
  */
}

int main()
{
  /*
  LookupTable table;
   
  // READ IN THE LIST OF KEYS HERE…

  table.display();

  Item i - table.retrieve(“when”);
  cout << “count for when is: “ << i.count << endl; // should be 1

  i = table.retrieve(“weather”);
  cout << “count for weather is: “ << i.count << endl; // should be 2

  table.remove(“when”);
  table.remove(“weather”);

  i = table.retrieve(“weather”);
  cout << “count for weather is: “ << i.count << endl; // should  be 1

  table.display();
  */
}
