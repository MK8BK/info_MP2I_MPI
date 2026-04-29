#include <iostream>
#include <cstdlib>
using namespace std;

size_t factIter(unsigned int n){
  size_t res{1};
  while(n){
    res *= n;
    --n;
  }
  return res;
}

size_t factRec(unsigned int n){
  if(n) return n * factRec(n-1);
  else return 1;
}

int main(int argc, char** argv){
  unsigned int n;
  cin >> n;
  cout << factIter(n) << endl;
  cout << factRec(n) << endl;
  return EXIT_SUCCESS;
}

