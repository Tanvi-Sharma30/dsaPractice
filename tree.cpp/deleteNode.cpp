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

class Solution{
    public:
        int kthSmallest(TreeNode* root, int k) {
            if(root==NULL) return 0;
            set<int> s;
            queue<TreeNode*> q;
            q.push(root);
            s.insert(root->val);
            while(true){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                    s.insert(temp->left->val);
                }
                if(root->right) {
                    q.push(root->right);
                    s.insert(root->left->val);
                }
            }
            int count = 1;
            for(auto it = s.begin(); it != s.end(); it++) {
                if(count == k) {
                return *it;
            }
            count++;
        }
        return 0;
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
    int ans = sol.kthSmallest(root,5);
    cout<<ans;


    return 0;
}