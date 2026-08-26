#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], 
                  vector<int>& vis, 
                  vector<int>& pathVis, 
                  vector<int>& ans) {
        
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, ans))
                    return true;
            }
            else if (pathVis[it]) {
                return true;  
            }
        }
        pathVis[node] = 0;
        ans.push_back(node);   
        return false;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};