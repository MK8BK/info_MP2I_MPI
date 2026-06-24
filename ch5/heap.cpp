#include <cstdlib>
#include <iostream>
#include <optional>
#include <unordered_map>
#include <vector>

class Heap {
  std::vector<int> data;
  std::unordered_map<int, int> valToIndex;
  void up(int index);
  void down(int index);
public:
  Heap() : data(), valToIndex() {}
  void push(int val);
  std::optional<int> pop();
};
std::optional<int> Heap::pop() {
  if (data.empty())
    return {};
  int root{data[0]};
  valToIndex.erase(data[0]);
  int val{*data.rbegin()};
  data.pop_back();
  int n{static_cast<int>(data.size())};
  if (n >= 1) {
    data[0] = val;
    valToIndex[val] = 0;
    down(0);
  }
  return root;
}
void Heap::down(int i) {
  int val{data[i]};
  int left, right;
  int n{static_cast<int>(data.size())};
  while (true) {
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (right < n && data[right] < val && data[right] < data[left]) {
      data[i] = data[right];
      valToIndex[data[right]] = i;
      i = right;
    } else if (left < n && data[left] < val) {
      data[i] = data[left];
      valToIndex[data[left]] = i;
      i = left;
    } else {
      data[i] = val;
      valToIndex[val] = i;
      return;
    }
  }
}
void Heap::up(int index) {
  int val{data[index]};
  while (index > 0 && val < data[(index - 1) / 2]) {
    data[index] = data[(index - 1) / 2];
    valToIndex[data[(index - 1) / 2]] = index;
    index = (index - 1) / 2;
  }
  data[index] = val;
  valToIndex[val] = index;
}
void Heap::push(int val) {
  if (static_cast<int>(data.size()) == 0) {
    data.push_back(val);
    valToIndex[val] = 0;
    return;
  }
  if (valToIndex.contains(val))
    return;
  data.push_back(val);
  valToIndex[val] = static_cast<int>(data.size() - 1);
  up(static_cast<int>(data.size() - 1));
}

int main() {
  Heap h;
  for (int i{20}; i >= 0; --i)
    h.push(i);
  auto f = []() { std::cout << "Empty\n"; };
  for (int i{}; i < 21; ++i) {
    std::optional<int> r{h.pop()};
    if (r)
      std::cout << r.value() << '\n';
    else
      f();
  }
  return EXIT_SUCCESS;
}
