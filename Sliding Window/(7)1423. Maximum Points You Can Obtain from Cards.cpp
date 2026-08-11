#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& nums, int k){
        int lsum = 0, rsum = 0, maxsum = 0;
        for (int i = 0; i < k; i++) {
            lsum += nums[i];
        }
        maxsum = lsum;
        int rIndex = nums.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            lsum -= nums[i];
            rsum += nums[rIndex];
            rIndex--;
            maxsum = max(maxsum, lsum + rsum);
        }
        return maxsum;
    }
};
