// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int b = 0, sb = 0, idx = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > sb){
                if(nums[i] > b){
                    sb = b;
                    b = nums[i];
                    idx = i;
                } else {
                    sb = nums[i];
                }

            }
        }
        return (b >= sb * 2) ? idx : -1;
    }
};
