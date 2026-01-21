#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
    public:

    int unique(vector<int> arr , int n){
        int i =0;
        for (int j=1; j<n; j++){
            if(arr[j] != arr[i]){
                arr[i+1] = arr[j];
                i++ ;
            }
        }
        cout<<i+1;
        return (i+1);
    }

   
};

int main(){

    vector<int> arr = { 1, 2, 2, 3, 3, 3};
    int n = arr.size();

    Solution sol;
    sol.unique(arr,n);
    
    return 0;
}