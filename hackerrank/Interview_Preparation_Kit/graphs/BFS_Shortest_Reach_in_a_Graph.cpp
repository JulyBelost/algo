#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

const int inf = INT_MAX;

class Graph {
    vector<vector<int>> nodes;

    public:
        Graph(int n) {
            nodes.resize(n);
        }

        void add_edge(int u, int v) {
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {
            vector<int> dist(nodes.size(), inf);
            queue<pair<int, int> > neighs;
            neighs.push(make_pair(start, 0));
            while(!neighs.empty()){
                int top = neighs.front().first;
                int rank = neighs.front().second;

                neighs.pop();

                for(int  i = 0; i < nodes[top].size(); ++i){
                    int neig = nodes[top][i];
                    if(dist[neig] == inf){
                        neighs.push(make_pair(neig, rank + 1));
                        dist[neig] = (rank + 1) * 6;
                    }
                }
            }

            return dist;
        }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << (distances[i] == inf ? -1 :  distances[i]) << " ";
            }
        }


        cout << endl;
    }

    return 0;
}
