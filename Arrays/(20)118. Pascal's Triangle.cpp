#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int n = 0; n < numRows; n++) {
            vector<int> row;
            long long val = 1;  
            for (int r = 0; r <= n; r++) {
                row.push_back(val);
                val = val * (n - r) / (r + 1); 
            }
            ans.push_back(row);
        }
        return ans;
    }
};
