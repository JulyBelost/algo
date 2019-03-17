// https://leetcode.com/problems/jewels-and-stones/ 

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        vector<int> jvec(60);
        for(int i = 0; i < jvec.size(); ++i){
            jvec[i] = 0;
        }
        for(int i = 0; i < J.size(); ++i){
            jvec[J[i]-'A'] = 1;
        }
        for (int j = 0; j < S.size(); ++j){
            if (jvec[S[j] - 'A'] == 1){
                ++res;
            }
        }
        return res;
    }
};
