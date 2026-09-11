#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int index, int prev, vector<int>& nums,
                      vector<vector<vector<int>>>& dp,
                      vector<vector<int>>& vis) {

        if (index == nums.size())
            return {};

        if (vis[index][prev + 1])
            return dp[index][prev + 1];

        vis[index][prev + 1] = 1;

        vector<int> notTake = solve(index + 1, prev, nums, dp, vis);

        vector<int> take;
        if (prev == -1 || nums[index] % nums[prev] == 0) {
            take = solve(index + 1, index, nums, dp, vis);
            take.insert(take.begin(), nums[index]);
        }

        if (take.size() >= notTake.size())
            dp[index][prev + 1] = take;
        else
            dp[index][prev + 1] = notTake;

        return dp[index][prev + 1];
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1));
        vector<vector<int>> vis(n, vector<int>(n + 1, 0));

        return solve(0, -1, nums, dp, vis);
    }
};