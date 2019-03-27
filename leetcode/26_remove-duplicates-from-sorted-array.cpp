// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        int k = 0;
        for(int i = 0, j = 0; i < n && j < n && k < n; ++i){
            if(nums[i] != nums[j]){
                ++k;
                nums[k] = nums [i];
                j = i;
            }
        }
        return k + 1;
    }
};
