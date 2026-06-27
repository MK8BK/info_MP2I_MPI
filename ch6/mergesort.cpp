#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

template <std::random_access_iterator It>
void merge(const std::iter_difference_t<It> l,
           const std::iter_difference_t<It> m,
           const std::iter_difference_t<It> r,
           std::vector<std::iter_value_t<It>> &cache, It start) {
  std::iter_difference_t<It> lp{l}, rp{m}, cp{l};
  while (rp < r && lp < m) {
    if (*(start + lp) <= *(start + rp)) {
      cache[cp] = *(start + lp);
      ++lp;
    } else {
      cache[cp] = *(start + rp);
      ++rp;
    }
    ++cp;
  }
  while (rp < r) {
    cache[cp] = *(start + rp);
    ++rp, ++cp;
  }
  while (lp < m) {
    cache[cp] = *(start + lp);
    ++lp, ++cp;
  }
  for (std::iter_difference_t<It> i{l}; i < r; ++i)
    *(start + i) = cache[i];
}

// convention used: right bound excluded
template <std::random_access_iterator It>
void aux(const std::iter_difference_t<It> l, const std::iter_difference_t<It> r,
         std::vector<std::iter_value_t<It>> &cache, It start) {
  if (r - l < 2)
    return;
  std::iter_difference_t<It> m{l + (r - l) / 2};
  aux(l, m, cache, start);
  aux(m, r, cache, start);
  merge(l, m, r, cache, start);
}

template <std::random_access_iterator It> void mergeSort(It start, It end) {
  const auto n{end - start};
  std::vector<std::iter_value_t<It>> cache(n);
  aux(0, n, cache, start);
}

int main() {
  using namespace std;
  const int n{50};
  srand(time(nullptr));
  std::vector<int> v(n);
  for (int i{}; i < n; ++i)
    v[i] = rand() % 100;

  for (int i{}; i < n; ++i)
    cout << v[i] << ' ';
  cout << '\n';

  mergeSort(v.begin(), v.end());

  for (int i{1}; i < n; ++i)
    if (v[i] < v[i - 1]) {
      cout << "Not sorted" << endl;
      break;
    }
  return EXIT_SUCCESS;
}
