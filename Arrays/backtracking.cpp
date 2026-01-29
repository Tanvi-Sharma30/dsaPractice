#include <iostream>
using namespace std;

// void fun(int i, int n){
//     if (i<1) return ;
//     fun(i-1 , n);
//     cout<<i<<endl;
// } 

// Reverse 

// void fun1(int i, int n){
//     if(i>n) return; 
//     fun1(i+1, n);
//     cout<<i<<endl;
// }

   //Factorial

int fact(int n) {
  if (n == 0) return 1;
  return n * fact(n-1);
} 


int main() {
    // fun(8,8);
    //fun1(0,6);

    int n =4;
    cout<<fact(n);

    return 0;
}