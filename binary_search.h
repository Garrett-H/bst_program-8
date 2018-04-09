/* Author: Garrett Hay
 * Date  : 4/4/18
 * File  : binary_search.h
 * Description: 
 */

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include <string>
#include <fstream>

class binary_seach
{
 public:
  binary_search();
  ~binary_search();
  void set(std::string keyInsert, int dataInsert);
  int find(std::string keyFind);
  void print();
  void min();
  void max();
  void save_file(std::string fileInsert);
  void delete(std::string keyDelete);
 private:
  struct bstNode
  {
    std::string key;
    int data;
    bstNode *left, *right;
  }
  bstNode* root;
  bstNode* lowest;
  bstNode* highest;
  
  void setCycle(bstNode* currSet, bstNode* tempInsert);
  void findCycle();
  void printCycle(bstNode* currPrint);
  void fileCycle(bstNode* currFile, std::ofstream& fOut);
  
#endif // BINARY_SEARCH_H
