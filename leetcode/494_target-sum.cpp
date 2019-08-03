// https://leetcode.com/problems/target-sum/

int addToSum(int x, int l, vector<int>& nums, int S){
    if(l == nums.size()){
        return x == S ? 1: 0;
    }
    return addToSum(x + nums[l], l + 1, nums, S) + addToSum(x - nums[l], l + 1, nums, S);
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return addToSum(0, 0, nums, S);
    }
};