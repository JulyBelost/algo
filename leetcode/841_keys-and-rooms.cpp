// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> keys(n);
        stack<int> path;
        keys[0] = 1;
        path.push(0);
        int r = 1;
        while(!path.empty() && r < rooms.size()){
            int cur = path.top();
            path.pop();
            for(int i = 0; i < rooms[cur].size(); ++i){
                if(!keys[rooms[cur][i]]){
                    path.push(rooms[cur][i]);
                    keys[rooms[cur][i]] = 1;
                    ++r;
                }

            }
        }
        return r == rooms.size();
    }
};