#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
   private:
   bool detect(int src, vector<vector<int>>&adj, vector<int>&vis){
      vis[src]=1;
      queue<pair<int,int>> q;
      q.push({src, -1});
      while(!q.empty()){
         int node = q.front().first;
         int parent = q.front().second;
         q.pop();

         for(auto p: adj[node]){
            if(!vis[p]){
               vis[p]=1;
               q.push({p,node});
            } else if(parent!=p) return true;
         }
      }
      return false;
   }
   public:
   bool isCycle(int v, vector<vector<int>>& adj){
    vector<int>vis(v,0);
    for(int i=0; i<v; i++){
      if(!vis[i]) {
         if(detect(i, adj, vis))
         return true;
      }
    }
    return false;
   }
};