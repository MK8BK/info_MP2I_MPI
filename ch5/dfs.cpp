#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename F>
void dfs(const vector<vector<int>> &graph, int start, F f) {
  int n{static_cast<int>(graph.size())};
  std::vector<bool> visited(n, false);
  std::stack<int> s;
  s.push(start);
  visited[start] = true;
  int v;
  while (!s.empty()) {
    v = s.top();
    s.pop();
    f(v);
    for (int i{}; i < n; ++i)
      if (!visited[i] && graph[v][i] != 0) {
        s.push(i);
        visited[i] = true;
      }
  }
}

int main() {
  int n{8};
  vector<vector<int>> g(n, vector<int>(n, 0));
  g[0][1] = g[0][2] = g[1][3] = g[2][3] = g[3][4] = g[3][5] = g[5][7] =
      g[4][6] = g[6][7] = 1;
  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j)
      cout << g[i][j] << ' ';
    cout << '\n';
  }
  auto f = [](const int i) { std::cout << i << " <--- working on it \n"; };
  dfs<decltype(f)>(g, 0, f);

  return EXIT_SUCCESS;
}
