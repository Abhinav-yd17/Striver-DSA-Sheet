#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        if (m == 0) return false;
        int n = mat[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / n;
            int c = mid % n;

            if (mat[r][c] == target) return true;
            if (mat[r][c] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};