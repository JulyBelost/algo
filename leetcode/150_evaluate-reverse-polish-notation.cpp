// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Created by Julia on 2019-08-04.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for(int i = 0; i < tokens.size(); ++i){
            if((tokens[i].back() >= '0' && tokens[i].back() <= '9') ) {
                st.push_back(stoi(tokens[i]));
            } else {
                int n = st.back();
                st.pop_back();
                int m = st.back();
                st.pop_back();
                if(tokens[i] == "+"){
                    st.push_back(m + n);
                } else if(tokens[i] == "-"){
                    st.push_back(m - n);
                } else if(tokens[i] == "*"){
                    st.push_back(m * n);
                } else if(tokens[i] == "/"){
                    st.push_back(m / n);
                }
            }
        }
        return st.back();
    }
};