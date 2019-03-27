// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0, j = 0; i < s.size() && j < s.size(); ++i){
            if(s[i] == ' '){
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            } else if(i == s.size() - 1){
                reverse(s.begin() + j, s.end());
            }
        }
        return s;
    }
};
