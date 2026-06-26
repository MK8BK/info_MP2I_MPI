#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

// **
// Given n points on a line, find the minimum number of intervals of size 1
// that covers all points
//

size_t minIntervalCover(std::vector<double>& e){
  size_t  count{};
  double rightBound;
  size_t i{0};
  const size_t n{e.size()};
  std::sort(e.begin(), e.end());
  while(i<n){
    ++count;
    rightBound = e[i]+1.0;
    while(i<n && e[i]<=rightBound) ++i;
  }
  return count;
}


int main(){
  const int n{30};
  std::vector<double> e(n);
  srand(time(nullptr));
  for(int i{}; i<n; ++i)
    e[i] = ((rand()%100)/100.0)*(rand()%50);
  for(int i{}; i<n; ++i) std::cout << e[i] << ' ';
  size_t mN{minIntervalCover(e)};
  std::cout << '\n' << mN << std::endl;
  return EXIT_SUCCESS;
}
