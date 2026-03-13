#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<vector<int>>&adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it: adj[node]){
            if(dfs(node,vis,pathVis,adj)==true) return true;
            else if(pathVis[node]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    public:
    bool isCycle(int v, vector<vector<int>> adj){
        vector<int> vis(v,0);
        vector<int> pathVis(v,0);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true) return true;
            }
        }
        return false;
    }
};