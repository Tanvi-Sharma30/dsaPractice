#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right){}
};
class Solution{
    public:
    void findParent(TreeNode* root, TreeNode* target, map<TreeNode* , TreeNode* > &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if(curr->right) {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }
    // vector<int> kthDistance(TreeNode* root, TreeNode* target, int k){
    //     map<TreeNode* , TreeNode* > parent;
    //     findParent(root, target, parent);
    //     queue<TreeNode*> q;
    //     map<TreeNode*, bool> visited;
    //     q.push(target);
    //     visited[target]=true;
    //     int level=0;
    //     while(!q.empty()){
    //         int size = q.size();
    //         if(level==k) break;
    //             level ++;
    //         for(int i=0; i<size; i++){
    //             TreeNode* curr = q.front();
    //             q.pop();
    //             if(curr->left && !visited[curr->left]){
    //                 q.push(curr->left);
    //                 visited[curr->left]=true;
    //             }
    //             if(curr->right && !visited[curr->right]){
    //                 q.push(curr->right);
    //                 visited[curr->right] =true;
    //             }
    //             if(parent[curr]&& !visited[parent[curr]]){
    //                 q.push(parent[curr]);
    //                 visited[parent[curr]] = true;
    //             }
    //         }
    //     }
    //     vector<int> result;
    //     while(!q.empty()){
    //     for(int i=0; i<q.size(); i++){
    //         TreeNode* temp = q.front();
    //         q.pop();
    //         result.push_back(temp->val);
    //     }
    // }
    //     return result;
    // }


    int timeTakenToBurn(TreeNode* root, TreeNode* target, int k){
        map<TreeNode*, TreeNode*> parent;
        findParent(root, target, parent);
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] =true;
        int time =0;
        while(!q.empty()){
            int size = q.size();
            bool burned = false;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                    burned =true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                    burned = true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                    burned = true;
                }
            }
            if(burned) time++;
        }
        cout<<time<<endl;
        return time;
    }
};

// int main(){
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(1);

//     root->left->left = new TreeNode(6);
//     root->left->right = new TreeNode(2);

//     root->right->right = new TreeNode(8);

//     root->left->right->left = new TreeNode(7);
//     root->left->right->right = new TreeNode(4);

//     TreeNode* target = root->left; 
//     int k = 2;

//     Solution sol;
//     vector<int> ans = sol.kthDistance(root, target, k);
    
//     for (int x : ans) {
//         cout << x << " ";
//     }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);

    TreeNode* target = root->left->right; 

    Solution sol;
    sol.timeTakenToBurn(root, target, 2);
    return 0;
}