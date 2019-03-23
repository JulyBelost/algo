// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        int n = nums.size();
        int sum = 0;
        int res = n + 1;

        for(int i = 0, j = 0; i < n && j <= n; ){

            if(sum >= s){
                res = min(res, j - i);
                sum -= nums[i];
                ++i;
            } else {
                if(j != n){
                    sum += nums[j];
                }
                ++j;
            }
        }
        return res == n + 1 ? 0 : res;
    }
};
