// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        for(; i <= j; ){
            if(i == j && nums[i] == val){
                return i;
            }
            if(nums[j] == val){
                --j;
            } else if(nums[i] == val){
                nums[i] = nums[j];
                --j;
                ++i;
            } else {
                ++i;
            }
        }
        return min(i, j) + 1 ;
    }
};
