#include <iostream>

#include "tree.cpp"

using namespace std;
using namespace tree;

int main() {
  node *root = nullptr;
  string str, op;
  while (true) {
    cout << "[I]nserir\n[C]onsultar\n[S]air\n";
    cout << "Escolha uma opção: ";
    cin >> op;
    if(op=="s" || op=="S") break;

    cout << "Valor: ";
    cin >> str;
    if(op=="i" || op=="I"){
        insert_bst(root, str);
        traversal_in(root);
        cout << endl;
    }
    else if(op=="C" || op=="c"){
        node *p = search_bst(root, str);
        if(p) cout << "Achou!\n";
        else  cout << "Não achou!\n";
    }
  }
}
