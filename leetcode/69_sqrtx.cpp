// https://leetcode.com/problems/sqrtx/
// Created by Julia on 2019-08-04.

class Solution {
public:
    int mySqrt(int x) {
        int r = x, l = 0;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            long long s = m * m;
            if(s == x){
                return m;
            }
            if(s > x){
                r = m - 1;
            } else if ((m + 1) * (m + 1) > x) {
                return m;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};

