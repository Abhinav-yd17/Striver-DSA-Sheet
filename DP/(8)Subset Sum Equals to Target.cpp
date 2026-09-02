#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {

        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

        // Base Case
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;

        // Fill Table
        for(int i = 1; i <= n; i++) {

            for(int target = 1; target <= k; target++) {

                bool notTake = dp[i-1][target];

                bool take = false;

                if(arr[i-1] <= target)
                    take = dp[i-1][target - arr[i-1]];

                dp[i][target] = take || notTake;
            }
        }

        return dp[n][k];
    }
};