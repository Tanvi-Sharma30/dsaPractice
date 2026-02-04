#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int> a, long long k){
    int left = 0;
    int right = 0;
    long long sum = 0;
    int maxlen = 0;
    int n= a.size();

    
        for(int right = 0; right<n; right++){
            sum += a[right];
        while(left<= right && sum > k){
            sum -= a[left];
            left ++;
        }
        if(sum == k){
            maxlen = max(maxlen , right - left +1); //+1 coz indexing start form o in array
        }
    }
    cout<<"Longest subarray is: "<<maxlen<<endl;
    return maxlen ;
}

int main(){
    vector<int> a = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int n = a.size();
    long long k;
     longestSubarray(a, 3);
     
     return 0;
}