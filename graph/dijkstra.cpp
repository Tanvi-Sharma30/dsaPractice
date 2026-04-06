#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Sloution {
    public:
    vector<int>dijkstra(int v, vector<vector<pair<int,int>>>adj,int s){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>dis(v,INT_MAX);
            dis[s]=0;
            pq.push({0,s}); //wight ,node
            while(!pq.empty()){
                int currDis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                for(auto it: adj[node]){
                    int adjEdge = it.first;
                    int weight = it.second;

                    if(currDis+ weight < dis[adjEdge]){
                        dis[adjEdge] = currDis+weight;
                        pq.push({dis[adjEdge], adjEdge});
                    }
                }
            }
        return dis;
    }
};