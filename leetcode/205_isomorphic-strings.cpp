// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        vector<int> hs(128), ht(128);
        for(int i = 0; i < hs.size(); ++i){
            hs[i] = 0;
            ht[i] = 0;
        }

        char s_j = ' ', t_j = ' ';
        string sn = "", tn = "";

        for(int i = 0; i < n; ++i){
            if(hs[s[i] - ' '] == 0){
                hs[s[i] - ' '] = i + 1;
                sn.push_back(s_j);
                ++s_j;
            } else {
                sn.push_back(sn[hs[s[i] - ' ']] - 1);
            }
            if(ht[t[i] - ' '] == 0){
                ht[t[i] - ' '] = i + 1;
                tn.push_back(t_j);
                ++t_j;
            } else {
                tn.push_back(tn[ht[t[i] - ' ']] - 1);
            }
        }
        return (sn == tn);
    }
};
