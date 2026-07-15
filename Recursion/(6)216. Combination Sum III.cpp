#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void combinations(int ind, int k, int n, vector<int>& ds) {
        if (k < 0 || n < 0) return;
        if (k == 0 && n == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i <= 9; i++) {
            ds.push_back(i);
            combinations(i + 1, k - 1, n - i, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        combinations(1, k, n, ds);
        return ans;
    }
};
