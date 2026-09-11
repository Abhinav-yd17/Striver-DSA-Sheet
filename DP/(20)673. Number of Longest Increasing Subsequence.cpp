#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,int> solve(int index, int prev, vector<int>& nums,
                        vector<vector<pair<int,int>>>& dp,
                        vector<vector<int>>& vis) {

        if (index == nums.size())
            return {0, 1};   // {length, count}

        if (vis[index][prev + 1])
            return dp[index][prev + 1];

        vis[index][prev + 1] = 1;

        // Not Take
        auto notTake = solve(index + 1, prev, nums, dp, vis);

        // Take
        pair<int,int> take = {0, 0};

        if (prev == -1 || nums[index] > nums[prev]) {
            auto next = solve(index + 1, index, nums, dp, vis);
            take = {next.first + 1, next.second};
        }

        // Choose better result
        if (take.first > notTake.first)
            return dp[index][prev + 1] = take;

        if (take.first < notTake.first)
            return dp[index][prev + 1] = notTake;

        // Same length → add counts
        return dp[index][prev + 1] =
            {take.first, take.second + notTake.second};
    }

    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<pair<int,int>>> dp(
            n, vector<pair<int,int>>(n + 1, {-1, -1}));

        vector<vector<int>> vis(n, vector<int>(n + 1, 0));

        auto ans = solve(0, -1, nums, dp, vis);

        return ans.second;
    }
};