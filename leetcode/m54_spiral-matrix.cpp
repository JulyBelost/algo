// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }
        int m = matrix.size(), n = matrix[0].size();
        int l = m * n;
        int cnt = 0;
        vector<vector<int> > flag(m, vector<int>(n));
        int i = 0, j = 0;
        for(int k = 0; cnt < l; ++k){
            if(k % 4 == 0){
                i = k / 4;
                j = 0;
                while(j < n){
                    if(flag[i][j] == 0){
                        res.push_back(matrix[i][j]);
                        flag[i][j] = 1;
                        ++cnt;
                    }
                    ++j;
                }
            }
            if(k % 4 == 1){
                i = 0;
                j = n - 1 - k / 4;
                while(i < m){
                    if(flag[i][j] == 0){
                        res.push_back(matrix[i][j]);
                        flag[i][j] = 1;
                        ++cnt;
                    }
                    ++i;
                }
            }
            if(k % 4 == 2){
                i = m - 1 - k / 4;
                j = n - 1;
                while(j >= 0){
                    if(flag[i][j] == 0){
                        res.push_back(matrix[i][j]);
                        flag[i][j] = 1;
                        ++cnt;
                    }
                    --j;
                }
            }
            if(k % 4 == 3){
                i = m - 1;
                j = k / 4;
                while(i >= 0){
                    if(flag[i][j] == 0){
                        res.push_back(matrix[i][j]);
                        flag[i][j] = 1;
                        ++cnt;
                    }
                    --i;
                }
            }

        }
        return res;
    }
};
