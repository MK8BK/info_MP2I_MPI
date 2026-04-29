#include <iostream>
#include <cstdlib>

int pgcdv2(int a, int b){
  if(a<=0 || b<=0) return -1;
  while(a!=b){
    if(a>b) a = a - b;
    else b = b - a;
  }
  return a;
}

int main(int argc, char** argv){
  int a, b;
  std::cin >> a >> b;
  int p{pgcdv2(a,b)};
  std::cout << p << std::endl;
  return EXIT_SUCCESS;
}

