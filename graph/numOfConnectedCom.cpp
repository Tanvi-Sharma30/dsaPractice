#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    private:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size(); 
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            //travers all the neighbours 
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow = r+delrow;
                    int ncol = c+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                       vis[nrow][ncol]=1;
                       q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    public:
    int numOfIslands(vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt =0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt ++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        cout<<cnt<<endl;
        return cnt;
    }
};

int main(){
    vector<vector<char>>grid = {
        {'1','1','0'},
        {'1','1','0'},
        {'0', '0','0'},
        {'0','0','1'}
    };
    Solution sol;
    sol.numOfIslands(grid);

    return 0;
}