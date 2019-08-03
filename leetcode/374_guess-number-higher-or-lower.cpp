// https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        while(l <= r){
            int i = l + (r - l) / 2;
            int a = guess(i);
            if(!a){
                return i;
            } else if(a == -1){
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};