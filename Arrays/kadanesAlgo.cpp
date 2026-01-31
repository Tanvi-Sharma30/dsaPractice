#include<iostream>
#include<vector>
using namespace std;

long long maxSubArraySum(int a[], int n){
    long long sum = 0, maxi = LONG_MIN;
    for(int i = 0; i<n; i++){
        sum += a[i];

        if(sum<0){
            sum = 0;
        }

        if(sum> maxi){
            maxi = sum;
        }
    }
    cout<<"Maximum value is: "<<maxi<<endl;
    return maxi;
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    maxSubArraySum(a,n);
}