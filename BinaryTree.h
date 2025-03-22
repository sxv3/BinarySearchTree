#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree {
public:
  BinaryTree();
  ~BinaryTree();

  void insert(int val);
  void remove(int val);
  bool search(int val);
  void print();

private:
  Node* root;

  void insert(Node* &node, int val);
  Node* remove(Node* node, int val);
  Node* findMin(Node* node);
  bool search(Node* node, int val);
  void print(Node* node, int space);
  void destroyTree(Node* node);
};

#endif
