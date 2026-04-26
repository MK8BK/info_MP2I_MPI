#include <iostream>
#include <cstdlib>

int pgcd(int a, int b){
  if(a<=0 || b<=0) return -1;
  if(a<b)
    std::swap(a, b);
  int t;
  while(b>0){
    t = a;
    a = b;
    b = t%b;
  }
  return a;
}

int main(int argc, char** argv){
  int a, b;
  std::cin >> a >> b;
  int p{pgcd(a,b)};
  std::cout << p << std::endl;
  return EXIT_SUCCESS;
}

