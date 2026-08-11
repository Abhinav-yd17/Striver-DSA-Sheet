#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int l = 0, maxf = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            cnt[s[r] - 'A']++;
            maxf = max(maxf, cnt[s[r] - 'A']);
            if ((r - l + 1) - maxf > k) {
                cnt[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
