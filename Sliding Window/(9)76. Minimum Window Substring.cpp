#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        vector<int> hash(256, 0);
        for (char c : t)
            hash[c]++;

        int l = 0, r = 0, cnt = 0;
        int minLen = INT_MAX, start = -1;
        int m = t.size();

        while (r < s.size()) {
            if (hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        if (start == -1)
            return "";
        return s.substr(start, minLen);
    }
};
