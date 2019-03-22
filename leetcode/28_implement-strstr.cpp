// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }

        for(int i = 0; i + needle.size() <= haystack.size(); ++i){
            for(int j = 0; j < needle.size() && i + j < haystack.size() && haystack[i + j] == needle[j]; ++j){
                if(j == needle.size() - 1){
                    return i;
                }
            }
        }

        return -1;
    }
};
