#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<int> bfs(int v, vector<int> adj[]){
        vector<int> vis(v, 0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        vector<int>bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};