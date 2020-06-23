#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bipartite(vector<vector<int> > &adj) {
    queue<pair<int, int>> vq;
    vector<int> colour(adj.size(), 0);

    vq.push({0, 0});
    colour[0] = 1;
    while(!vq.empty()){
        pair<int,int> cur = vq.front();
        vq.pop();

        for(int i = 0; i < adj[cur.first].size(); ++i) {
            if(colour[adj[cur.first][i]] == colour[cur.first]) {
                return 0;
            }
            if(colour[adj[cur.first][i]] == 0) {
                vq.push({adj[cur.first][i], cur.second + 1});
                colour[adj[cur.first][i]] = -colour[cur.first];
            }
        }
    }

    return 1;
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

  std::cout << bipartite(adj);
}
