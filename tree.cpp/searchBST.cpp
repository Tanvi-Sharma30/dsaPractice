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
    // int ceilValue(TreeNode* root, int key){
    //     int ceil =-1;
    //     TreeNode* temp = root;
    //     while(temp!=NULL){
    //         if(temp->val == key) {
    //             ceil = temp->val;
    //             return ceil;
    //         }
    //         if(temp->val< key){
    //             temp = temp->right;
    //         } else {
    //             ceil = temp->val;
    //             temp = temp->left;
    //         }
    //     }
    //     return ceil;
    // }

    int floorValue(TreeNode* root, int key){
        int floor = -1;
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val==key) {
                floor = temp->val;
                return floor;
            }
            if(temp->val > key){
                temp= temp->left;
            } else{
                floor = temp->val;
                temp= temp->right;
            }
        }
        return floor;
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
    int ans = sol.floorValue(root, 9);
    cout<<ans;


    return 0;
}