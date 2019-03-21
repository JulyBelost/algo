// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int an = a.size(), bn = b.size();
        int mx = max(an, bn);
        vector<int> av(mx);
        vector<int> bv(mx);
        vector<int> cv(mx);
        for(int i = 0; i < an; ++i){
            av[i] = a[an - 1 - i] - '0';
        }
        for(int i = 0; i < bn; ++i){
            bv[i] = b[bn - 1 - i] - '0';
        }
        for(int i = 0; i < mx; ++i){
            cv[i] = av[i] + bv[i];
        }
        for(int i = 0; i < mx; ++i){
            if(cv[i]==2 || cv[i]==3) {
                if(i == mx - 1){
                    cv.push_back(1);
                } else {
                    cv[i + 1] += 1;
                }
                cv[i] %= 2;
            }
        }
        for(int i = cv.size() - 1; i >= 0; --i){
            res.push_back('0' + cv[i]);
        }
        return res;
    }
};
