#include<bits/stdc++.h>
using namespace std;  
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeros = 0, maxLen = 0;
        int n = nums.size();

        while (r < n) {
            if (nums[r] == 0) zeros++;
            if (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
