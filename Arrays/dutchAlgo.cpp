#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int> &a, int n){
    int low = 0, mid = 0, high = n-1;

    while(mid<= high){
        if(a[mid]== 0){
            swap(a[low], a[mid]);
            low++;
            mid++ ;
        } else if(a[mid] ==1){
            mid++;
        } else {
            swap(a[mid], a[high]);
            high -- ;
        }
    }
}

int main(){
    vector<int> a = {1, 2, 0, 1, 1, 0, 0, 2, 1, 1};
    int n = a.size();

    sortArray(a,n);
    cout<<"Sorted array is: ";
    for(auto x : a){
     cout<<x<<" ";
    }
    return 0;
}