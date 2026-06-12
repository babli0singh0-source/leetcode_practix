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
    int helper(TreeNode* root,bool &check){
        if(!check)return 0;
        if(root==nullptr)return 0;
        int lh=helper(root->left,check);
        int rh=helper(root->right,check);
        if(abs(lh-rh)>1)check=false;
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool check=true;
        int h=helper(root,check);
        return check;
    }
};
