#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
  root = nullptr;
}

BinaryTree::~BinaryTree() {
  destroyTree(root);
}

//public insert method
void BinaryTree::insert(int val) {
  insert(root, val);
}

//insert helper -> recursive
void BinaryTree::insert(Node* &node, int val) {
  if (node == nullptr) {
    node = new Node(val);
  } else if (val < node->data) {
    insert(node->left, val);
  } else {
    insert(node->right, val);
  }
}


bool BinaryTree::search(int val) {
  return search(root, val);
}

bool BinaryTree::search(Node* node, int val) {
  if (node == nullptr) {
    return false;
  } else if (node->data == val) {
    return true;
  } else if (val < node->data) {
    return search(node->left, val);
  } else {
    return search(node->right, val);
  }
}

void BinaryTree::remove(int val) {
  root = remove(root, val);
}

Node* BinaryTree::remove(Node* node, int val) {
  if (node == nullptr) {
    return nullptr;
  } else if (value < node->data) {
    node->left = remove(node->left, val);
  } else if (value > node->data) {
    node->right = remove(node->right, val);
  } else {
    if ((node->left == nullptr) && (node->right == nullptr)) {
      delete node;
      return nullptr;
    } else if (node->left == nullptr) {
      Node* temp = node->right;
      delete node;
      return temp;
    } else if (node->right == nullptr) {
      Node* temp = node->left;
      delete node;
      return temp;
    }

    Node* temp = findMin(node->right);
    node->data = temp->data;
    node->right = remove(node->right, temp->data);
  }
  return node;
}

Node* BinaryTree::findMin(Node* node) {
  while ((node && node->left) != nullptr) {
    node = node->left;
  }  
  return node;
}

void BinaryTree::print() {
  print(root, 0);
}

void BinaryTree::print(Node* node, int space) {
  if (node == nullptr) {
    return;
  }

  space += 5;
  print(node->right, space);

  for (int i = 5; i < space; i++) {
    cout << " ";
  }

  cout << node->data << endl;
  print(node->left, space);
}

void BinaryTree::destroyTree(Node* node) {
  if (node == nullptr) {
    return;
  }

  destroyTree(node->left);
  destroyTree(node->right);
  delete node;
  
}


