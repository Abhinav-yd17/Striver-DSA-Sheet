#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjacentNode : adj[node]) {
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, vis, pathVis, adj) == true)
                    return true;
            }
            else if(pathVis[adjacentNode])
                return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj) == true)
                    return false;
            }
        }
        return true;
    }
};