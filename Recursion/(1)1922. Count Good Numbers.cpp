#include<bits/stdc++.h>
using namespace std;  
class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b % 2)
                ans = ans * a % mod;

            a = a * a % mod;
            b /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        return power(5, (n + 1) / 2) * power(4, n / 2) % mod;
    }
};