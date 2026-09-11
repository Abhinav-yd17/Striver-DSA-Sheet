#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string &s1, string &s2){
        if(s1.size()+1 != s2.size()) return false;

        int i=0,j=0;
        while(j<s2.size()){
            if(i<s1.size() && s1[i]==s2[j]){
                i++; j++;
            }else{
                j++;
            }
        }
        return i==s1.size();
    }
    int solve(int index,int prev,vector<string>& words,
              vector<vector<int>>& dp){

        if(index==words.size())
            return 0;

        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];

        int notTake = solve(index+1,prev,words,dp);

        int take=0;
        if(prev==-1 || check(words[prev],words[index])){
            take = 1 + solve(index+1,index,words,dp);
        }

        return dp[index][prev+1]=max(take,notTake);
    }
    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),
            [](string &a,string &b){
                return a.size()<b.size();
            });

        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return solve(0,-1,words,dp);
    }
};