// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string a = strs[0];
        for(int i = 0; i < strs.size(); ++i){
            if(a == ""){
                return a;
            }
            a = a.substr(0, strs[i].size());
            for(int j = 0; j < a.size(); ++j){
                if(a[j] != strs[i][j]){
                    a = a.substr(0, j);
                }
            }
        }
        return a;
    }
};
