// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 1; i < n; ++i){
            string res;
            for(int j = 0; j < s.size();){
                char symb = s[j];
                int cnt = 1;
                while((j + 1) < s.size() && s[j+1] == s[j]){
                    ++cnt;
                    ++j;
                }
                res.push_back('0' + cnt);
                res.push_back(s[j]);
                ++j;
            }
            s = res;
        }
       return s;
    }
};
