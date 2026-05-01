#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class BST{
  typedef struct node {
    int val;
    struct node* parent;
    struct node* left;
    struct node* right;
  } Node;
  Node* root;
  bool recContainsHelper(Node* n, int value){
    if(!n) return false;
    if(n->val==value) return true;
    if(value>n->val) return recContainsHelper(n->right, value);
    else return recContainsHelper(n->left, value);
  }
  template<typename F>
  void inorderDoHelper(Node* n, F f) const {
    if(!n) return;
    inorderDoHelper(n->left, f);
    f(n->val);
    inorderDoHelper(n->right, f);
  }
  template<typename F>
  void postorderDoHelper(Node* n, F f) const {
    if(!n) return;
    postorderDoHelper(n->left, f);
    postorderDoHelper(n->right, f);
    f(n->val);
  }
  template<typename F>
  void preorderDoHelper(Node* n, F f) const {
    if(!n) return;
    f(n->val);
    preorderDoHelper(n->left, f);
    preorderDoHelper(n->right, f);
  }
public:
  BST():root(nullptr){}
  bool recContains(int value){
    return recContainsHelper(root, value);
  }

  template<typename F>
  void inorderDo(F f) const {
    inorderDoHelper(root, f);
  }
  template<typename F>
  void postorderDo(F f) const {
    postorderDoHelper(root, f);
  }
  template<typename F>
  void preorderDo(F f) const {
    preorderDoHelper(root, f);
  }
  bool iterContains(int value){
    Node *x{root};
    while(x && x->val!=value){
      if(value<x->val)
        x = x->left;
      else
        x = x->left;
    }
    return x!=nullptr;

  }
  void insert(int value){
    Node *z{new Node(value, nullptr, nullptr, nullptr)};
    Node *y{nullptr};
    Node *x{root};
    while(x){
      y = x;
      if(y->val == value) return;
      if(value<x->val)
        x = x->left;
      else
        x = x->right;
    }
    z->parent = y;
    if(!y)
      root = z;
    else if(value < y->val)
      y->left = z;
    else
      y->right = z;
  }
};

int main(int argc, char** argv){
  BST bst;
  vector<int> a({5,7,3,2,4,6,8,1,9,10});
  for(int x : a)
    bst.insert(x);
  for(int i{-5}; i<16; ++i)
    cout << i << ' ' << bst.recContains(i) << '\n';
  auto print = [](const int n){cout << n << ' ';};
  bst.inorderDo(print);
  cout << endl;
  bst.preorderDo(print);
  cout << endl;
  bst.postorderDo(print);
  cout << endl;

  return EXIT_SUCCESS;
}
