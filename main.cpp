#include <iostream>
#include <cstring>
#include "BinaryTree.h"

using namespace std;

int main() {
  BinaryTree tree;
  char command[80];

  cout << "what would you like to do? (ADD, REMOVE, SEARCH, PRINT, QUIT)" << endl;

  while (true) {
    cout << "enter command:" << endl;
    cin >> command;

    if (strcmp(command, "ADD") == 0) {
      cout << "enter numbers to add (1-999), seperated by spaces and press enter" << endl;
      cin.ignore();
      char input[1000];
      cin.getline(input, 1000);
      char* token = strtok(input, " ");

      while (token != nullptr) {
	int num = atoi(token);
	if ((num >= 1) && (num <= 999)) {
	  tree.insert(num);
	}

	token = strtok(nullptr, " ");
      }
    } else if (strcmp(command, "REMOVE") == 0) {
      cout << "enter number to remove" << endl;
      int num;
      cin >> num;
      tree.remove(num);
    } else if (strcmp(command, "SEARCH") == 0) {
      cout << "enter number to search" << endl;
      int num;
      cin >> num;

      if (tree.search(num)) {
	cout << num << " is in the tree" << endl;
      } else {
	cout << num << " is not in the tree" << endl;
      }
    } else if (strcmp(command, "PRINT") == 0) {
      cout << "visual representation of the tree" << endl;
      tree.print();
    } else if (strcmp(command, "QUIT") == 0) {
      break;
    } else {
      cout << "unknown command" << endl;
    }
  }
  return 0;
}
