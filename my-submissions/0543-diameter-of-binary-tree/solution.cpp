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
    int ans=0;
    int height(TreeNode* root){
        if(root==nullptr)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        ans=max(ans,(lh+rh));
        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h=height(root);
        return ans;
    }
};
