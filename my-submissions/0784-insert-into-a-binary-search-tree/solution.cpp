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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(root==nullptr)return node;
        TreeNode* temp=root;
        TreeNode* prev=root;
        while(temp!=nullptr){
            prev=temp;
            if(temp->val>val)temp=temp->left;
            else temp=temp->right;
        }
        if(prev->val>val)prev->left=node;
        else prev->right=node;
        return root;
    }
};
