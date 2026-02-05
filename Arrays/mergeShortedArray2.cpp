#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
        if(arr1[ind1]>arr2[ind2]){
            swap(arr1[ind1], arr2[ind2]);
        }
    }
    public:
    void merge(long long arr1[], long long arr2[], int n, int m){
        int len = (n+m);
        int gap = (len /2)+(len%2);
        while (gap>0){
            int left =0;
            int right = left+gap;
            while(right< len){
                // one pointer at arr1 and another at arr2
                if(left<n && right >=n){
                    swapIfGreater(arr1,arr2, left, right -n);
                } //one pointer at arr2 and another at arr2
                else if (left >= n){
                    swapIfGreater(arr2,arr2, left-n, right-n);
                }//one pointer at arr1 and another at arr1
                else {
                    swapIfGreater(arr1,arr1,left,right);
                }
                left ++, right++ ;
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
        }
    }
};

int main(){
    long long arr1[] = {1, 2, 7, 4, 3};
    long long arr2[]= {6, 9, 8, 1, 4, 0, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    Solution sol;
    sol.merge(arr1,arr2,n, m);

    cout<<"Merged aarray: ";
    for(int i=0; i<n; i++) cout<<arr1[i]<<" ";
    for(int i=0; i<m; i++) cout<<arr2[i]<<" ";
    cout<<endl;
    return 0;
}