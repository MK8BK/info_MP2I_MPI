#include <iostream>
#include <cstdlib>
using namespace std;

bool paire(unsigned int n);
bool impaire(unsigned int n);

bool paire(unsigned int n){
  if(n==0) return true;
  else return impaire(n-1);
}

bool impaire(unsigned int n){
  if(n==0) return false;
  else return paire(n-1);
}

int main(int argc, char** argv){
  unsigned int  n;
  cin >> n;
  cout << paire(n) << endl;
  cout << impaire(n) << endl;
  return EXIT_SUCCESS;
}
