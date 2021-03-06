#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int> > res;
    vector<int> nodes(n);
    vector<vector<int> > groups(n);

    for(int i = 0; i < n; ++i){
        nodes[i] = i;
        groups[i].push_back(i);
    }

    for(int i = 0; i < m; ++i){
        int k, l;
        cin >> k >> l;
        if(nodes[k - 1] != nodes[l - 1]){
            int l_gr = nodes[k - 1];
            int m_gr = nodes[l - 1];
            if(groups[l_gr].size() > groups[m_gr].size()){
                swap(l_gr, m_gr);
            }

            groups[m_gr].insert(
                groups[m_gr].end(),
                groups[l_gr].begin(),
                groups[l_gr].end()
            );

            for(int j = 0; j < groups[l_gr].size(); ++j){
                nodes[groups[l_gr][j]] = m_gr;
            }

            res.push_back(make_pair(k, l));
            if(res.size() == (n - 1)){
                break;
            }
        }
    }

    for(int i = 0; i < (n - 1); ++i){
        cout << res[i].first << " " << res[i].second << "\n";
    }
}
