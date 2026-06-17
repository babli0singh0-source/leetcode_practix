/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        int mini=min(p->val,q->val);
        int maxi=max(p->val,q->val);
        while(curr!=nullptr){
            if(curr->val==mini||curr->val==maxi||curr->val>mini&&curr->val<maxi)return curr;
            else if(curr->val<mini&&curr->val<maxi)curr=curr->right;
            else if(curr->val>mini&&curr->val>maxi)curr=curr->left;
        }
        return nullptr;
    }
};
