#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// vector<vector<int>> triplet(int n, vector<int> &num){
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         for(int j = i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 if(num[i] + num[j]+ num[k] == 0){
//                     vector<int> temp = {num[i],num[j],num[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

          // OPTIMAL SOLUTION

 vector<vector<int>> triplet(int n, vector<int> &num){
       vector<vector<int>> ans;
       sort(num.begin(), num.end());
       for(int i=0; i<n; i++){
        int j= i+1;
        int k = n-1;
           if(i>0 && num[i] == num[i-1]) continue;
           while(j<k){
            int sum = num[i] + num[j] + num[k];
            if(sum<0){
                j++;
            } else if(sum>0){
                k--;
            } else {
                vector<int> temp = {num[i],num[j],num[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && num[j] == num[j-1]) j++;
                while(j<k && num[k] == num[k+1]) k--;
            }
           }
       } 
       return ans;  
}



int main(){
    vector<int> num = {-1, -2, -1, 0, 0, 0, -2, -1, -2, 2, 2, 2, 2};
    int n= num.size();
     
    vector<vector<int>> ans = triplet(n, num);

    for(auto x: ans){
        for(auto val: x){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}