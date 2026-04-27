#include<iostream>
#include<vector>
using namespace std;

         // LINEAR SEARCH

// int lowerBound(vector<int> &arr, int target){
//     int n= arr.size();
//     for(int i=0; i<n; i++){
//         if(arr[i]>= target) {
//             return i;
//         } 
//     }
//     return -1;
// }

         // BINARY SEARCH

int lowerBound(vector<int> &arr, int target, int n) {
    int ans = n;
    long long low = 0;
    long long high = n-1;

    while(low<=high){
        long long mid = (low+high)/2;
        if(arr[mid]>= target) {
           ans = mid;
           high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return ans; // if target does not present in arr then return size of arr
    }      

int main(){
   vector<int> arr = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
   int n = arr.size();
   
   int index = lowerBound(arr,6,n);
   cout << "Lower bound index: " << index << endl;

   return 0;
}