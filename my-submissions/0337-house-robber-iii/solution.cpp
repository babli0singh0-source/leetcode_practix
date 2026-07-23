/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    unordered_map<TreeNode*,int>mpp;
    int helper(TreeNode* curr){
        if(curr==nullptr)return 0;
        if(mpp.count(curr))return mpp[curr];
        int take=0,nottake=0;
        if(curr->left){
            take+=helper(curr->left->left)+helper(curr->left->right);
            nottake+=helper(curr->left);
        }
        if(curr->right){
            take+=helper(curr->right->right)+ helper(curr->right->left);
            nottake+= helper(curr->right);
        }
        take+=curr->val;
        return mpp[curr]=max(take,nottake);
    }
public:
    int rob(TreeNode* root) {
        return helper(root);
    }
};
