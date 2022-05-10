#include <iostream>

#include "tree.cpp"

using namespace std;
using namespace tree;

int main() {
  node *root = new_node("A");
  root->left = new_node("B");
  root->left->left = new_node("G");
  root->right = new_node("C");
  root->right->left = new_node("E");
  root->right->right = new_node("F");
  root->right->right->left = new_node("H");

  node *p = tree::search(root, "E");
  if (p != nullptr)
    p->left = new_node("I");
  else
    cout << "Not found!" << endl;

  show(root);
}
