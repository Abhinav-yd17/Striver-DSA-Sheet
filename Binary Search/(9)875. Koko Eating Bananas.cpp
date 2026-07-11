#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 0;
        for (int p : piles) if (p > hi) hi = p; 

        auto canFinish = [&](int k) -> bool {
            long long hours = 0; 
            for (int p : piles) {
                hours += (p + (long long)k - 1) / k;
                if (hours > h) return false;
            }
            return hours <= h;
        };

        int ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canFinish(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
