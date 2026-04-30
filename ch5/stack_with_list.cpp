#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
using namespace std;

typedef struct stack{
  int data;
  struct stack* pred;
} Stack;

void push(Stack **p, int i){
  Stack* newP{new Stack};
  newP->data = i;
  newP->pred = *p;
  *p = newP;
}

int pop(Stack **p){
  if(p==nullptr)
    throw runtime_error("[Can't pop from empty stack]\n");
  Stack *t{(*p)->pred};
  int x{(*p)->data};
  free(*p);
  *p = t;
  return x;
}

int main(int argc, char** argv){
  vector<int> a{{1,2,3,4,5}};
  Stack *p{nullptr};
  for(int i : a)
    push(&p, i);
  while(p!=nullptr)
    cout << pop(&p) << ' ';
  cout << endl;
  return EXIT_SUCCESS;
}
