#include <iostream>
#include <cstdlib>
using namespace std;


double fastExpRec(double x, unsigned int n){
  if(n==0) return 1.0;
  double y;
  if(n%2==0){
    y = fastExpRec(x, n/2);
    return y*y;
  }else{// not necessary but eh
    y = fastExpRec(x, (n-1)/2);
    return y*y*x;
  }
}

double fastExpIter(double x, unsigned int n){
  if(n==0) return 1.0;
  double y{1.0};
  while(n>1){
    if(n%2!=0)
      y = x*y, --n;
    x = x*x;
    n /= 2;
  }
  return x*y;
}

int main(int argc, char** argv){
  double x;
  unsigned int n;
  cin >> x >> n;
  cout << fastExpRec(x, n) << endl;
  cout << fastExpIter(x, n) << endl;

  return EXIT_SUCCESS;
}
