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
  highest  = NULL;
}


binary_search::~binary_search(){
  deconCycle(root);
}
void binary_search::deconCycle(bstNode* currDecon) {
  if(currDecon != NULL) {
    deconCycle(currDecon->left);
    deconCycle(currDecon->right);
    delete currDecon;
  }
}


void binary_search::set(string keyInsert, int dataInsert){
  //make node to be inserted
  cout << "Making new Node: " << endl;
  bstNode* temp = new bstNode;
  temp->key = keyInsert;
  temp->data = dataInsert;
  cout << "Inserting Node: " << endl;
  //if root is empty make it equal to temp
  if(root == NULL) {
    root = temp;
    lowest = temp;
    highest = temp;
  }
  //if the key is less than the current lowest make it the lowest
  else if(temp->key < lowest->key) {
    lowest->left = temp;
    lowest = temp;
  }
  //if the key is more than the highest make it the highest
  else if(temp->key > highest->key) {
    highest->right = temp;
    highest = temp;
  }
  //if not root, lowest, or highest then insert using helper
  else
    setCycle(root, temp);
  cout << "Node Inserted: " << endl;
}
void binary_search::setCycle(bstNode* currSet, bstNode* tempInsert) {
  //if the key is the same as current
  if(tempInsert->data == currSet->data)
    currSet->key = tempInsert->key;
  //if the key is less than the current
  else if(tempInsert->key < currSet->key) {
    if(currSet->left == NULL)
      currSet->left = tempInsert;
    else
      setCycle(currSet->left, tempInsert);
  }
  //if the key is more than the current
  else {
    if (currSet->right == NULL)
      currSet->right = tempInsert;
    else
      setCycle(currSet->right, tempInsert);
  }
}


int binary_search::find(string keyFind) {
  //return value
  int valFound;
  cout << "Searching..." << endl;
  //if the key searched is the lowest
  if(keyFind == lowest->key)
    valFound = lowest->data;
  //if the key searched is the highest
  else if (keyFind == highest->key)
    valFound = highest->data;
  //if it is neither
  else
    valFound = findCycle(root, keyFind);
  //if the value is the default return value. I.E. the not found integer
  if(valFound == -1000)
    cout << "Item not found." << endl;
  
  return valFound;
}
int binary_search::findCycle(bstNode* currFind, string &keyFind) {
  //default return value
  int found= -1000;
  //if the node is empty
  if(currFind == NULL)
    return found;
  //if the key to find is the current one
  else if(currFind->key == keyFind)
    found = currFind->data;
  //if key to find is greater than the current one
  else if(currFind->key < keyFind)
    found = findCycle(currFind->right, keyFind);
  //if key to find is less than the current one
  else
    found = findCycle(currFind->left, keyFind);
  
  return found;
}


void binary_search::print() {
  printCycle(root);  //cycles through entire tree & prints the data for each in sorted order
  cout << endl;      //used for easier reading
}
void binary_search::printCycle(bstNode* currPrint) {
  //if the current Node is at the end
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
  ofstream fOut;
  fOut.open(fileInsert.c_str());
  fileCycle(root, fOut);
  fOut.close();
}
void binary_search::fileCycle(bstNode* currFile, ofstream &fOut) {
  if(currFile != NULL) {
    fileCycle(currFile->left, fOut);
    fOut << currFile->key << " " << currFile->data << '\n';
    fileCycle(currFile->right, fOut);
  }
}


void binary_search::deleteItem(string keyDelete) {
  deleteCycle(root, keyDelete);
}
void binary_search::deleteCycle(bstNode* &currDel, string keyDel) {

  //if root is NULL or later cycles don't find the key
  if (currDel == NULL)
    cout << "Error #1: Key Not Found." << endl;

  //if the key to be deleted is greater than the current key
  else if(currDel->key < keyDel)
    deleteCycle(currDel->right, keyDel);
  
  //if the key to be deleted is less than the current key
  else if(currDel->key > keyDel)
    deleteCycle(currDel->left, keyDel);
  
  //if the current key is the key to be deleted
  else {
    //temp is the replacement for the deleting node
    bstNode* temp;
    if(currDel->left == NULL && currDel->right == NULL)
      currDel = NULL;
    //if the current left is NULL
    else if(currDel->left==NULL) {
      temp = currDel->right;
      delete currDel;
      currDel = temp;
    }
    //if the current right is NULL, but the left is not
    else if(currDel->right == NULL) {
      temp = currDel->left;
      delete currDel;
      currDel = temp;
    }
    //if the current has both left & right
    else {
      bstNode* stem;
      temp= currDel->right;
      stem= NULL;
      //setting temp to the lowest right stems
      while(temp->left != NULL) {
	stem = temp;
	temp = temp->left;
      }
      //setting the to be deleted to the leftmost right stem
      currDel->key = temp->key;
      currDel->data = temp->data;
      //deleting the leftmost
      if(stem != NULL)
	deleteCycle(stem->left, stem->left->key);
      else
	deleteCycle(currDel->right, currDel->right->key);
    }
  }
}
