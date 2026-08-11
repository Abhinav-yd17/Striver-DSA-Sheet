#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind;

    StockSpanner() {
        ind = -1;
        while(!st.empty()) st.pop();
    }
    
    int next(int val) {
        ind = ind + 1;

        while(!st.empty() && st.top().first <= val) {
            st.pop();
        }

        int ans = ind - (st.empty() ? -1 : st.top().second);

        st.push({val, ind});
        return ans;
    }
};