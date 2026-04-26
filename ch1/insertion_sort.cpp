#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

template<typename It>
void insertion_sort(It start, It end){
  size_t n{static_cast<size_t>(end-start)}, i{}, j;
  if(n<2) [[unlikely]] return;
  while(i<n-1){
    j = i+1;
    while(j>0 && *(start+j)<*(start+j-1)){
      std::swap(*(start+j), *(start+j-1));
      --j;
    }
    ++i;
  }
}

int main(int argc, char** argv){
  size_t n;
  std::cin >> n;
  std::vector<int> a(n);
  for(size_t i{}; i<n; ++i) std::cin >> a[i];
  insertion_sort(a.begin(), a.end());
  for(size_t i{}; i<n; ++i) std::cout << a[i] << ' ';
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
