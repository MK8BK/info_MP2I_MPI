#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
using namespace std;

typedef struct queue{
  int data;
  struct queue* succ;
} Queue;

void enqueue(Queue** f, int val){
  if(f==nullptr) throw runtime_error("Can't enqueue on null queue.");
  Queue *nf{new Queue};
  if(nf==nullptr) throw runtime_error("Could not allocate memory.");
  nf->data = val;
  if(*f==nullptr)
    nf->succ = nf;
  else{
    nf->succ = (*f)->succ;
    (*f)->succ = nf;
  }
  *f = nf;
}

int dequeue(Queue** f){
  if(*f==nullptr)
    throw runtime_error("Can't enqueue on null queue.");
  Queue *oldF{(*f)->succ};
  int x{oldF->data};
  if(oldF == *f)
    *f = nullptr;
  else
    (*f)->succ = (*f)->succ->succ;
  free(oldF);
  return x;
}


int main(int argc, char** argv){
  vector<int> a{{1,2,3,4,5}};
  Queue *f{nullptr};
  for(int i : a)
    enqueue(&f, i);
  while(f!=nullptr)
    cout << dequeue(&f) << ' ';
  cout << endl;
  return EXIT_SUCCESS;
}
