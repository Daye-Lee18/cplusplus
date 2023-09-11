#include "myset.h"

void MySet::Insert(int data) {
  // TODO: insert 'data' into set
  // BST
  /*
  if (bst.Search(bst.GetRoot(), data) == NULL){
      bst.Insert(data);
      size++;
  }
  */
  // RBT
  if (rbt.Search(rbt.GetRoot(), data)->key == 0){
    rbt.Insert(data);
    size++;
  }
}

void MySet::Erase(int data) {
  // TODO: erase 'data' from set
  // BST
  /*
  BST::Node* target = bst.Search(bst.GetRoot(), data);
  if (target != NULL){
    bst.Delete(target);
    size--;
  }
  */
  //RBT
  RBT::Node* target = rbt.Search(rbt.GetRoot(), data);
  if (target->key != 0){
    rbt.Delete(target);
    size--;
  }
}

bool MySet::Find(int data) {
  // TODO: return true if 'data' exists in the set
  // BST 
  /*
  if (bst.Search(bst.GetRoot(), data) != NULL){
    return true; 
  }
  else{
    return false;
  }
  */
  // RBT
  if (rbt.Search(rbt.GetRoot(), data)->key != 0){
    return true;
  }
  else{
    return false;
  }
}

size_t MySet::Size() {
  // TODO: return number of elements in the set
  return size;
}
