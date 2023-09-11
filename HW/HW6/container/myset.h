#pragma once

#include "bst.h"
#include "rbt.h"

class MySet{
  public:
    void Insert(int data);
    void Erase(int data);
    
    bool Find(int data);
    size_t Size();

  private:
    int size = 0;
    // BST
    //BST bst;
    // RBT
    RBT rbt;
};
