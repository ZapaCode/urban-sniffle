#include <iostream>

#include "tree.cpp"

using namespace std;
using namespace tree;

int main() {
  node *root = nullptr;
  string str;
  while (true) {
    if (root == nullptr) {
      cout << "Inserir: ";
      cin >> str;
      root = new_node(str);
    } else {
      cout << "Pesquisar: ";
      cin >> str;
      node *p = tree::search(root, str);
      if (!p)
        cout << "Não encontrou!\n";
      else {
        string lr;
        cout << "Inserir: ";
        cin >> str;
        cout << "[E]squerda/[D]ireita? ";
        cin >> lr;
        if (lr == "e" || lr == "E") {
          if (p->left == nullptr)
            p->left = new_node(str);
          else
            cout << "Ocupado!\n";
        } else {
          if (p->right == nullptr)
            p->right = new_node(str);
          else
            cout << "Ocupado!\n";
        }
      }
    }
    show(root);

    cout << "Continuar? [S]im/[N]ão: ";
    cin >> str;
    if (str == "N" || str == "n") break;
  }
}
