#include<iostream>
#include<vector>
using namespace std;

vector<int> leader(vector<int> & A){
    int n = A.size();
   vector<int> temp;
   int maxi = INT_MIN;
    for(int i=n-1;i>0;i--){
        
        if(A[i]>maxi){
            temp.push_back(A[i]);
            }
            maxi= max(maxi, A[i]);
    }
    sort(temp.begin(), temp.end());
    for(int x: temp){
        cout<<x<<" ";
    }
    return temp;
}

int main(){
    vector <int> A= {10, 22, 12, 3, 0, 6};
    leader(A);
    
    return 0;
}