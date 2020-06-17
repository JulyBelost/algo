#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int reach(vector<vector<int> > &adj, int x, int y) {
    vector<int> checked(adj.size(), 0);
    queue<int> vq;
    vq.push(x);
    while(!vq.empty()) {
        int t = vq.front();
        if(checked[t] == 0) {
            checked[t] = 1;
            for(int i: adj[t]){
                vq.push(i);
            }
        }
        vq.pop();
    }

    return checked[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
