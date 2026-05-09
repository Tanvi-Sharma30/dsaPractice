#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void strassenMatrix(int A[2][2], int B[2][2], int C[2][2]){
        int p1,p2,p3,p4,p5,p6,p7;
        p1 = (A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
        p2 = (A[1][0]+A[1][1])*B[0][0];
        p3 = A[0][0]*(B[0][1]- B[1][1]);
        p4= (A[1][1])*(B[1][0]-B[0][0]);
        p5 = (A[0][0]+A[0][1])*B[1][1];
        p6 = (A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
        p7 = (A[0][1]-A[1][1])*(B[1][0]+B[1][1]);

        C[0][0] = p1+p4+p5+p7;
        C[0][1]= p3+p5;
        C[1][0]= p2+p4;
        C[1][1] = p1-p2+p3+p6;
    }
    void printMatrix(int matrix[2][2]){
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
int A[2][2];int B[2][2];int C[2][2];

cout<<"Elements of matrix A";
for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
    cin>>A[i][j];
            }
        }
cout<<"Elements of matrix B";        
for(int i=0; i<2; i++){
   for(int j=0; j<2; j++){
     cin>>B[i][j];
            }
        } 

        Solution sol;
    sol.strassenMatrix(A,B,C);
    sol.printMatrix(C);
    
    return 0;
}