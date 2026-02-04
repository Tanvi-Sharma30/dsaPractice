#include<iostream>
#include<vector>
using namespace std;

// int maxProductSubarray(vector<int> &arr){
//     int n = arr.size();
//     int maxi =INT_MIN;
//     for(int i=0;i<n; i++){
//         int pro =1;
//         for(int j=i; j<n; j++){
//         pro *= arr[j];
//         maxi = max(maxi, pro);
//     }}
//     cout<<maxi; 
//     return maxi;
// }

     // OPTIMAL SOLUTION

     int maxProductSubarray(vector<int> &arr){
        int pre =1 , suff =1;
        int maxi = INT_MIN;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(pre == 0) pre =1;
            if(suff == 0) suff =1;

            pre = pre*arr[i];
            suff= suff*arr[n-1-i];
            maxi = max(pre, suff);
        }
        cout<<maxi;
        return maxi;
     }


int main(){
    vector<int> arr = {2, 3, -2, -7, 0, 6, 8};
    maxProductSubarray(arr);
    return 0;
}