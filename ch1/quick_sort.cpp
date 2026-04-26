#include <cstdlib>
#include <iostream>
#include <vector>

template<typename It>
size_t partition(It start, size_t l, size_t r){
  auto pivot{*(start+r)};
  size_t i{l};
  for(size_t j{l}; j<r; ++j){
    if(*(start+j)<=pivot){
      std::swap(*(start+j), *(start+i));
      ++i;
    }
  }
  std::swap(*(start+i), *(start+r));
  return i;
}

template<typename It>
void quickSortAux(It start, size_t l, size_t r){
  if(l>=r) return;
  size_t pivot_index{partition(start, l, r)};
  if (pivot_index>l+1)
    quickSortAux(start, l, pivot_index-1);
  if (pivot_index+1<r)
    quickSortAux(start, pivot_index+1, r);
}

template<typename It>
void quickSort(It start, It end){
  size_t n{static_cast<size_t>(end-start)};
  if(n<2) return;
  quickSortAux(start, 0, n-1);
}

int main(int argc, char** argv){
  size_t n;
  std::cin >> n;
  std::vector<int> a(n);
  for(size_t i{}; i<n; ++i) std::cin >> a[i];
  quickSort(a.begin(), a.end());
  for(size_t i{}; i<n; ++i) std::cout << a[i] << ' ';
  std::cout << std::endl;
  return EXIT_SUCCESS;
}

