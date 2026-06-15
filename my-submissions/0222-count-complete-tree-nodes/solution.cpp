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
    int findleftheight(TreeNode* root){
        if(root==nullptr)return 1;
        return 1+findleftheight(root->left);
    }
    int findrightheight(TreeNode* root){
        if(!root)return 0;
        return 1+findrightheight(root->right);
    }
    int nodecount(TreeNode* root){
        if(root==nullptr)return 0;
        int lh=findleftheight(root->left);
        int rh=findrightheight(root->right);
        if(lh==rh)return (1<<lh)-1;
        return 1+nodecount(root->left)+nodecount(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        return nodecount(root);
    }
};
