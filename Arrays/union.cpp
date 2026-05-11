#include<iostream>
#include<vector>
#include<set>
using namespace std; 

class Solution {
    public:

    //  vector<int> unionArray(vector <int> a, vector<int> b){
    //     int n1 = a.size();
    //     int n2 = b.size();
    //     set<int> st; 
    //     for(int i=0; i<n1; i++){
    //         st.insert(a[i]);
    //     }
    //     for(int i=0; i<n2; i++){
    //         st.insert(b[i]);
    //     }
    //     vector<int> temp;
    //     for(auto it : st){ // insert value of set(st) in temp array
    //         temp.push_back(it);
    //     }
    //     return temp;
    // }


    //      OPTIMAL SOLUTION

     vector<int> unionArray(vector <int> a, vector<int> b){

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int n1 = a.size();
        int n2 = b.size();
        int i =0;
        int j =0;
        vector<int> temp;
        while(i<n1 && j<n2){
            if(a[i] <= b[j]){
                if (temp.size() == 0 || temp.back() != a[i]){
                    temp.push_back(a[i]);
                }
                i++;
            } else {
                if(temp.size() == 0|| temp.back()!= b[j]){
                    temp.push_back(b[j]);
                }
                j++;
            }
        } 

        // if one of the array is get iterated 

            while(j<n2){ //for remaining elements of array b
                if(temp.size() == 0|| temp.back()!= b[j]){
                    temp.push_back(b[j]);
                }
                j++;
            }

            while(i<n1){ // for remaining elements pf array a
               if (temp.size() == 0 || temp.back() != a[i]){
                    temp.push_back(a[i]);
                }
                i++; 
            }
            return temp;
    }
};

int main(){
    vector<int> a = {1, 2, 2, 4, 5, 3};
    vector<int> b ={2, 3, 6, 5, 8};

    Solution sol;

    vector<int> ans = sol.unionArray(a,b);

    for (int x : ans){ // here ans is vector and it will print all elements of temp
        cout<<x<<" ";
    }
    return 0;
}