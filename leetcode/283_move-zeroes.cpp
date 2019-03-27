// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i = 0, j = 0; i < n && j < n - k && k < n; ++i){
            if(nums[i] == 0){
                ++k;
            } else {
                nums[j] = nums[i];
                ++j;
            }
        }
        for(int i = n - k; i < n; ++i){
            nums[i] = 0;
        }
    }
};
