// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_r = 0, sum_l = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum_r += nums[i];
        }
        for(int i = 0; i < nums.size(); ++i){
            sum_r -= nums[i];
            if (sum_r == sum_l){
                return i;
            }
            sum_l += nums[i];
        }
        return -1;
    }
};
