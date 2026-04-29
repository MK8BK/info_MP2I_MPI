#include <iostream>
#include <cstdlib>
#include <vector>
#include <optional>
#include <iterator>
#include <type_traits>
using namespace std;

template<typename It, typename V>
  requires forward_iterator<It> && is_same<typename It::value_type, V>::value
optional<V> majorityElement(It start, It end)// -> optional<typename It::value_type>
{
  if(start==end) return nullopt;
  if(end-start==1) return *start;
  It copyStart{start};
  V candidate;
  size_t counter{};
  size_t n{};
  while(start!=end){
    ++n;
    if(!counter){
      candidate = *start;
      ++counter;
    }else{
      if(*start==candidate) ++counter;
      else --counter;
    }
    ++start;
  }
  counter = 0;
  while(copyStart!=end){
    if(*copyStart==candidate) ++counter;
    ++copyStart;
  }
  if(counter>n/2) return optional(candidate);
  return nullopt;
}
// template<typename It, typename V>
//   requires forward_iterator<It> && is_same<typename It::value_type, V>::value
// optional<V> majorityElement(It start, It end) -> optional<typename It::value_type>;

int main(){
  unsigned int n;
  cout << "Enter array size then elements:" << endl;
  cin >> n;
  vector<int> a(n);
  for(unsigned int i{}; i<n; ++i) cin >> a[i];
  optional<int> maj{majorityElement<decltype(a.begin()), int>(a.begin(), a.end())};
  if(maj)
    cout << "Majority element exists and is " << maj.value() << '\n';
  else
    cout << "Majority element does not exist\n";

  return EXIT_SUCCESS;
}
