#include <iostream>
#include <cstdlib>
using namespace std;
using UI = unsigned int;

UI mult(UI m, UI n){
  if(m==0 || n==0) return 0;
  if(m==1) return n;
  else return n+mult(m-1, n);
}

int main(int argc, char** argv){
  UI n, m;
  cin >> n >> m;
  cout << mult(n, m) << endl;
  return EXIT_SUCCESS;
}

