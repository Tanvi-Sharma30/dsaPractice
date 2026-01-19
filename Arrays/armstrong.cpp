#include<iostream>
using namespace std;

class Solution {
  public:

  bool isArmstrongNum(int x){
    int num = 0;
    int temp = x;

    while (x!=0){
        int dig = x%10;
        int n = dig*dig*dig;
        num = num*10 + n;
        x = x/10;
    }
    return num = temp ;
  }
};

int main(){
    int x;
    cout<< "Enter a number: ";
    cin>> x;

    Solution sol;
    bool result = sol.isArmstrongNum(x);
     cout<<(result?"True":"False")<<endl;
     
    return 0;
}