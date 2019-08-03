// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Created by Julia on 2019-08-04.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(nums[r] > nums[l]){
            return nums[l];
        }
        while(l + 1 < r){
            int m = l + (r - l) / 2;
            // if(nums[m] < nums[m - 1]){
            //     return nums[m];
            // }
            if(nums[m] < nums[l]){
                r = m;
            } else {
                l = m;
            }
        }
        return nums[r];
    }
};

