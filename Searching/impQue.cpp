#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low =0; int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int noOfMissing = arr[mid]-(mid+1);
            if(noOfMissing<k) low =mid+1;
            else high=mid-1;
        }
        // after high crosses low ans = arr[high]+more
        //more = k-noOfMissing therefor ans = arr[high]+k-arr[high]+high -1
        //eventually arr[high] get cancel out and become k+high+1
        //so as we know after across low is pointing high+1
        //therefor ans will become low+k
       return low+k;
    }
};
int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    Solution sol;
    int ans = sol.findKthPositive(arr,5);
    cout<<ans;

    return 0;
}