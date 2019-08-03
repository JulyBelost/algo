// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = -1, r = nums.size();
        int m = nums.size() / 2;
        while(l < r){
            if((m == 0 || nums[m] > nums[m - 1]) && (m == nums.size() - 1 || nums[m] > nums[m + 1])){
                return m;
            }
            int m_l = l + (m - l) / 2;
            int m_r = m + (r - m) / 2;
            if(nums[m_l] > nums[m]){
                r = m;
            } else if (nums[m_r] > nums[m]){
                l = m;
            } else {
                l = m_l;
                r = m_r;
            }
            m = l + (r - l) / 2;
        }
        return m;
    }
};