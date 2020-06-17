#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number_of_components(vector<vector<int> > &adj) {
    int n  =adj.size();
    vector<int> checked(n, 0);
    int res = 0;

    for(int i = 0; i < n; ++i) {
        if(checked[i] == 1) {
            continue;
        }
        ++res;
        queue<int> vq;
        vq.push(i);
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
    }

    return res;
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
  std::cout << number_of_components(adj);
}
