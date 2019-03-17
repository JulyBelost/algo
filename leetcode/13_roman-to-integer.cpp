https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> roman;

        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;

        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            if(i+1 < s.size() && (roman[s[i]] < roman[s[i+1]])){
                res += roman[s[i+1]] - roman[s[i]];
                ++i;
            } else {
                res += roman[s[i]];
            }
        }
        return res;
    }
};
