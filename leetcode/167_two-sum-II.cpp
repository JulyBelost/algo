// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0, j = n - 1; i != j;){
            int x = numbers[i] + numbers[j];
            if(x == target){
                return {i + 1, j + 1};
            } else if (x < target){
                ++i;
            } else {
                --j;
            }
        }
        return {};
    }
};
