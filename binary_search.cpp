/* Author: Garrett Hay
 * Date  : 4/4/18
 * File  : binary_search.cpp
 * Description: 
 */

#include <iostream>
#include <string>
#include <fstream>
#include "binary_search.h"

using namespace std;

binary_search::binary_search(){
  root     = NULL;
  lowest   = NULL;
  highest  = NULL:
  size_bst = 0;

}

binary_search::~binary_search(){

}


void binary_search::set(string keyInsert, int dataInsert){
  //make node to be inserted
  bstNode* temp = new bstNode;
  temp->key  = keyInsert;
  temp->data = dataInsert;
  if(root == NULL) {
    root = temp;
    lowest = temp;
    highest = temp;
  }
  else if(temp->key < lowest->key) {
    lowest->left = temp;
    lowest = temp;
  }
  else if(temp->key > highest->key) {
    highest->right = temp;
    highest = temp;
  }
  else
    setCycle(root, temp);
  
}
void binary_search::setCycle(bstNode* currSet, bstNode* tempInsert){
  if(currSet == NULL) {
    currSet = new bstNode;
    currSet = tempInsert;
  }
  //if the key is the same as current
  else if(tempInsert->key == currSet->key)
    currSet->data = tempInsert->data;
  //if the key is less than the current
  else if(tempInsert->key < currSet->key)
    setCycle(currSet->left, tempInsert);
  //if the key is more than the current
  else
    setCycle(currSet->right, tempInsert);
}


int binary_search::find(string keyFind) {

}

void binary_search::print() {
  printCycle(root);  //cycles through entire tree & prints the data for each in sorted order
  cout << endl;      //used for easier reading
}
void binary_search::printCycle(bstNode* currPrint) {
  if(currPrint != NULL) {
    printCycle(currPrint->left);                                          //move left, if can
    cout << "( " << currPrint->key << ", " << currPrint->data << " )\n";  //print itself
    printCycle(currPrint->right);                                         //move right, if can
  }
}

void binary_search::min() {
  cout << "( " << lowest->key << ", " << lowest->data << " )\n";
}

void binary_search::max() {
  cout << "( " << highest->key << ", " << highest->data << " )\n";
}

void binary_search::save_file(string fileInsert) {

}

void binary_search::delete(string keyDelete) {

}
