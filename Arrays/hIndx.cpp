#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int cnt=0;
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i=0;i<n;i++){
            if(cnt==citations[i]) break;
            if(cnt<citations[i]) cnt+=1;
            else break;
        }
        return cnt;
    }
};