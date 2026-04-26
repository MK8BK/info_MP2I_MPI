#include <iostream>
#include <algorithm>
#include <vector>

template<typename It>
void selection_sort(It start, It end){
  if(start==end) [[unlikely]] return;
  // assume start and end are proper iterators with start<end
  size_t n{static_cast<size_t>(end-start)}, i{}, j;
  while(i<n-1){
    j = i;
    for(size_t k{i}; k<n; ++k)
      if(*(start+k)<*(start+j))
        j = k;
    std::swap(*(start+j), *(start+i));
    ++i;
  }
}

int main(int argc, char** argv){
  size_t n;
  std::cin >> n;
  std::vector<int> a(n);
  for(size_t k{}; k<n; ++k) std::cin >> a[k];
  selection_sort(a.begin(), a.end());
  for(size_t k{}; k<n; ++k) std::cout << a[k] << ' ';
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
