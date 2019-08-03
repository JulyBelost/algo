// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int l = 0, r = nums.size() - 1; l <= r; ){
            int i = l + (r - l) / 2;
            if(nums[i] > target){
                r = i - 1;
            } else if(nums[i] < target){
                l = i + 1;
            } else {
                return i;
            }
        }
        return -1;
    }
};