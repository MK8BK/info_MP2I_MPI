#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template<typename T, size_t maxSize>
class Queue{
private:
  // push on the head, pop from the tail
  size_t front, rear, size;
  array<T, maxSize> storage;
public:
  Queue() : front(0), rear(maxSize-1), size(0){}
  void enqueue(T t){
    if(size==maxSize) throw runtime_error("[can't enqueue on full queue]\n");
    rear = (rear+1)%maxSize;
    ++size;
    storage[rear] = t;
  }
  T dequeue(){
    if(size==0) throw runtime_error("[can't dequeue on empty queue]\n");
    T data{storage[front]};
    front = (front+1)%maxSize;
    --size;
    return data;

  }
  T peak() const {
    if(size==0) throw runtime_error("[can't peak on empty stack]\n");
  }
  bool isEmpty() const {
    return size==0;
  }
};

int main(int argc, char** argv){
  Queue<int, 50> s;
  vector<int> a{{1, 2, 3, 4, 5, 6, 7}};
  for(int i : a)
    s.enqueue(i);
  while(!s.isEmpty())
    cout << s.dequeue() << ' ';
  cout << endl;
  return EXIT_SUCCESS;
}
