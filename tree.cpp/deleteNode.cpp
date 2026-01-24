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
     TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val>key){
                if(temp->left!=NULL && temp->left->val==key){
                    temp->left = helper(temp->left);
                } else temp = temp->left;
            } else {
                if(temp->right!=NULL && temp->right->val == key){
                    temp->right = helper(temp->right);
                } else temp = temp->right;
            }
        }
        return root;
    }

    TreeNode* helper(TreeNode* root){
        TreeNode* temp = root;
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastChild = findLast(root->left);
        lastChild->right = rightChild;

    return root;
    }

    TreeNode* findLast(TreeNode* root){
        if(root->right == NULL) return root;
        return findLast(root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    root->right = new TreeNode(15); 
    root->right->right = new TreeNode(13); 
    root->right->left = new TreeNode(17); 

    Solution sol;
    TreeNode* ans = sol.deleteNode(root,5);
    cout<<ans;


    return 0;
}