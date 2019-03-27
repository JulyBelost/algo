// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i = 0; i <= rowIndex; ++i){
            vector<int> t;
            for(int j = 0; j <= res.size(); ++j){
                if(j == 0 || j == i){
                    t.push_back(1);
                } else {
                    t.push_back(res[j - 1] + res[j]);
                }
            }
            res = t;
        }
        return res;
    }
};
