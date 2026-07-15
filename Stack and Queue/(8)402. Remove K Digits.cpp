#include<bits/stdc++.h>
using namespace std;  
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;

        ans = ans.substr(i);

        if (ans == "") return "0";
        return ans;
    }
};
