#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    int left =0 , right= m-1;
    int top =0 , bot = n-1;
    vector<int> ans;

    while(top<= bot && left<=right){
    for(int i= left; i<=right; i++){
        ans.push_back(mat[top][i]);
    }
    top++;
    for(int i= top; i<=bot; i++){
        ans.push_back(mat[i][right]);
    }
    right --;
    if(top<=bot){
    for(int i = right; i>=left; i--){
        ans.push_back(mat[bot][i]);
    } 
    bot --;
    }
    if(left<=right){
    for(int i=bot; i>=top; i--){
        ans.push_back(mat[i][left]);
    }
    left++;
}
}
return ans;
}

int main(){
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    

    vector<int> ans = spiralMatrix(mat);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}