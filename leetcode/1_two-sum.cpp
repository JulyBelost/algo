// https://leetcode.com/problems/two-sum/
// sort O(nlogn) + O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        vector<pair<int, int> > muns(n);
        for(int i = 0; i < n; ++i){
            muns[i].first = nums[i];
            muns[i].second = i;
        }
        sort(muns.begin(), muns.end());

        for(int i = 0, j = n - 1; j > i, i < n; ){
            int a = muns[i].first;
            int b = muns[j].first;
            if (a + b == target){
                res.push_back(muns[i].second);
                res.push_back(muns[j].second);
                return res;
            } else if (a + b > target) {
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};
