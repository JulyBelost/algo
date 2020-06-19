#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int acyclic(vector<vector<int> > &adj) {
    int n = adj.size();
    vector<int> checked(n, 0);
    for(int i = 0; i < n; ++i){
        if(checked[i] != 0){
            continue;
        }
        stack<int> path;
        path.push(i);
        checked[i] = 1;
        while(!path.empty()){
            int cur = path.top();
            if(adj[cur].empty()){
                checked[cur] = 2;
                path.pop();
            } else {
                int next = adj[cur].back();
                if(checked[next] == 1) {
                    return 1;
                } else if (checked[next] == 0) {
                    checked[next] = 1;
                    path.push(next);
                }
                adj[cur].pop_back();
            }
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
