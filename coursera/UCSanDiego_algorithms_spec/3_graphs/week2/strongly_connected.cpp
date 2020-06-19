#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>> & adj, vector<int> & used, vector<int> & order, int v) {
    if(used[v] != 0) {
        return;
    }

    used[v] = 1;

    for(int i = 0; i < adj[v].size(); ++i){
        dfs(adj, used, order, adj[v][i]);
    }

    order.push_back(v);
}

int number_of_strongly_connected_components(vector<vector<int> > adj, vector<vector<int> > rev_adj) {
  int result = 0;
  int n = adj.size();
  vector<int> used(n, 0);
  vector<int> order;

  for(int v = 0; v < n; ++v) {
      if(used[v] != 0) {
          continue;
      }

      dfs(rev_adj, used, order, v);
  }

  fill(used.begin(), used.end(), 0);

  for(int i = n - 1; i >= 0; --i){
      if(used[order[i]] != 0) {
          continue;
      }

      dfs(adj, used, order, order[i]);
      ++result;
  }

  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > rev_adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    rev_adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_strongly_connected_components(adj, rev_adj);
}
