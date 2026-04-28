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
    vector<int> childrenSumProperty(TreeNode *root){
        if(root==NULL) return;
        //check condition
        int child =0;
        if(root->left) child +=root->left->val;
        if(root->right) child+=root->right->val;
        if(child>=root->val) root->val = child;
        else {
            if(root->left) root->left->val = root->val;
            else if(root->right) root->right->val = root->val;
        }
        childrenSumProperty(root->left);
        childrenSumProperty(root->right);
        // execution
        int tot = 0;
        if(root->left) tot +=root->val;
        if(root->right) tot+=root->val;
        if(root->left || root->right) root->val = tot;
    }
};