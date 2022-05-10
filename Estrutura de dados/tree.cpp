#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace tree {

struct node {
  string value;
  node *left, *right;
};

node *new_node(const string &s) {
  node *p = new node;
  p->value = s;
  p->left = p->right = nullptr;
  return p;
}

void show(node *p, int level = 0, const string &prefix = "√") {
  if (p == nullptr) return;

  string ident(3 * level, ' ');
  cout << ident << prefix << p->value << endl;

  show(p->left, level + 1, "↙");
  show(p->right, level + 1, "↘");
}

int height(node *p) {
  if (p == nullptr) return -1;

  return max(height(p->left), height(p->right)) + 1;
}

void traversal_pre(node *p) {
  if (!p) return;

  cout << p->value << " ";
  traversal_pre(p->left);
  traversal_pre(p->right);
}

void traversal_in(node *p) {
  if (!p) return;

  traversal_in(p->left);
  cout << p->value << " ";
  traversal_in(p->right);
}

void traversal_pos(node *p) {
  if (!p) return;

  traversal_pos(p->left);
  traversal_pos(p->right);
  cout << p->value << " ";
}

void recursive_breadth(node *p, vector<string> &values) {
  if (p == nullptr) return;

  if (p->left != nullptr) values.push_back(p->left->value);

  if (p->right != nullptr) values.push_back(p->right->value);

  recursive_breadth(p->left, values);
  recursive_breadth(p->right, values);
}

void traversal_breadth(node *p) {
  vector<string> values;
  if (p != nullptr) {
    values.push_back(p->value);
    recursive_breadth(p, values);
  }
  for (auto s : values) cout << s << " ";
}

node *search(node *p, const string &s) {
  if (p == nullptr) return nullptr;
  if (p->value == s) return p;

  node *pl = tree::search(p->left, s);
  if (pl != nullptr) return pl;

  return tree::search(p->right, s);
}

// TODO
void insert_bst(node *&p, const string &s) {
  if (p == nullptr)
    p = new_node(s);
  else if (s < p->value)
    insert_bst(p->left, s);
  else
    insert_bst(p->right, s);
}

node *search_bst(node *p, const string &s) {
  if (!p) return nullptr;
  if (p->value == s)
    return p;
  else if (s < p->value)
    return search_bst(p->left, s);
  else
    search_bst(p->right, s);
}
}  // namespace tree
