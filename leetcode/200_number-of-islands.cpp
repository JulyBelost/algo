// https://leetcode.com/problems/number-of-islands/

void explore_island(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& flags){
    queue<pair<int, int> > q;
    pair<int, int> d[] = {make_pair(0, 1), make_pair(0, -1), make_pair(-1, 0), make_pair(1, 0)};
    q.push(make_pair(i,j));
    while(!q.empty()){
        int k = q.front().first;
        int m = q.front().second;
        q.pop();
        for(int l = 0; l < 4; ++l){
            int k_sh = k + d[l].first;
            int m_sh = m + d[l].second;
            if(k_sh >= 0 && k_sh < grid.size() && m_sh >= 0 && m_sh < grid[0].size()){
                if(grid[k_sh][m_sh] == '1' && flags[k_sh][m_sh] == 0){
                    flags[k_sh][m_sh] = 1;
                    q.push(make_pair(k_sh, m_sh));
                }
            }
        }
    }
    return;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int> > flags;
        int islands = 0;
        for(int i = 0; i < grid.size(); ++i){
            flags.push_back({});
            for(int j = 0; j < grid[0].size(); ++j){
                flags[i].push_back(0);
            }
        }

        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(flags[i][j] == 1 || grid[i][j] == '0'){
                    flags[i][j] = 1;
                } else if(grid[i][j] == '1' && flags[i][j] == 0){
                    ++islands;
                    flags[i][j] = 1;
                    explore_island(i, j, grid, flags);
                }

            }
        }
        return islands;
    }
};
