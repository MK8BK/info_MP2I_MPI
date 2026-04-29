#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
using namespace std;

typedef struct pile{
  int data;
  struct pile* pred;
} Pile;

void push(Pile **p, int i){
  Pile* newP{new Pile};
  newP->data = i;
  newP->pred = *p;
  *p = newP;
}

int pop(Pile **p){
  if(p==nullptr)
    throw runtime_error("[Can't pop from empty stack]\n");
  Pile *t{(*p)->pred};
  int x{(*p)->data};
  free(*p);
  *p = t;
  return x;
}

int main(int argc, char** argv){
  vector<int> a{{1,2,3,4,5}};
  Pile *p{nullptr};
  for(int i : a)
    push(&p, i);
  while(p!=nullptr)
    cout << pop(&p) << ' ';
  cout << endl;
  return EXIT_SUCCESS;
}
