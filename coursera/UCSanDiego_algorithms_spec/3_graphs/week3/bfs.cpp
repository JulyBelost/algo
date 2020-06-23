#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
    queue<pair<int, int>> vq;
    vector<int> checked(adj.size(), 0);
    vq.push({s, 0});

    while(!vq.empty()) {
        pair<int,int> cur = vq.front();
        vq.pop();
        for(int i = 0; i < adj[cur.first].size(); ++i) {
            if(adj[cur.first][i] == t) {
                return cur.second + 1;
            }
            if(checked[adj[cur.first][i]] == 0) {
                vq.push({adj[cur.first][i], cur.second + 1});
                checked[adj[cur.first][i]] = 1;
            }
        }
    }

    return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
