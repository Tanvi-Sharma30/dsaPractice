#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right){}
};

class Solution {
public:
    bool isValid(TreeNode* root, TreeNode* temp, vector<TreeNode*>&ans){
        if(root==NULL) return false;
        ans.push_back(root);
        if(root==temp) return true;
        if(isValid(root->left, temp, ans) || isValid(root->right, temp, ans)) return true;

        ans.pop_back();
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ansP;
        vector<TreeNode*> ansQ;
        isValid(root,p,ansP);
        isValid(root,q,ansP);
        int i=0;
        while(i<ansP.size() && i<ansQ.size() && ansP[i]==ansQ[i]){
            i+=1;
        }
        return ansP[i-1];
    }
};