#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
  int a, b;
  cin >> a >> b;
  int q{}, r{a};
  while(r>=b)
    r -= b, ++q;
  cout << q << ' ' << r << endl;
  return EXIT_SUCCESS;
}
