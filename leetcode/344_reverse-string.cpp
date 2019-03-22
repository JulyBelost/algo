// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        char t;
        int n = s.size();
        for(int i = 0; i < n / 2; ++i){
            t = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = t;
        }
    }
};
