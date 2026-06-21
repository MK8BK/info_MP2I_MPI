#include <cassert>
#include <cstdlib>
#include <limits>

struct BstNode {
  int data;
  BstNode *left, *right;
  BstNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

using Bst = BstNode *;

// Insert
void bstInsert(Bst &bst, int value) {
  if (!bst) {
    BstNode *newNode{new BstNode(value)};
    bst = newNode;
    return;
  }
  BstNode *parent{nullptr};
  BstNode *current{bst};
  while (current) {
    parent = current;
    if (current->data > value)
      current = current->left;
    else if (current->data < value)
      current = current->right;
    else // nothing to do, value already present
      return;
  }
  BstNode *newNode{new BstNode(value)};
  if (parent->data > value)
    parent->left = newNode;
  else
    parent->right = newNode;
}

// Search
BstNode* bstSearch(const Bst bst, int value){
    BstNode* current{bst};
    while(current){
        if(current->data > value){
            current = current->left;
        }else if(current->data < value){
            current = current->right;
        }else{
            return current;
        }
    }
    return nullptr;
}

// Delete
void bstDelete(Bst& bst, int value){
    if(!bst) return;
    // search for node and its parent
    BstNode* current{bst};
    BstNode* parent{nullptr};
    while(current){
        if(current->data > value){
            parent = current;
            current = current->left;
        }else if(current->data < value){
            parent = current;
            current = current->right;
        }else{
            break;
        }
    }
    if(!current) return; // not found
    if(!current->right && !current->left){
        if(!parent){
            bst = nullptr;
            delete current;
            return;
        }
        if(parent->data>value) parent->left = nullptr;
        else parent->right = nullptr;
        delete current;
        return;
    }
    if(!current->right){
        if(!parent){
            bst = current->left;
            delete current;
            return;
        }
        if(parent->data>value) parent->left = current->left;
        else parent->right = current->left;
        delete current;
        return;
    }
    if(!current->left){
        if(!parent){
            bst = current->right;
            delete current;
            return;
        }
        if(parent->data>value) parent->left = current->right;
        else parent->right = current->right;
        delete current;
        return;
    }
    // else both are present
    // get smallest from right subtree, and its parent
    BstNode* smallestRightParent{current};
    BstNode* smallestRight{current->right};
    while(smallestRight->left){
        smallestRightParent = smallestRight;
        smallestRight = smallestRight->left;
    }

    current->data = smallestRight->data;
    if(current==smallestRightParent)
        smallestRightParent->right = smallestRight->right;
    else
        smallestRightParent->left = smallestRight->right;
    delete smallestRight;
    return;
}

// Find Minimum
int getMinimum(const Bst& bst){
    Bst pbst{bst};
    while(pbst && pbst->left){
        pbst = pbst->left;
    }
    if(pbst)
        return pbst->data;
    else
        return std::numeric_limits<int>::max();
}


// Find Maximum
int getMaximum(const Bst& bst){
    Bst pbst{bst};
    while(pbst && pbst->right){
        pbst = pbst->right;
    }
    if(pbst)
        return pbst->data;
    else
        return std::numeric_limits<int>::min();
}

// Find Successor
// Find Predecessor
// Inorder Traversal
// Preorder Traversal
// Postorder Traversal
// Level-order Traversal
// Height Calculation
// Validate BST
// Find Parent
// Find Depth
// Find Lowest Common Ancestor (LCA)
// Count Nodes
// Count Leaf Nodes
// Count Internal Nodes
// Check Empty
// Clear Tree
// Mirror/Invert Tree
// Balance Check
// BST to Sorted Array
// Sorted Array to BST
// Range Query
// K-th Smallest Element
// K-th Largest Element
// Tree Copy/Clone
// Tree Equality Check
// Diameter Calculation
// Path Sum Queries

int main(int argc, char **argv) {
    Bst bst{};
    assert(!bstSearch(bst, 1));
    bstInsert(bst, 1);
    assert(bstSearch(bst, 1));
    bstDelete(bst, 1);
    assert(!bstSearch(bst, 1));
    bstInsert(bst, 3);
    bstInsert(bst, 2);
    assert(!bstSearch(bst, 1));
    return EXIT_SUCCESS;
}
