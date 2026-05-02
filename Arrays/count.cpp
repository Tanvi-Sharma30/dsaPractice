#include<iostream>
using namespace std;

class Solution {
public:
   int count = 0;
    int countDigit(int n) {
        while(n != 0){
    int dig = n%10;
    count = count +1;
    n = n/10; }
    
    cout<<"Number of digits are: "<<count<<endl;
    return count ;
    }
};

int main (){
    int n;
    cout <<"enter a number: ";
    cin>>n;
    Solution sol;
    int result = sol.countDigit(n);
    
}