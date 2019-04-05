// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        res[n - 1] = 0;
        int i = n - 2;
        while(i >= 0 && T[i] >= T[i + 1]){
            res[i] = 0;
            --i;
        }
        for(; i >= 0; --i){
            if(T[i] < T[i + 1]){
                res[i] = 1;
            } else {
                int j = i + 1;
                while(j < n && T[i] >= T[j]){
                    if(res[j] == 0){
                        j = i;
                        break;
                    }
                    j += res[j];
                }
                res[i] = j - i;
            }
        }
        return res;
    }
};
