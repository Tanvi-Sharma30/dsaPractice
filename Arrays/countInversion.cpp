#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int cnt =0;
int merge(vector<int> arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<= mid && right<= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt +=(mid-left+1);
            right ++;
        }
    }

    while(left<= mid){
        temp.push_back(arr[left]);
    }

    while(right<= high){
        temp.push_back(arr[right]);
    }
    for(int i= low; i<=high; i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    if(low>=high) return cnt;
    int mid = (low+high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid,high);
    return cnt;
}

int numberOfInversions(vector<int> &a, int n){
    mergeSort(a, 0, n-1);
   
  return cnt;
}
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int inversions = obj.numberOfInversions(arr, n);

    cout << "Number of inversions: " << inversions << endl;
    return 0;
}