// https://leetcode.com/problems/rotate-array/

// O(1) extra space, O(n) time 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int i = 0, j = n - k, l = j;
        while(l < n){
            swap(nums[i], nums[j]);
            ++i;
            ++j;
            if(i == l){
                l = j;
            }
            if(j == n){
                j = l;
            }
        }
    }
};
