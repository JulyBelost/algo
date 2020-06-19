#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int go_node(const vector<vector<int> > &adj, vector<int> & checked, int i) {
    if(checked[i] == 1) {
        return 1;
    }
    if(checked[i] == 2) {
        return 0;
    }
    checked[i] = 1;

    for(int j = 0; j < adj[i].size(); ++j){
        if(go_node(adj, checked, adj[i][j]) == 1){
            return 1;
        }
    }
    checked[i] = 2;

    return 0;
}

int acyclic(const vector<vector<int> > &adj) {
    int n = adj.size();
    vector<int> checked(n, 0);
    for(int i = 0; i < n; ++i){
        if(checked[i] != 0){
            continue;
        }
        if(go_node(adj, checked, i) == 1){
            return 1;
        }
    }

    return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
