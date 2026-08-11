#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalH = 0;

        for (int bananas : piles) {
            totalH += (bananas + hourly - 1) / hourly;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};