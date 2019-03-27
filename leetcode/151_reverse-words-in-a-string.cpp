// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        while(s[0]==' '){
            s.erase(s.begin());
        }
        reverse(s.begin(), s.end());
        while(s[0]==' '){
            s.erase(s.begin());
        }
        s.push_back(' ');
        for(int i = 0, j = 0; i < s.size() && j < s.size(); ++i){
            if(s[i]==' '){
                reverse(s.begin() + j, s.begin() + i);
                ++i;
                while(i < s.size() && s[i]==' '){
                    s.erase(s.begin() + i);
                }
                j = i;
            }
        }
        s.pop_back();
        return s;
    }
};
