#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


class RedBlackTree{
  enum class Color{
    RED, BLACK
  };
  typedef struct Node {
    Color c;
    Node* parent;
    Node *left, *right;
    int val;
  } Node;
  Node* root;

  Node* search(int value) const {
    Node *n{root};
    while (n!=nullptr) {
      if (n->val==value) return n;
      if (n->val>value) n = n->left;
      else n = n->right;
    }
    return nullptr;
  }

  void rotateLeft(int value){
    Node* x{search(value)};
    if (!x || !(x->right)) throw runtime_error("Can't rotate node.");
    Node *y{x->right};
    Node *beta{y->left};
    Node* oldParent{x->parent};
    if (oldParent) {
      if (oldParent->val > x->val) // was left node
        oldParent->left = y;
      else // was right node
        oldParent->right = y;
      y->parent = oldParent;
    }else // is root
      root = y;
    x->parent = y;
    beta->parent = x;
    x->right = beta;
    y->left = x;
  }

  void rotateRight(int value){
    Node* y{search(value)};
    if (!y || !(y->left)) throw runtime_error("Can't rotate node.");
    Node *x{y->left};
    Node *beta{x->right};
    Node* oldParent{y->parent};
    if (oldParent) {
      if (oldParent->val > y->val) // was left node
        oldParent->left = x;
      else // was right node
        oldParent->right = x;
      x->parent = oldParent;
    }else // is root
      root = x;
    y->parent = x;
    beta->parent = y;
    y->left = beta;
    x->right = y;
  }
  void insertFixup(Node* z) {
    // z is not nullptr, see insert below
    while (z->parent->c == Color::RED) {
      if (z->p==z->p->p)
    }
  }
  public:
  RedBlackTree():root(nullptr){}
  void insert(int value) {
    Node* y{nullptr};
    Node* x{root};
    Node *z{new Node(Color::RED, nullptr, nullptr, nullptr, value)};
    while(x) {
      y = x;
      if (value<x->val)
        x = x->left;
      else
        x = x->right;
    }
    z->parent = y;
    if (!y) {
      root = z, z->c = Color::BLACK;
      return;
    }
    if (value<y->val)
      y->left = z;
    else
      y->right = z;
    insertFixup(z);
  }
  bool contains(int value) const {
    return true;
  }

};

int main(int argc, char** argv){
  return EXIT_SUCCESS;
}
