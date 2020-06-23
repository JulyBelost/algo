#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inf = INT32_MAX;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    vector<pair<int, int>> d(adj.size(), inf);
    vector<pair<int, int>> p(adj.size(), -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> unprocessed;
    int n = adj.size(), j = 0, v, w;

    unprocessed.push({0, s});
    while(!unprocessed.empty() && j < n) {
        pair<int,int> cur = unprocessed.top();
        unprocessed.pop();

        v = cur.second;
        int v_path = cur.first;

        if(v_path > d[v]) {
            continue;
        }
        
        for(int i = 0; i < adj[v].size(); ++i) {
            int new_path = v_path + cost[v][i];
            int w = adj[v][i];

            if(new_path < d[w]) {
                unprocessed.push({new_path, w});
                d[w] = new_path;
                p[w] = v;
            }
        }
        ++j;
    }

    return (paths[t].first == inf ? -1 : paths[t].first);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }

    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
