#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution{
    public:
    vector<int>dijkstra(int v, vector<vector<pair<int,int>>>adj,int s){
        set<pair<int, int>> st;
        vector<int>dis(v,INT_MAX);
        st.insert({0,s});
        dis[s]=0;

        while(!st.empty()){
            auto it =*(st.begin());
            int node = it.second;
            int dist = it.first;

            for(auto it:adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;
                if(dist+adjwt < dis[adjnode]){
                    if(dis[adjnode]!=INT_MAX){
                        st.erase({dis[adjnode],adjnode});
                    }
                    dis[adjnode]=dist+adjwt;
                    st.insert({dis[adjnode], adjnode});
                }
            }
        }
        return dis;
    }
};