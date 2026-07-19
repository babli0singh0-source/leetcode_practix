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
    int count=0;
    int isdominant(TreeNode* root){
        if(root==nullptr)return 0;
        int leftb=isdominant(root->left);
        if(root->left!=nullptr){
            leftb=max(leftb,root->left->val);
        }
        
        int  rightb=isdominant(root->right);
        
        if(root->right!=nullptr){
            rightb=max(rightb,root->right->val);
        }
        if(root->val>=leftb&&root->val>=rightb){
            count++;
        }
        return max({leftb,rightb,root->val});
    }
public:
    int countDominantNodes(TreeNode* root) {
        isdominant(root);
        return count;
    }
};
