#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
    private:
    void dfs(int node,vector<vector<int>>& adj,vector<int>&vis,stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis,st);
        }
        st.push(node);
    }
    public:
    vector<int>topoSort(int v,vector<vector<int>>& adj){
        vector<int>vis(v,0);
        stack<int>st;
        vector<int>ans;
        for(int i=0; i<v; i++){
            if(!vis[i]){
            dfs(i,adj,vis,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int V = 6;

    vector<vector<int>> adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    cout << "Topological Sort: ";
    for(auto it : result){
        cout << it << " ";
    }

    return 0;
}