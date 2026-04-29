#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template<typename T>
class Stack{
private:
  size_t size;
  vector<T> storage;
public:
  Stack() : size(0), storage(1){}
  void push(T t){
    if(size==storage.size()){
      storage.push_back(t);
      ++size;
    }else{
      storage[size++] = t;
    }
  }
  T pop(){
    if(size==0) throw runtime_error("[can't pop from empty stack]\n");
    return storage[--size];
  }
  T peak() const {
    if(size==0) throw runtime_error("[can't peak on empty stack]\n");
    return storage[size-1];
  }
  bool isEmpty() const {
    return size==0;
  }
};

int main(int argc, char** argv){
  Stack<int> s;
  vector<int> a{{1, 2, 3, 4, 5, 6, 7}};
  for(int i : a)
    s.push(i);
  while(!s.isEmpty())
    cout << s.pop() << ' ';
  cout << endl;
  return EXIT_SUCCESS;
}
