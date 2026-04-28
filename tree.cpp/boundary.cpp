#include<iostream>
#include<vector>
#include<queue>
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
    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL) ;
    }
    void addLeft(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->val);
            if(curr->left) curr = curr->left;
            if(curr->right) curr= curr->right;
        }

    }
    void addLeaves(TreeNode* root, vector<int> &res){
        if(root==NULL) return;
        if (isLeaf(root)){
             res.push_back(root->val);
             return ;
        }  
        addLeaves(root->left, res);
        addLeaves(root->right, res);   
    }

    void addRight(TreeNode* root, vector<int> &res){
        vector<int > ans;
        TreeNode* temp = root->right;
        while(temp){
            if(!isLeaf(temp)) ans.push_back(temp->val);
            if(temp->right) temp = temp->right;
            if(temp->left) temp = temp->left;
        }
        for(int i=ans.size()-1; i>=0; i++){
            res.push_back(ans[i]);
        }
    }
    vector<int> printBoundary(TreeNode* root){
        vector<int> res;
        if(root==NULL) return res;
        if(! isLeaf(root)) res.push_back(root->val);
        addLeft(root, res);
        addLeaves(root, res);
        addRight(root, res);

        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.printBoundary(root);

    for(int i=0; i<result.size(); i++){
        cout<<result[i];
    }

    return 0;
}