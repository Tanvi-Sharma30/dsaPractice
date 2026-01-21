#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include <sstream>
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
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if (root==NULL) return NULL;
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     while(!q.empty()){
    //         TreeNode* temp = q.front();
    //         q.pop();
    //         if(temp==NULL) continue;
    //         if(temp->val == val) return temp;
    //         if(temp->val > val && temp->left!=NULL){
    //             q.push(temp->left);
    //         } else if(temp->val < val && temp->right){
    //             q.push(temp->right);
    //         }
            
    //     }
    //     return NULL;
    // }

    // TreeNode* searchBST(TreeNode* root, int val){
    //     if(root==NULL || root->val==val) return root;
    //     if(root->val > val) return searchBST(root->left, val);
    //     return searchBST(root->right, val);
    // }

    TreeNode* searchBST(TreeNode* root, int val){
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val==val) return temp;
            if(temp->val > val) temp= temp->left;
            else temp = temp->right;
        }
        return NULL;
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7); 

    Solution sol;
    TreeNode*ans =sol.searchBST(root, 2);
    if(ans != NULL)
    cout << ans->val << endl;
    else
    cout << "Not found" << endl;


    return 0;
}