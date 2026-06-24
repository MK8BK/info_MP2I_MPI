#include <optional>
#include <vector>

class UnionFind {
  std::vector<int> parent;
public:
  explicit UnionFind(int n);
  // union is NOT a valid function name
  void unite(int x, int y);
  std::optional<int> find(int x);
};
UnionFind::UnionFind(int n) : parent(n, 0) {
  for (int i{}; i < n; ++i)
    parent[i] = i;
}
void UnionFind::unite(int x, int y) {
  std::optional<int> nxo{find(x)};
  std::optional<int> nyo{find(y)};
  if (!nxo || !nyo)
    return;
  // since there is path reduction, eh
  parent[nxo.value()] = nyo.value();
}
std::optional<int> UnionFind::find(int x) {
  if (x >= static_cast<int>(parent.size()) || x < 0)
    return {};
  int r{x};
  while (r != parent[r])
    r = parent[r];
  // path reduction
  int next;
  while (x != r) {
    next = parent[x];
    parent[x] = r;
    x = next;
  }
  return r;
}
