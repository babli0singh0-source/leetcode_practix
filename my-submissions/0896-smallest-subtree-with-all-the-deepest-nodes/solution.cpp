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
public:
    pair<int,TreeNode*>helper(TreeNode* root){
        if(root==nullptr)return {0,nullptr};
        auto [ld,ln]=helper(root->left);
        auto [rd,rn]=helper(root->right);
        if(ld>rd)return {ld+1,ln};
        else if(ld<rd)return {rd+1,rn};
        else return {ld+1,root};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;   
    }
};
