#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template<typename It, typename V>
bool binsearch_v1(It start, It end, V query)
requires std::is_same_v<typename It::value_type, V>
{
  if(!(end-start)) return false;
  It mid;
  while(start<end){
    mid = start + (end-start)/2;
    if(*mid>query)
      end = mid;
    else
      start = mid+1;
  }
  return *mid==query;
}

template<typename It, typename V>
bool binsearch_v2(It start, It end, V query)
requires std::is_same_v<typename It::value_type, V>
{
  auto n{end-start};
  if(!n) return false;
  decltype(n) offset{};
  for(auto step{n/2}; step>=1; step/=2)
    while(step+offset<n && *(start+offset+step)<=query)
      offset += step;
  return *(start+offset)==query;
}

int main(int argc, char* argv[]){
  int n;
  cout << "Enter the size of the array followed by the array values\n";
  cin >> n;
  vector<int> a(n);
  for(int i{}; i<n; ++i) cin >> a[i];
  int q;
  cout << "Enter query number: ";
  while(cin >> q){
    if(binsearch_v2(a.begin(), a.end(), q))
      cout << q << " found in array" << endl;
    else
      cout << q << " not found in array" << endl;
    cout << "Enter query number: ";
  }
  return EXIT_SUCCESS;
}

