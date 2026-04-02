#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class solution{
    private:
    vector<int>topoSort(int v , vector<vector<int>>&adj){
        vector<int>indeg(v,0);
        for(int i=0; i<v; i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<v; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        return topo;
    }
    public:
    string alienDict(int k, int n, vector<string>&dict){
        vector<vector<int>>adj(k);
        for(int i=0; i<n-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int i=0; i<len; i++){
                if(s1[i]!=s2[i]) {
                    adj[s1[i]].push_back(s2[i]);
                    break;
                }
            }
        }
        vector<int>topo = topoSort(k,adj);
        string ans = " ";
        for(auto it: topo){
            ans = ans+char(it +'a');
        }
        return ans;
    }
};