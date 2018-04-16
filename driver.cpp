/* Author: Garrett Hay
 * Date  : April 4, 2018
 * File  : driver.cpp
 * Description: 
 */

#include <iostream>
#include <string>
#include <fstream>
#include "binary_search.h"

using namespace std;

void menuStart(int deter);
void menuChoice(binary_search &bst, int menuRepeat, int action);
void options(binary_search &bst, int action);

int main() {
  binary_search bst;
  int used = 0;
  int action = 0;
  //starts menu
  menuStart(used);
  used++;
  //action to do
  cout << "Enter Here: ";
  cin >> action;
  //menu that uses the different options
  menuChoice(bst, used, action);
  
  
  return 0;
}

void menuStart(int deter) {
  if(deter  == 0)
    cout << "Welcome to the Quicker Sort Listings.\n";
  cout << "Please select an action to perform: \n\n"
       << "1. Insert into the list\n"
       << "2. Search keys for a value in the list\n"
       << "3. Print the keys & values in the current list\n"
       << "4. Print the current Smallest key in the list\n"
       << "5. Print the current Largest key in the list\n"
       << "6. Save the list to a file\n"
       << "7. delete an item via key from the list\n"
       << "8. End the Program" << endl;
}

void menuChoice(binary_search &bst, int menuRepeat, int action) {
  while(action != 8) {
    options(bst,action);
    cout << "\n\n";
    menuStart(menuRepeat);
    cout << "Enter next action here: ";
    cin  >> action;
    
  }
  cout << "Thank You for using this Program!" << endl;
}

void options(binary_search &bst, int action) {
  switch(action) {
    case 1:
      {
      string key;
      int data;
      cout << "\nInserting into the list:\n"
	   << "Please enter the key for the item: ";
      cin  >> key;
      cout << "Please enter the number data for the item: ";
      cin  >> data;
      bst.set(key, data);
      break;
      }
    case 2:
      {
      string finding;
      int found = 0;
      cout << "\nSearch via key for an item in the list:\n"
	   << "Please enter the key of the item you are looking for: ";
      cin  >> finding;
      cout << endl;
      
      found = bst.find(finding);
      if (found == -1000)
	cout << "No Item." << endl;
      else
	cout << "Found: " << found << endl;
      break;
      }
    case 3:
      {
      cout << "\nThis is the current list, sorted (key,value):\n";
      bst.print();
      break;
      }
    case 4:
      {
      cout << "\nThe current smallest key item is: \n";
      bst.min();
      break;
      }
    case 5:
      {
      cout << "\nThe current largest key item is: \n";
      bst.max();
      break;
      }
    case 6:
      {
      string fileName;
      cout << "\nPlease enter the file name that you would like the list saved to: \n";
      cin  >> fileName;
      bst.save_file(fileName);
      break;
      }
    case 7:
      {
      string delKey;
      cout << "\nPlease enter the key of the item you wish to delete: " << endl;
      cin  >> delKey;
      bst.deleteItem(delKey);
      break;
      }
    default:
      {
      cout << "You have enter a number that is not a choice.\n"
	   << "Please try again.";
      break;
      }
  }
}



      
   
