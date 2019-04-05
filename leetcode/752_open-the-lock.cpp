// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> deadends_set(deadends.begin(), deadends.end());
        if(deadends_set.count("0000")){
            return -1;
        }
        if(target == "0000"){
            return 0;
        }
        map<string, int> visited;
        queue<string> q;
        q.push("0000");
        visited.insert(make_pair("0000", 0));
        int l = 0;

        while(!q.empty()){
            string cur = q.front();
            int l = visited[cur];
            q.pop();
            for(int i = 0; i < 4; ++i){
                string left = cur, right = cur;
                left[i] = cur[i] == '0' ? '9' : cur[i] - 1;
                right[i] = cur[i] == '9' ? '0' : cur[i] + 1;
                if(right == target || left == target){
                    return l + 1;
                }
                if(!deadends_set.count(left) && !visited.count(left)){
                    visited.insert(make_pair(left, l + 1));
                    q.push(left);
                }
                if(!deadends_set.count(right) && !visited.count(right)){
                    visited.insert(make_pair(right, l + 1));
                    q.push(right);
                }
            }
        }
        return -1;
    }
};
