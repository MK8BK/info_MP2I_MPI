#include <iostream>
#include <cstdlib>
using namespace std;
using UI = unsigned int;

// move n blocks from t1 to t3 using intermediate block t2
void hanoiRec(UI n, UI t1, UI t2, UI t3){
  if(n==0) return;
  if(n==1)
    cout << "Moving one block from " << t1 << " to " << t3 << '\n';
  else{
    hanoiRec(n-1, t1, t3, t2);
    cout << "Moving one block from " << t1 << " to " << t3 << '\n';
    hanoiRec(n-1, t2, t1, t3);
  }
}

int main(int argc, char** argv){
  UI n;
  cin >> n;
  hanoiRec(n, 1, 2, 3);
  return EXIT_SUCCESS;
}

