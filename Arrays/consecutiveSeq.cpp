#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutiveELement(vector<int> &a){
    // sort(a.begin(), a.end());
    // int n= a.size();
    // int lastSmaller = INT_MIN;
    // int cnt = 0;
    // int longest = 1;

    // for(int i=0; i<n; i++){
    //     if(a[i]-1 == lastSmaller){
    //         cnt +=1;
    //         lastSmaller = a[i];
    //     }
    //     else if(lastSmaller != a[i]){
    //         cnt =1;
    //         lastSmaller = a[i];
    //     }
    //     longest = max(longest, cnt);
    // }
    // cout<<longest;


         //. OPTIMAL SOLUTION


         int n= a.size();
         if(n==0) return 0;
         int longest= 1;
         unordered_set<int> st;
          
         for(int i=0; i<n; i++){
            st.insert(a[i]);
         }

         for(auto x :st){
            // find starting element
            if(st.find(x-1) == st.end()){ // If there is no element before x, then x is the smallest in this possible sequence.
                  int cnt =1;
                  while(st.find(x+1)!= st.end()){ //if no previous element exist
                    x = x+1;
                    cnt = cnt+1;
                  }
                  longest = max(longest, cnt);
            }
         }

    cout<<longest;
    return longest;
}

int main(){
    vector<int> a = {5, 8, 3, 2, 1, 4,1 ,2} ;
    longestConsecutiveELement(a);

    return 0;
}