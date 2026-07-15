#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }

        return pse;
    }
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }

        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);

        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }

        return total;
    }
};