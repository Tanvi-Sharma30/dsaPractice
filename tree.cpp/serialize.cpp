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
    string serialize(TreeNode* root){
        if(root==NULL) return "";
        queue<TreeNode*> q;
        string s ="";
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = new TreeNode(root->val);
            q.pop();
            if(temp==NULL){
                s+="NULL";
                continue;
            }
            s +=to_string(temp->val)+"";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return s;
    }
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="NULL") {
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="NULL"){
                node->right =NULL;
            } else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right =rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};