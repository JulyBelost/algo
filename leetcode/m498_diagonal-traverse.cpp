// https://leetcode.com/problems/diagonal-traverse/

bool diagonalSort(pair<int, int> a, pair<int, int> b) {
        int ai = a.first, aj = a.second;
        int bi = b.first, bj = b.second;
        int as = ai + aj, bs = bi + bj;
        if(as == bs){
            if(as % 2 == 0){
                return aj < bj;
            } else {
                return ai < bi;
            }
        } else {
            return as < bs;
        }
    }

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int> > idxs;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                idxs.push_back(make_pair(i, j));
            }
        }

        sort(idxs.begin(), idxs.end(), diagonalSort);

        for(int i = 0; i < idxs.size(); ++i){
            res.push_back(matrix[idxs[i].first][idxs[i].second]);
        }

        return res;
    }
};
