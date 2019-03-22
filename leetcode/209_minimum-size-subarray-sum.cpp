// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int> numssums = {0};
        int t = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            t += nums[i];
            numssums.push_back(t);
        }
        if(numssums[n] < s){
            return 0;
        }

        int res = nums.size();

        for(int i = 0, j = 0; i <= n && j <= n; ){
            if(numssums[j] - numssums[i] >= s){
                res = min(res, j - i);
                ++i;
                j = i;
            } else {
                ++j;
            }
        }
        return res;
    }
};
