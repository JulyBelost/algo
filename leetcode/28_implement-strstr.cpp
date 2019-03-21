// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }
        for(int i = 0; i < haystack.size(); ++i){
            if(haystack[i] == needle[0] && haystack.substr(i, needle.size()) == needle){
                return i;
            }
        }
        return -1;
    }
};
