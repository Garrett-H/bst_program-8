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
  char except = 'a';
  try{
  int valFound = findCycle(root, keyFind);
  }
  catch(except)
    cerr << "Error #2: No Item Found\n";
  return valFound;
}
int binary_search::findCycle(bstNode* currFind, string keyFind) {
  if(currFind == NULL)
    throw "Error #2: No Item Found\n";
  else if(currFind->key == keyFind)
    return currFind->value;
  else{
    if(currFind->key < keyFind)
      findCycle(currFind->right);
    else
      findCycle(currFind->left);
  }
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
  ofstream fOut;
  fOut.open(fileInsert.c_str());
  fileCycle(root, fOut);
  fOut.close();
}
void binary_search::fileCycle(bstNode* currFile, ofstream& fOut) {
  if(currFile != NULL) {
    fileCycle(currFile->left, fOut);
    fOut << currFile->key << " " << currFile->data << '\n';
    fileCycle(currFile->right, fOut);
  }
}


void binary_search::delete(string keyDelete) {
  deleteCycle(root, keyDelete);
}
void binary_search::deleteCycle(bstNode* currDel, string keyDel) {
  if (currDel == NULL)
    cout << "Error #1: Key Not Found." << endl;
  else if(currDel->key < keyDel)
    deleteCycle(currDel->right, keyDel);
  else if(currDel->key > keyDel)
    deleteCycle(currDel->left, keyDel);
  else {
    bstNode* temp= currDel->right;

    if(currDel->left==NULL  && currDel->right==NULL) {
      delete currDel;
      currDel = temp;
    }
    else if(currDel->right != NULL && currDel->left == NULL) {
      delete currDel;
      currDel = temp;
    }
    else if(currDel->left != NULL && currDel->right == NULL) {
      temp = currDel->left;
      delete currDel;
      currDel = temp;
    }
    else {
      while(temp->left != NULL)
	temp = temp->left;
      currDel->key = temp->key;
      currDel->data = temp->data;
    }
  }
}
