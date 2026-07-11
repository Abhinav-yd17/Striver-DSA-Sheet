#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int startIdx = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                startIdx = mid;
                end = mid - 1; 
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        start = 0;
        end = nums.size() - 1;
        int endIdx = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                endIdx = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        vector<int> ans;
        ans.push_back(startIdx);
        ans.push_back(endIdx);
        return ans;
    }
};
