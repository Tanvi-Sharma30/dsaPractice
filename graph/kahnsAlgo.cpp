#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Solution{
    public:
    vector<int>topo(int v,vector<vector<int>>adj){
        vector<int>inDeg(v,0);
        for(int i=0; i<v; i++){
            for(auto it:adj[i]){
                inDeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<v; i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
        }
        return topo;
    }
};