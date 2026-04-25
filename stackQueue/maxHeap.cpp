#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxTastePoints(vector<int>v, vector<int>d, int n, int m){
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<n; i++){
            pq.push({v[i],i});
        }
        int sum=0;
        while(m>0 &&!pq.empty()){
            int taste = pq.top().first;
            int idx = pq.top().second;
            if(taste<=0) break;
            sum+=taste;
            int nextTaste = taste - d[idx];
            m--;
            if(nextTaste>0) 
            pq.push({nextTaste,idx});
        }
        return sum;
    }
};