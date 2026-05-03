#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> v){
    int cnt = 0;
    int el;
    for(int i=0; i<v.size(); i++){
        if(cnt == 0){
            cnt = 1;
            el = v[i]; //take next element as new el
        } else if( v[i] == el){
            cnt ++;
        } else {
            cnt -- ;
        }
    }

      // iterate again to check ans if it is occure greater than n/2 times
    int cnt1 = 0;
    for(int i=0; i<v.size(); i++){
        if (v[i]== el)cnt ++;
    } 
    if (cnt1> (v.size())/2){
        return el;
    }
    cout<<"Majority occured element is: "<<el<<endl;
    return el;
}

int main(){
    vector<int> v = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    
    majorityElement(v);
}