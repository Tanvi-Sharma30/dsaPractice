#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& pathVis, vector<int>& check) {
        
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, check) == true) {
                    return true;
                }
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        check[node] = 1;      // SAFE NODE
        pathVis[node] = 0;    // BACKTRACK
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);
        vector<int> safeNode;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < n; i++) {
            if (check[i] == 1)
                safeNode.push_back(i);
        }

        return safeNode;
    }
};